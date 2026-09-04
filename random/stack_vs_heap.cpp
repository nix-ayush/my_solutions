#include <chrono>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

// This trick forces the compiler to treat a variable as "used",
// stopping it from deleting your code!
template <typename T> void force_use(T &&val) {
  // Inline assembly that convinces the compiler the data is being read/modified
  asm volatile("" : "+g"(val) : : "memory");
}

class Allocator {
public:
  static constexpr int SIZE = 10000000;

  void heap() {
    std::vector<int> the_heap(SIZE);
    the_heap[SIZE - 1] =
        666; // Use it so that the compiler doesn't optimized it!
  }

  void stack() {
    int the_stack[SIZE];
    the_stack[SIZE - 1] = 777;
    // the_stack[0] = 777;
    /** this will cause segmentation fault since it's > 8MB,
        i mean the the stack size

        then why does accessing "SIZE - 1" does not cause segfault?
        because *the stack grows downwards toward lower memory address*!
        which means "SIZE - 1" is essentially is at the very top of the array,
        right next to where the stack was valid and allocated!
        therefore we never touched the unmapped 40MB below!

        let's make it more simple, uhhh
        "In C/C++, arrays always lay out in memory in normal, ascending order:
        index 0 is at the lowest memory address, and index SIZE - 1
        is at the highest."

        High Memory Addresses (e.g. 0x7fffffff...)
        ▲
        │   [ Caller's Stack Frame (Already valid, mapped in RAM) ]
        │   ─────────────────────────────────────────────────────── <── Old RSP
        │   [ the_stack[SIZE - 1] ]  <-- YOU WROTE HERE (Safe!)
        │   [ the_stack[...]      ]
        │   [ ... 40 MB of array ...]
        │   [ ~8 MB stack limit   ]  <-- The OS Guard Page sits here
        │   [ the_stack[0]        ]  <-- Index 0 is down here in the void!
        │   ─────────────────────────────────────── <── New RSP (sub rsp, 40MB)
        ▼
        Low Memory Addresses

        unknown source explanation:
        Linux uses "demand paging." It doesn't give you 8 MB of physical RAM
        upfront; it maps 4 KB pages on the fly as your stack grows downward.

        When you executed:
        the_stack[SIZE - 1] = 777;

        Because SIZE - 1 is the highest address in the array, it sits right next
        to the old rsp-memory that was already mapped and valid from the
        caller function. The CPU wrote the number 777 into memory that
        already existed. No alarms went off.

        -Why the_stack[0] will kill it?
        Index 0 is at the very bottom (the new rsp). That address is 40 MB
        below where you started.

        Linux typically sets your stack limit to 8 MB (ulimit -s). Right
        below that 8 MB limit, the kernel places an intentionally unmapped
        page called a guard page.

        If you touch the_stack[0], the CPU attempts to write to an
        unmapped address past the 8 MB boundary. The Memory Management Unit
        (MMU) says "Access Denied," triggers a page fault that the kernel
        refuses to fulfill, and the kernel instantly kills your program
        with a Segmentation Fault (core dumped).

        It grows from high addresses down to low addresses because
        of a 50-year-old architectural trick: letting the Stack and the Heap
        share the same empty memory without wasting space.
    **/
  }

  void reservedHeap() {
    std::vector<int> the_heap;
    the_heap.reserve(SIZE);
  }

  void reservedHeapPushedBack() {
    std::vector<int> the_heap;
    the_heap.reserve(SIZE);

    for (int i = 0; i < SIZE; ++i) {
      the_heap.push_back(i);
    }
    the_heap[SIZE - 1] = 777;
  }
};

template <typename Func, typename... Args>
void profiling(std::string name, Func &&func, Args &&...args) {
  auto start = std::chrono::steady_clock::now();
  std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
  auto end = std::chrono::steady_clock::now();

  auto elapsed =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  std::cout << "Function " << name << " took: " << elapsed << " microseconds\n";
}

int main() {
  Allocator hey;

  profiling("Allocator::heap", &Allocator::heap, hey);
  profiling("Allocator::reservedHeap", &Allocator::reservedHeap, hey);
  profiling("Allocator::reservedHeapPushedBack",
            &Allocator::reservedHeapPushedBack, hey);
  profiling("Allocator::stack", &Allocator::stack, hey);

  return 0;
}

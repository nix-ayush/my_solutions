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

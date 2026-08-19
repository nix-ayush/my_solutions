// used by leetcode(tho i think this is not necessary...?)
#include <algorithm>
#include <string>
#include <vector>

class Solution {
private:
  std::string buzz_me(const int &num);

public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> fbuzz;
    fbuzz.reserve(n);

    for (int x = 1; x <= n; x++) {
      fbuzz.push_back(buzz_me(x));
    }

    return fbuzz;
  }
};

std::string Solution::buzz_me(const int &num) {
  std::string output{};

  if (num % 15 == 0) {
    output = "FizzBuzz";
  } else if (num % 3 == 0) {
    output = "Fizz";
  } else if (num % 5 == 0) {
    output = "Buzz";
  } else {
    output = std::to_string(num);
  }

  return output;
}

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[fizzBuzz]") {
  Solution solver;

  SECTION("Test Case 1") {
    std::vector<std::string> output = {"1", "2", "Fizz"};
    REQUIRE(solver.fizzBuzz(3) == output);
  }
  SECTION("Test Case 2") {
    std::vector<std::string> output = {"1", "2", "Fizz", "4", "Buzz"};
    REQUIRE(solver.fizzBuzz(5) == output);
  }
  SECTION("Test Case 3") {
    std::vector<std::string> output = {
        "1",    "2",    "Fizz", "4",    "Buzz", "Fizz", "7",       "8",
        "Fizz", "Buzz", "11",   "Fizz", "13",   "14",   "FizzBuzz"};
    REQUIRE(solver.fizzBuzz(15) == output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.fizzBuzz() == output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.fizzBuzz() == output);
  }
}
#endif

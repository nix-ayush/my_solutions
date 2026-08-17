/** Given a list of numbers and a number k, return whether any two numbers from
the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
**/

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool find_sum_pair(const std::vector<int> &list, int target) {
    // first make a hashmap;
    // take first number and store it then substract it from k and check if the
    // result number exists; if it exists exit with true else move to next
    // number and continue this process
    std::unordered_set<int> seen{};

    for (const auto &num : list) {
      int complement{target - num};

      if (seen.contains(complement)) {
        return true;
      } else {
        seen.insert(num);
      }
    }
    return false;
  }
};

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[find_sum_pair]") {
  Solution solver;

  SECTION("Test Case 1") {
    std::vector<int> input = {10, 15, 3, 7};
    int input2 = 17;
    bool expected = true;
    REQUIRE(solver.find_sum_pair(input, input2) == expected);
  }
  SECTION("Test Case 2") {
    // REQUIRE(solver.methodName() == expected_output);
  }
  SECTION("Test Case 3") {
    // REQUIRE(solver.methodName() == expected_output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.methodName() == expected_output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.methodName() == expected_output);
  }
}
#endif

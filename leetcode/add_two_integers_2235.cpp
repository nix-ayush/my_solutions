// used by leetcode(tho i think this is not necessary...?)
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int sum(int num1, int num2) { return num1 + num2; }
};

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[sum]") {
  Solution solver;

  SECTION("Test Case 1") { REQUIRE(solver.sum(12, 5) == 17); }
  SECTION("Test Case 2") { REQUIRE(solver.sum(-10, 4) == -6); }
  SECTION("Test Case 3") {
    // REQUIRE(solver.sum() == expected_output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.sum() == expected_output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.sum() == expected_output);
  }
}
#endif

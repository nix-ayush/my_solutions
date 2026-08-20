// used by leetcode(tho i think this is not necessary...?)
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.8 + 32.00};
  }
};

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[convertTemperature]") {
  Solution solver;

  SECTION("Test Case 1") {
    std::vector<double> output = {309.65, 97.7};
    REQUIRE(solver.convertTemperature(36.50) == output);
  }
  SECTION("Test Case 2") {
    std::vector<double> output = {395.26, 251.798};
    REQUIRE(solver.convertTemperature(122.11) == output);
  }
  SECTION("Test Case 3") {
    // REQUIRE(solver.convertTemperature() == output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.convertTemperature() == output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.convertTemperature() == output);
  }
}
#endif

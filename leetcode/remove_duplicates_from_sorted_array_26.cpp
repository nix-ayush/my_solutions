#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &vec) {
    if (vec.empty()) {
      return 0;
    }
    int writer = 1;

    // start reader at 1 since first value is always unique
    for (int reader = 1; reader < vec.size(); reader++) {
      // writer-1 here: since we are actually comparing current number with the
      // LAST updated number
      if (vec[reader] != vec[writer - 1]) {
        vec[writer] = vec[reader];
        writer++;
      }
    }

    vec.resize(writer);
    return writer;
  }
};

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[removeDuplicates]") {
  Solution solver;

  SECTION("Test Case 1") {
    // std::pair<int, std::vector<int>> output = {2, {1, 2}};
    // actually nvm, the og function from leetcode returns integer and modified
    // og vector by using reference to it
    std::vector<int> input = {1, 1, 2};
    std::vector<int> expected_output = {1, 2};
    int expected_count = 2;
    REQUIRE(solver.removeDuplicates(input) == expected_count);
    REQUIRE(input == expected_output);
  }
  SECTION("Test Case 2") {
    std::vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> expected_output = {0, 1, 2, 3, 4};
    int expected_count = 5;
    REQUIRE(solver.removeDuplicates(input) == expected_count);
    REQUIRE(input == expected_output);
  }
  SECTION("Test Case 3") {
    // REQUIRE(solver.removeDuplicates() == expected_output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.removeDuplicates() == expected_output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.removeDuplicates() == expected_output);
  }
}
#endif

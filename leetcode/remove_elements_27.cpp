#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &vec, int val) {
    if (vec.empty()) {
      return 0;
    }

    // for this one start with check from 1st element
    // used a writer variable to keep track of what to change
    int writer = 0;
    for (int reader = 0; reader < vec.size(); reader++) {
      if (vec[reader] != val) {
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

TEST_CASE("LeetCode Tests", "[removeElement]") {
  Solution solver;

  SECTION("Test Case 1") {
    std::vector<int> input1 = {3, 2, 2, 3};
    int input2 = 3;
    int expected_count = 2;
    std::vector<int> expected_output = {2, 2};
    REQUIRE(solver.removeElement(input1, input2) == expected_count);
    REQUIRE(input1 == expected_output);
  }
  SECTION("Test Case 2") {
    std::vector<int> input1 = {0, 1, 2, 2, 3, 0, 4, 2};
    int input2 = 2;
    int expected_count = 5;
    std::vector<int> expected_output = {0, 1, 3, 0, 4};
    REQUIRE(solver.removeElement(input1, input2) == expected_count);
    REQUIRE(input1 == expected_output);
  }
  SECTION("Test Case 3") {
    // REQUIRE(solver.removeElement() == expected_output);
  }
  SECTION("Test Case 4") {
    // REQUIRE(solver.removeElement() == expected_output);
  }
  SECTION("Test Case 5") {
    // REQUIRE(solver.removeElement() == expected_output);
  }
}
#endif

#include <vector>
using namespace std;

// TODO: Make it faster!
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int size = nums.size();
    int current_num{};
    int other_num{};

    for (int x = 0; x < size; x++) {
      current_num = nums[x];

      for (int y = x + 1; y < size; y++) {
        other_num = nums[y];

        if ((current_num + other_num) == target) {
          return {x, y};
        }
      }
    }

    return {0, 0};
  }
};

#ifdef ONLINE_JUDGE
#include "catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("LeetCode Tests", "[twoSum]") {
  Solution solver;

  SECTION("Example #1") {
    std::vector<int> input = {2, 3, 4};
    int target = 7;
    REQUIRE(solver.twoSum(input, target) == std::vector<int>{1, 2});
  }

  SECTION("Example #2") {
    std::vector<int> input = {6, 8, 19};
    int target = 25;
    REQUIRE(solver.twoSum(input, target) == std::vector<int>{0, 2});
  }
}
#endif

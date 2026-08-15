#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int len = digits.size();

    for (int counter = len - 1; counter >= 0; counter--) {
      int current_digit = digits[counter];

      if (current_digit == 9) {
        digits[counter] = 0;
      } else {
        digits[counter] += 1;
        return digits;
      }
    }

    /** this will only continue to execute if all digits are 9 which will make
        the complete std::vector 0 and not return the std::vector during the
        loop; we did this to add 1 at start of std::vector: ex: 9,9,9 becomes
        1,0,0,0 FIRST
        if(digits[0] == 0){
            digits.insert(digits.begin(), 1);
            }
    **/

    // REWRITE: just make first digit 1 and append 0 at end
    digits[0] = 1;
    digits.push_back(0);

    return digits;
  }
};

#ifdef ONLINE_JUDGE
#include "catch_amalgamated.hpp"
#include <iostream>
TEST_CASE("LeetCode Tests", "[plusOne]") {
  Solution solver;

  SECTION("Standard addition without carries") {
    std::vector<int> input = {1, 2, 3};
    REQUIRE(solver.plusOne(input) == std::vector<int>{1, 2, 4});
  }

  SECTION("Edge case ending with nine") {
    std::vector<int> input = {4, 3, 2, 9};
    REQUIRE(solver.plusOne(input) == std::vector<int>{4, 3, 3, 0});
  }

  SECTION("All nines expansion logic") {
    std::vector<int> input = {9, 9, 9};
    REQUIRE(solver.plusOne(input) == std::vector<int>{1, 0, 0, 0});
  }
}
#endif

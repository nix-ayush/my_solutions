class Solution {
  // private:
  //     long reverseNumber(int num) {
  //         long reversed {};
  //         while (num > 0) {
  //             // int last_digit {num % 10}; reversed += (reversed*10) +
  //             last_digit; reversed *=10; reversed += num%10; num /= 10;
  //         }

  // return reversed;
  // }
public:
  bool isPalindrome(int x) {
    // int number{x};
    // if (number < 0) {
    // return false;
    // }

    // long reversed_num = reverseNumber(number);

    // return (reversed_num == number);

    if (x < 0 || (x % 10 == 0 && x != 0)) {
      // the second condition is to check for since other numbers ending with 0
      // can't be palindrome since we need first digit as 0 too, which can
      // happen in only "0", we are taking input as int not strings so "01234"
      // is taken as "1234" by the compiler or computer whatever.
      return false;
    }

    int first_half{x};
    int last_half{};

    while (first_half > last_half) {
      int last_digit{first_half % 10};
      last_half = (last_half * 10) + last_digit;
      first_half /= 10;
    }

    return (first_half == last_half || first_half == last_half / 10);
  }
};

/** in a palindrome example 12344321
 * if we break down it into two parts, 1234 and 4321
 * we ca find that right side is flipped of left side and vice-versa.
 * therefore we can instead of reversing whole number, just reverse half and
 * check. similarly for odd number we can just nuke the middle number so we have
 * two final conditions to check first_half == second_half(even) first_half ==
 * (second_half/10) (odd- we will run loop till 1st half is greater than second
 * half so this will chop till equal for even and the middle digit as well in
 * case for odd)
 **/

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[methodName]") {
  Solution solver;

  // TODO: Write Test Cases!
  SECTION("Test Case 1") {
    // REQUIRE(solver.methodName() == expected_output);
  }
}
#endif

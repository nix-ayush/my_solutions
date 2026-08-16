#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> brackets;

    for (const char &ch : s) {
      if (ch == '(')
        brackets.push(')');
      else if (ch == '{')
        brackets.push('}');
      else if (ch == '[')
        brackets.push(']');
      else {
        // to check if the last one does not match the current bracket, we only
        // check after ensuring the stakc isn't empty(ex:'}()') and crash the
        // program by using .top()
        if (brackets.empty() || brackets.top() != ch)
          return false;
        brackets.pop();
      }
    }
    return brackets.empty();
  }
};

#ifdef ONLINE_JUDGE
#include <iostream>

// for test cases
#include "catch_amalgamated.hpp"

TEST_CASE("LeetCode Tests", "[isValid]") {
  Solution solver;

  SECTION("Case 1") { REQUIRE(solver.isValid("()") == true); }
  SECTION("Case 2") { REQUIRE(solver.isValid("()[]{}") == true); }
  SECTION("Case 3") { REQUIRE(solver.isValid("(]") == false); }
  SECTION("Case 4") { REQUIRE(solver.isValid("([])") == true); }
  SECTION("Case 5") { REQUIRE(solver.isValid("([)]") == false); }
}
#endif

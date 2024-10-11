#include <LinkedListStack.hpp>
#include <array>
#include <catch2/catch_amalgamated.hpp>
#include <postfixCalc.hpp>
#include <string>
#include <unordered_map>

namespace {
namespace proj0 = shindler::ics46::project0;

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails,
// your score for the portion will be zero, regardless of other considerations.

// And some tests for the linked list based stack and the associated calculator.
// VERY IMPORTANT:  if your LinkedListStack is not templated, or if
//      it is not linked-list based, your score for this project
//      will be zero.  Be sure your LinkedListStack compiles and runs
//      with non-numeric data types.  A char is a numeric type.
//

TEST_CASE("Stack:InsertOneElement:ExpectTopEqualElement", "[Required]") {
    const int INSERT_VALUE = 5;

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUE);

    REQUIRE(stack.top() == INSERT_VALUE);
}

TEST_CASE("Stack:InsertTwoElements:ExpectTopEqualSecond", "[Required][Stack]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);

    REQUIRE(stack.top() == INSERT_VALUES[1]);
}

TEST_CASE("Stack:InsertTwoElementsWithPop:ExpectTopEqualFirst",
          "[Required][Stack]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);
    stack.pop();

    REQUIRE(stack.top() == INSERT_VALUES[0]);
}

TEST_CASE("Stack:EmptyCallToTop:ExpectException", "[Required][Stack]") {
    proj0::LinkedListStack<int> stack;

    REQUIRE_THROWS_AS(stack.top(), proj0::StackEmptyException);
}

TEST_CASE("Stack:UntilEmptyTest", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);

    REQUIRE(stack.top() == INSERT_VALUES[1]);
    stack.pop();
    stack.pop();
    REQUIRE_THROWS_AS(stack.top(), proj0::StackEmptyException);
}

TEST_CASE("Stack:POPTHENPUSH", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);

    REQUIRE(stack.top() == INSERT_VALUES[1]);
    stack.pop();
    REQUIRE(stack.top() == INSERT_VALUES[0]);
    stack.push(4);
    REQUIRE(stack.top() == 4);
}

TEST_CASE("Stack:CopyConstructor", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);

    proj0::LinkedListStack<int> copystack{stack};
    REQUIRE(copystack.top() == 3);

}

TEST_CASE("Stack:CopyConstructorAndRemove", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};

    proj0::LinkedListStack<int> stack;

    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);

    proj0::LinkedListStack<int> copystack{stack};
    REQUIRE(copystack.top() == 3);
    REQUIRE(copystack.size() == 2);

    copystack.pop();
    REQUIRE(copystack.size() == 1);
    REQUIRE(stack.size() == 2);
    REQUIRE(copystack.top() == 5);

    copystack.pop();
    REQUIRE(copystack.size() == 0);
    REQUIRE(stack.top() == 3);
    REQUIRE_THROWS_AS(copystack.top(), proj0::StackEmptyException);

}

TEST_CASE("Stack:CopyNothing", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};
    proj0::LinkedListStack<int> stack;
    proj0::LinkedListStack<int> copystack{stack};
    REQUIRE_THROWS_AS(copystack.top(), proj0::StackEmptyException);
    copystack.push(INSERT_VALUES[0]);
    REQUIRE(copystack.top() == 5);
    REQUIRE_THROWS_AS(stack.top(), proj0::StackEmptyException);

}

TEST_CASE("Stack:AssignmentCOPYNothing", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};
    proj0::LinkedListStack<int> stack;
    proj0::LinkedListStack<int> copystack = stack;
    REQUIRE_THROWS_AS(copystack.top(), proj0::StackEmptyException);
    copystack.push(INSERT_VALUES[0]);
    REQUIRE(copystack.top() == 5);

}

TEST_CASE("Stack:AssignmentCOPYAndDelete", "[PERSONAL]") {
    const std::array<int, 2> INSERT_VALUES{5, 3};
    proj0::LinkedListStack<int> stack;
    stack.push(INSERT_VALUES[0]);
    stack.push(INSERT_VALUES[1]);
    proj0::LinkedListStack<int> copystack = stack;
    REQUIRE(copystack.top() == 3);
    REQUIRE(copystack.size() == 2);
    stack.pop();
    REQUIRE(copystack.top() == 3);
    REQUIRE(copystack.size() == 2);
    stack.pop();
    REQUIRE(copystack.top() == 3);
    REQUIRE(copystack.size() == 2);
    copystack.push(5);
    REQUIRE_THROWS_AS(stack.top(), proj0::StackEmptyException);
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.empty());
    REQUIRE(copystack.size() == 3);
    REQUIRE_FALSE(copystack.empty());

}
// YOU SHOULD ADD ADDITIONAL TEST_CASE "ERE" H"[CASES]"!!

TEST_CASE("Calc:53*:Expect15", "[Required][Calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "*"};
    
    REQUIRE(proj0::postfixCalculator(EXPRESSION) == 15);
}

TEST_CASE("Calc:532-*:Expect5", "[Required][Calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-", "*"};

    REQUIRE(proj0::postfixCalculator(EXPRESSION) == 5);
}

TEST_CASE("Calc:432-:ExpectException", "[Required][Calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-"};

    REQUIRE_THROWS_AS(proj0::postfixCalculator(EXPRESSION),
                      proj0::CannotEvaluateException);
}

// You can fail this test and still get partial credit from others that pass.
// Of course, I would recommend you get this one to pass, too...
// Note that the group name is "PartialCredit" and not "Required."
TEST_CASE("Calc:43*20*:Expect300", "[PartialCredit][Calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "*", "20", "*"};

    REQUIRE(proj0::postfixCalculator(EXPRESSION) == 300);
}

TEST_CASE("Calc:432-:ExpectException2", "[Required][Calc]") {
    const std::vector<std::string> EXPRESSION = {"-", "5", "2"};

    REQUIRE_THROWS_AS(proj0::postfixCalculator(EXPRESSION),
                      proj0::CannotEvaluateException);
}

TEST_CASE("Calc:432-:IntegerDivision", "[Required][Calc]") {
    const std::vector<std::string> EXPRESSION = {"2" , "3", "/"};

    REQUIRE(proj0::postfixCalculator(EXPRESSION) == 1);
}

}  // namespace

#include "postfixCalc.hpp"
#include <iostream>
#include "LinkedListStack.hpp"

namespace shindler::ics46::project0 {

unsigned postfixCalculator(const std::vector<std::string>& entries) {
    // TODO: Implement Function
    LinkedListStack<std::string> stack; //Intialize a new stack that we will use specifically for strings
    unsigned index = 0;
    unsigned length = entries.size(); // Two variables to keep track of the length and the index. This is to make sure that the index does not seg fault
    while(index < length)
    {
        if (entries[index] == "*")
        {
            if (stack.size() < 2)
            {
                throw CannotEvaluateException("Not enough operator functions/too much numbers");
            }
            std::string first = stack.top();
            stack.pop();
            std::string second = stack.top();
            stack.pop();
            stack.push(std::to_string(std::stoi(first) * std::stoi(second))); // Makes string into digits to use operator and change back to string and push to stack
        }
        else if (entries[index] == "+")
        {
            if (stack.size() < 2)
            {
                throw CannotEvaluateException("Not enough operator functions/too much numbers");
            }
            std::string first = stack.top();
            stack.pop();
            std::string second = stack.top();
            stack.pop();
            stack.push(std::to_string(std::stoi(first) + std::stoi(second)));
        }
        else if (entries[index] == "/")
        {
            if (stack.size() < 2)
            {
                throw CannotEvaluateException("Not enough operator functions/too much numbers");
            }
            std::string first = stack.top();
            stack.pop();
            std::string second = stack.top();
            stack.pop();
            stack.push(std::to_string(std::stoi(first) / std::stoi(second)));
        }
        else if (entries[index] == "-")
        {
            if (stack.size() < 2)
            {
                throw CannotEvaluateException("Not enough operator functions/too much numbers");
            }
            std::string first = stack.top();
            stack.pop();
            std::string second = stack.top();
            stack.pop();
            if ((std::stoi(first) - std::stoi(second)) < 0)
            {
                stack.push(std::to_string(-(std::stoi(first) - std::stoi(second))));
            }
            else
            {
                stack.push(std::to_string(std::stoi(first) - std::stoi(second)));
            }
        }
        else
        {
            stack.push(entries[index]);
        }
        index++;
    }
    if (stack.size() != 1)
    {
         throw CannotEvaluateException("Not enough operator functions/too much numbers");
    }
    return std::stoi(stack.top());  // stub, not the correct answer
}

}  // namespace shindler::ics46::project0

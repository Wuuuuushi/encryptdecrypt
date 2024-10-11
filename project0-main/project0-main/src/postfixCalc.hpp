#ifndef __PROJ_0_POSTFIX_CALCULATOR
#define __PROJ_0_POSTFIX_CALCULATOR

#include <stdexcept>
#include <string>
#include <vector>

namespace shindler::ics46::project0 {

// This exception should be thrown whenever the postfix equation
// cannot be evaluated.
class CannotEvaluateException : public std::runtime_error {
   public:
    explicit CannotEvaluateException(const std::string& err)
        : std::runtime_error(err) {}
};

// For project 0, you should not need to do anything with this file.
// If you choose to create a helper function AND you want to add
// separate Google Tests for it, you should declare it in this header.
// You are not required to do that for the assignment.

[[nodiscard]] unsigned postfixCalculator(
    const std::vector<std::string>& entries);
}  // namespace shindler::ics46::project0
#endif

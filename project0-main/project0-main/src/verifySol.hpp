#ifndef __PROJ_0_VERIFIER
#define __PROJ_0_VERIFIER

#include <string>
#include <unordered_map>

namespace shindler::ics46::project0 {

// For project 0, you should not need to do anything with this file.
// If you choose to create a helper function AND you want to add
// separate Google Tests for it, you should declare it in this header.
// You are not required to do that for the assignment.

[[nodiscard]] bool verifySolution(
    const std::string& addend1, const std::string& addend2,
    const std::string& result,
    const std::unordered_map<char, unsigned>& mapping);
}  // namespace shindler::ics46::project0

#endif

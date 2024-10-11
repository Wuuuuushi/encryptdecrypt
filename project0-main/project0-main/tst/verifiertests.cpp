#include <catch2/catch_amalgamated.hpp>
#include <string>
#include <unordered_map>
#include <verifySol.hpp>

namespace {
namespace proj0 = shindler::ics46::project0;

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails,
// your score for the portion will be zero, regardless of other considerations.

TEST_CASE("Verifier:POT-PAN-BIB[A7B5I0N4O3P2T1]:ExpectTrue",
          "[Required][Verifier]") {
    const std::string ADDEND1 = "POT";
    const std::string ADDEND2 = "PAN";
    const std::string SUM = "BIB";

    const std::unordered_map<char, unsigned> SOLUTION = {
        {'A', 7}, {'B', 5}, {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}};

    REQUIRE(proj0::verifySolution(ADDEND1, ADDEND2, SUM, SOLUTION));
}

TEST_CASE("Verifier:CAT-DOG-PIG[A5C2D1G6I9O4P3T0]:ExpectTrue",
          "[Required][Verifier]") {
    const std::string ADDEND1 = "CAT";
    const std::string ADDEND2 = "DOG";
    const std::string SUM = "PIG";

    const std::unordered_map<char, unsigned> SOLUTION = {
        {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6},
        {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0}};

    REQUIRE(proj0::verifySolution(ADDEND1, ADDEND2, SUM, SOLUTION));
}

TEST_CASE("Verifier:LARRY-CAREER-LEGEND[L5A2R1Y6C9E4G3N0D7]:ExpectFalse",
          "[Required][Verifier]") {
    const std::string ADDEND1 = "LARRY";
    const std::string ADDEND2 = "CAREER";
    const std::string SUM = "LEGEND";

    const std::unordered_map<char, unsigned> SOLUTION = {
        {'L', 5}, {'A', 2}, {'R', 1}, {'Y', 6}, {'C', 9},
        {'E', 4}, {'G', 3}, {'N', 0}, {'D', 7}};

    REQUIRE_FALSE(proj0::verifySolution(ADDEND1, ADDEND2, SUM, SOLUTION));
}

TEST_CASE("Verifier:WhenSUMLongerThan1", "[PERSONAL]")
{
    const std::string addend1 = "A";
    const std::string addend2 = "BCD";
    const std::string result = "EFG";
    const std::unordered_map<char, unsigned> map ={
        {'A',1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 2}, {'F', 3}, {'G', 5}};
    REQUIRE(proj0::verifySolution(addend1, addend2, result, map));
}

TEST_CASE("VERIFIER:WHENZEROINFRONT", "[PERSONAL]")
{
    const std::string addend1 = "A";
    const std::string addend2 = "BCD";
    const std::string result = "EFG";
    const std::unordered_map<char, unsigned> map ={
        {'A',1}, {'B', 0}, {'C', 3}, {'D', 4}, {'E', 0}, {'F', 3}, {'G', 5}};
    REQUIRE(proj0::verifySolution(addend1, addend2, result, map));
}

TEST_CASE("VERIFIER:WHENALLLZERO", "[PERSONAL]")
{
    const std::string addend1 = "A";
    const std::string addend2 = "BBB";
    const std::string result = "BEF";
    const std::unordered_map<char, unsigned> map ={
        {'A',1}, {'B', 0}, {'C', 3}, {'D', 4}, {'E', 0}, {'F', 3}, {'G', 5}};
    REQUIRE_FALSE(proj0::verifySolution(addend1, addend2, result, map));
}

// YOU SHOULD ADD ADDITIONAL TEST_CASE "ERE" H"[CASES]"!!
}  // namespace

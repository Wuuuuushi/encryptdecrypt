#include "verifySol.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

namespace shindler::ics46::project0 {

bool verifySolution(const std::string& addend1, const std::string& addend2,
                    const std::string& result,
                    const std::unordered_map<char, unsigned>& mapping) {
    std::string str1{""};
    std::string str2{""};
    std::string strR{""};
    for (unsigned i = 0; i < addend1.length(); i++)
    {
        str1 += std::to_string(mapping.at(addend1[i])); //Digits are converted into string and combined with corresponding string varaible
    }
    for (unsigned i = 0; i< addend2.length(); i++)
    {
        str2 += std::to_string(mapping.at(addend2[i]));
    }
    for (unsigned i = 0; i < result.length(); i++)
    {
        strR += std::to_string(mapping.at(result[i]));
    }
    if (std::stoi(str1) + std::stoi(str2) != std::stoi(strR))
    {  
        return false; //If added values are not equal to the result value return false
    }
    return true;  // FYI, this stub is not a correct solution.
}

}  // namespace shindler::ics46::project0

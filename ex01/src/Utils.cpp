#include <Utils.hpp>

std::string Utils::trim(std::string input)
{
    const char *start;
    const char *end;
    std::string result;
    std::string next;

    if (input.size() == 0) {
        return "";
    }
    start = input.c_str();
    while (std::isspace(*start)) {
        start++;
    }
    end = start;
    while (*end && !std::isspace(*end)) {
        end++;
    }
    result = input.substr(start - input.c_str(), end - start);
    next = Utils::trim(end);
    if (next.size() > 0) {
        result += " " + next;
    }
    return result;
}
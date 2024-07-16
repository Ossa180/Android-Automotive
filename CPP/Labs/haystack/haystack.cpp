#include <string>
#include <string_view>

std::string func(std::string haystack, std::string_view needle, std::string_view replacement)
{
    size_t pos = 0;
    while ((pos = haystack.find(needle, pos)) != std::string::npos)
    {
        haystack.replace(pos, needle.length(), replacement);
        pos += replacement.length();
    }
    return haystack;
}

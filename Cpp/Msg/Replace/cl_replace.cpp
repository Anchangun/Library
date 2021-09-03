#include "cl_replace.h"

std::string cl_replace::fn_replace_all(const std::string& str, const std::string& target_str, const std::string& convert_str)
{
    std::string result_str = str;
    std::string::size_type pos = 0;
    std::string::size_type offset = 0;
    while ((pos = result_str.find(target_str, offset)) != std::string::npos) {
        result_str.replace(result_str.begin() + pos, result_str.begin() + pos + target_str.size(), convert_str);
        offset = pos + convert_str.size();
    }
    return result_str;
}

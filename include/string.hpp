#pragma once

#include <compare>
#include <string>

namespace yacw
{

class string : public std::basic_string<int>
{
public:
    explicit string(const char* str);
    explicit string(const std::string& str);

    std::string to_cppstring() const;

    string operator|(int x) const;
    string& operator|=(int x);
    string& operator=(const char* str);
    string& operator=(const std::string& str);

    std::strong_ordering operator<=>(const std::string& str) const;
    bool operator==(const std::string& str) const;
    bool operator!=(const std::string& str) const;
    bool operator<(const std::string& str) const;
    bool operator<=(const std::string& str) const;
    bool operator>(const std::string& str) const;
    bool operator>=(const std::string& str) const;

    friend std::strong_ordering operator<=>(const std::string& lhs, const string& rhs);
    friend bool operator==(const std::string& lhs, const string& rhs);
    friend bool operator!=(const std::string& lhs, const string& rhs);
    friend bool operator<(const std::string& lhs, const string& rhs);
    friend bool operator<=(const std::string& lhs, const string& rhs);
    friend bool operator>(const std::string& lhs, const string& rhs);
    friend bool operator>=(const std::string& lhs, const string& rhs);   

    std::strong_ordering operator<=>(const string& str) const;

    operator std::string() const;
};

namespace string_literals
{

string operator""_ys(const char* str, std::size_t len);

} // namespace string_literals

} // namespace yacw

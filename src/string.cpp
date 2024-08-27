#include <compare>
#include <cstring>
#include <string.hpp>

namespace yacw
{

// ------------------------------------------
// Operators
// ------------------------------------------
string::string(const char* str)
{
    *this = str;
}

string::string(const std::string& str)
{
    *this = str;
}

// ------------------------------------------
// Functions
// ------------------------------------------

std::string string::to_cppstring() const
{
    std::string str;
    str.resize(this->length());

    for (std::size_t i = 0; i < this->length(); ++i)
    {
        str[i] = static_cast<std::string::value_type>(this->at(i));
    }

    return str;
}

// ------------------------------------------
// Operators
// ------------------------------------------
string string::operator|(int x) const
{
    string copy = *this;
    copy |= x;
    return copy;
}

string& string::operator|=(int x)
{
    for (auto& it : *this)
    {
        it |= x;
    }
    return *this;
}

string& string::operator=(const char* str)
{
    *this = std::string(str);
    return *this;
}

string& string::operator=(const std::string& str)
{
    this->clear();
    this->resize(str.length());

    for (size_t i = 0; i < str.length(); ++i)
    {
        this->at(i) = str[i];
    }
    return *this;
}

std::strong_ordering string::operator<=>(const std::string& str) const
{
    return this->to_cppstring() <=> str;
}

bool string::operator==(const std::string& str) const
{
    return std::is_eq(*this <=> str);
}

bool string::operator!=(const std::string& str) const
{
    return std::is_neq(*this <=> str);
}

bool string::operator<(const std::string& str) const
{
    return std::is_lt(*this <=> str);
}

bool string::operator<=(const std::string& str) const
{
    return std::is_lteq(*this <=> str);
}

bool string::operator>(const std::string& str) const
{
    return std::is_gt(*this <=> str);
}

bool string::operator>=(const std::string& str) const
{
    return std::is_gteq(*this <=> str);
}

std::strong_ordering operator<=>(const std::string& lhs, const string& rhs)
{
    return lhs <=> rhs.to_cppstring();
}

bool operator==(const std::string& lhs, const string& rhs)
{
    return std::is_eq(lhs <=> rhs.to_cppstring());
}

bool operator!=(const std::string& lhs, const string& rhs)
{
    return std::is_neq(lhs <=> rhs.to_cppstring());
}

bool operator<(const std::string& lhs, const string& rhs)
{
    return std::is_lt(lhs <=> rhs.to_cppstring());
}

bool operator<=(const std::string& lhs, const string& rhs)
{
    return std::is_lteq(lhs <=> rhs.to_cppstring());
}

bool operator>(const std::string& lhs, const string& rhs)
{
    return std::is_gt(lhs <=> rhs.to_cppstring());
}

bool operator>=(const std::string& lhs, const string& rhs)
{
    return std::is_gteq(lhs <=> rhs.to_cppstring());
}

std::strong_ordering string::operator<=>(const string& str) const
{
    return this->to_cppstring() <=> str.to_cppstring();
}

string::operator std::string() const
{
    return this->to_cppstring();
}

string string_literals::operator""_ys(const char* str, std::size_t len)
{
    return string(str);
}

} // namespace yacw

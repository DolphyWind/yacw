#pragma once

#include <compare>
#include <string>

namespace yacw
{

/**
 * @brief String of integers instead of chars, since ncurses uses ints in character-related functions.
 */
class string : public std::basic_string<int>
{
public:
    /**
     * @brief Construct a yacw::string from a const char*
     *
     * @param str const char* to construct yacw::string from
     */
    explicit string(const char* str);

    /**
     * @brief Construct a yacw::string from a std::string 
     *
     * @param str std::string object to construct yacw::string from
     */
    explicit string(const std::string& str);

    /**
     * @brief Converts yacw::string to a std::string by casting each yacw::string character to char
     *
     */
    std::string to_cppstring() const;

    /**
     * @brief Applies bitwise OR operation to each character
     *
     * @param x Number to bitwise OR with
     * @return The result of bitwise OR operation
     */
    string operator|(int x) const;
    /**
     * @brief Applies bitwise OR operation to each character
     *
     * @param x Number to bitwise OR with
     */
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

    /**
     * @brief Convert yacw::string to std::string by casting each yacw::string character to char
     *
     */
    operator std::string() const;
};

namespace string_literals
{

string operator""_ys(const char* str, std::size_t len);

} // namespace string_literals

} // namespace yacw

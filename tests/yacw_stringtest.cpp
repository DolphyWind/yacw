#include <cassert>
#include <curses.hpp>
#include <yacw.hpp>
using namespace yacw::string_literals;

int main()
{
    yacw::string s = "Hello"_ys | A_BOLD;
    
    assert(s == std::string("Hello"));
    assert(s == "Hello");
    assert(s != "World");
    assert(s[0] == ('H' | A_BOLD));
    assert(s > "Hell"_ys);
    assert(s < "World");
    assert(s <= s && s >= s);
    s.push_back('A');
    assert(s == "HelloA");
    s.pop_back();
    assert(s.to_cppstring() == std::string("Hello"));

    return 0;
}

#include <cassert>
#include <curses.hpp>
#include <yacw.hpp>

int main()
{
    using namespace yacw::string_literals;
    using namespace std::string_literals;
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
    assert(s.to_cppstring() == "Hello"s);
    assert("Hello" == (std::string)"Hello"_ys);
    assert("Hello"s < "Helloo"_ys);
    assert("Hello"s <= "Helloo"_ys);
    assert("Hello"s == "Hello"_ys);
    assert("Helloo"s >= "Helloo"_ys);
    assert("Helloo"s > "Hello"_ys);
    assert("Helloo"_ys > "Hello"s);
    assert("Helloo"_ys >= "Helloo"s);
    assert("Hello"_ys <= "Hello"s);
    assert("a"s != "b"_ys);
    assert(std::is_eq("a"s <=> "a"_ys));

    return 0;
}

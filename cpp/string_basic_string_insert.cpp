/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_insert.exe ./cpp/string_basic_string_insert.cpp && (cd ../_build/cpp/;./string_basic_string_insert.exe)
https://en.cppreference.com/w/cpp/string/basic_string/insert
*/
#include <cassert>
#include <iterator>
#include <string>
using namespace std::string_literals;
int main()
{
    std::string s = "xmplr";
    // insert(size_type index, size_type count, char ch)
    s.insert(0, 1, 'E');
    assert("Exmplr" == s);
    // insert(size_type index, const char* s)
    s.insert(2, "e");
    assert("Exemplr" == s);
    // insert(size_type index, string const& str)
    s.insert(6, "a"s);
    assert("Exemplar" == s);
    // insert(size_type index, string const& str,
    //     size_type index_str, size_type count)
    s.insert(8, " is an example string."s, 0, 14);
    assert("Exemplar is an example" == s);
    // insert(const_iterator pos, char ch)
    s.insert(s.cbegin() + s.find_first_of('n') + 1, ':');
    assert("Exemplar is an: example" == s);
    // insert(const_iterator pos, size_type count, char ch)
    s.insert(s.cbegin() + s.find_first_of(':') + 1, 2, '=');
    assert("Exemplar is an:== example" == s);
    // insert(const_iterator pos, InputIt first, InputIt last)
    {
        std::string seq = " string";
        s.insert(s.begin() + s.find_last_of('e') + 1,
            std::begin(seq), std::end(seq));
        assert("Exemplar is an:== example string" == s);
    }
    // insert(const_iterator pos, std::initializer_list<char>)
    s.insert(s.cbegin() + s.find_first_of('g') + 1, { '.' });
    assert("Exemplar is an:== example string." == s);
}


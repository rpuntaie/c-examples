/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_iterator_traits.exe ./cpp/iterator_iterator_traits.cpp && (cd ../_build/cpp/;./iterator_iterator_traits.exe)
https://en.cppreference.com/w/cpp/iterator/iterator_traits
*/
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
    while(n > 0) {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
        n -= 2;
    }
}
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    my_reverse(v.begin(), v.end());
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    std::list<int> l{1, 2, 3, 4, 5};
    my_reverse(l.begin(), l.end());
    for (auto n : l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    int a[] = {1, 2, 3, 4, 5};
    my_reverse(a, a+5);
    for (int i=0; i<5; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    my_reverse(i1, i2); // compilation error
}


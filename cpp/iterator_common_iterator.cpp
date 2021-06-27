/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_common_iterator.exe ./cpp/iterator_common_iterator.cpp && (cd ../_build/cpp/;./iterator_common_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/common_iterator
*/
#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>
#include <string>
template <class ForwardIter>
void fire(ForwardIter first, ForwardIter last) {
    std::copy(first, last, std::ostream_iterator<std::string>{std::cout, " "});    
}
int main() {
    std::list<std::string> stars{"Pollux", "Arcturus", "Mira", "Aldebaran", "Sun"};
    using IT = std::common_iterator<
                   std::counted_iterator<std::list<std::string>::iterator>,
                   std::default_sentinel_t>;
    fire( IT(std::counted_iterator(stars.begin(), stars.size()-1)),
          IT(std::default_sentinel) );
}


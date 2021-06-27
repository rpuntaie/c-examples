/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_and.exe ./cpp/keyword_and.cpp && (cd ../_build/cpp/;./keyword_and.exe)
https://en.cppreference.com/w/cpp/keyword/and
*/
#include <iostream>
int n;
int main()
{
   if(n > 0 and n < 5)
   {
       std::cout << "n is small and positive\n";
   }
}


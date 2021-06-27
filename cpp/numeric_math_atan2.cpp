/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_math_atan2.exe ./cpp/numeric_math_atan2.cpp && (cd ../_build/cpp/;./numeric_math_atan2.exe)
https://en.cppreference.com/w/cpp/numeric/math/atan2
*/
#include <iostream>
#include <cmath>
int main()
{
    // normal usage: the signs of the two arguments determine the quadrant
    std::cout << "(x:+1,y:+1) cartesian is (r:" << hypot(1,1)
              << ",phi:" << atan2(1,1) << ") polar\n"  // atan2(1,1) = +pi/4, Quad I
              << "(x:-1,y:+1) cartesian is (r:" << hypot(1,-1)
              << ",phi:" << atan2(1,-1) << ") polar\n" // atan2(1, -1) = +3pi/4, Quad II
              << "(x:-1,y:-1) cartesian is (r:" << hypot(-1,-1)
              << ",phi:" << atan2(-1,-1) << ") polar\n" // atan2(-1,-1) = -3pi/4, Quad III
              << "(x:+1,y:-1) cartesian is (r:" << hypot(-1,1)
              << ",phi:" << atan2(-1,1) << ") polar\n"; // atan2(-1, 1) = -pi/4, Quad IV
    // special values
    std::cout << "atan2(0, 0) = " << atan2(0,0)
              << " atan2(0,-0) = " << atan2(0,-0.0) << '\n'
              << "atan2(7, 0) = " << atan2(7,0)
              << " atan2(7,-0) = " << atan2(7,-0.0) << '\n';
}


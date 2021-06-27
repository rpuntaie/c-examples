/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_end.exe ./cpp/container_unordered_set_end.cpp && (cd ../_build/cpp/;./container_unordered_set_end.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/end
*/
#include <iostream>
#include <unordered_set>
struct Point { double x, y; };
int main() {
    Point pts[3] = { {1, 0}, {2, 0}, {3, 0} };
    //points is a set containing the addresses of points
    std::unordered_set<Point *> points = { pts, pts + 1, pts + 2 };
    //Change each y-coordinate of (i, 0) from 0 into i^2 and print the point
    for(auto iter = points.begin(); iter != points.end(); ++iter){
        (*iter)->y = ((*iter)->x) * ((*iter)->x); //iter is a pointer-to-Point*
        std::cout << "(" << (*iter)->x << ", " << (*iter)->y << ") ";
    }
    std::cout << '\n';
    //Now using the range-based for loop, we increase each y-coordinate by 10
    for(Point * i : points) {
        i->y += 10;
        std::cout << "(" << i->x << ", " << i->y << ") ";
    }
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operators_6.exe ./cpp/language_operators_6.cpp && (cd ../_build/cpp/;./language_operators_6.exe)
https://en.cppreference.com/w/cpp/language/operators
*/
double a, b; // Bad: Global variables.
double linear(double x) {
    return a*x + b;
}
int main() {
    a = 2; b = 1;
    double f_0 = linear(0);
    double f_1 = linear(1);
    // Bad: Need to reassign the parameters to be able to calculate a different function:
    a = -1; b = 0;
    double g_0 = linear(0);
}


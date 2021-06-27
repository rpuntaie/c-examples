/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operators_7.exe ./cpp/language_operators_7.cpp && (cd ../_build/cpp/;./language_operators_7.exe)
https://en.cppreference.com/w/cpp/language/operators
*/
double linear(double a, double b, double x) {
    return a*x + b;
}
int main() {
    double f_0 = linear(2, 1, 0);
    // Bad: Have to repeat the same parameters again:
    double f_1 = linear(2, 1, 1);
    double g_0 = linear(-1, 0, 0);
}


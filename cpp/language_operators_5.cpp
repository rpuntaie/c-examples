/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operators_5.exe ./cpp/language_operators_5.cpp && (cd ../_build/cpp/;./language_operators_5.exe)
https://en.cppreference.com/w/cpp/language/operators
*/
// An object of this type represents a linear function of one variable a*x + b.
struct Linear {
    double a, b;
    double operator()(double x) const {
        return a*x + b;
    }
};
int main() {
    Linear f{2, 1}; // Represents function 2x + 1.
    Linear g{-1, 0}; // Represents function -x.
    // f and g are objects that can be used like a function.
    double f_0 = f(0);
    double f_1 = f(1);
    double g_0 = g(0);
}


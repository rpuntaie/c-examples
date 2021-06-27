/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_user_literal_1.exe ./cpp/language_user_literal_1.cpp && (cd ../_build/cpp/;./language_user_literal_1.exe)
https://en.cppreference.com/w/cpp/language/user_literal
*/
int main() {
    L"A" "B" "C"_x;  // OK: same as L"ABC"_x
    "P"_x "Q" "R"_y; // error: two different ud-suffixes (_x and _y)
}


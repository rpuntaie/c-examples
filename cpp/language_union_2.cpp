/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_union_2.exe ./cpp/language_union_2.cpp && (cd ../_build/cpp/;./language_union_2.exe)
https://en.cppreference.com/w/cpp/language/union
*/
int main()
{
    union
    {
        int a;
        const char* p;
    };
    a = 1;
    p = "Jennifer";
}


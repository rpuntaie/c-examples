/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_friend_3.exe ./cpp/language_friend_3.cpp && (cd ../_build/cpp/;./language_friend_3.exe)
https://en.cppreference.com/w/cpp/language/friend
*/
class F {};
int f();
int main()
{
    extern int g();
    class Local { // Local class in the main() function
        // friend int f(); // Error, no such function declared in main()
        friend int g(); // OK, there is a declaration for g in main()
        friend class F; // friends a local F (defined later)
        friend class ::F; // friends the global F
    };
    class F {}; // local F
}


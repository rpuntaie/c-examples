/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_placeholders.exe ./cpp/utility_functional_placeholders.cpp && (cd ../_build/cpp/;./utility_functional_placeholders.exe)
https://en.cppreference.com/w/cpp/utility/functional/placeholders
*/
#include <functional>
#include <string>
#include <iostream>
void goodbye(const std::string& s)
{
    std::cout << "Goodbye " << s << '\n';
}
class Object {
public:
    void hello(const std::string& s)
    {
        std::cout << "Hello " << s << '\n';
    }
};
int main()
{
    using ExampleFunction = std::function<void(const std::string&)>;
    Object instance;
    std::string str("World");
    ExampleFunction f = std::bind(&Object::hello, &instance, 
                                  std::placeholders::_1);
    // equivalent to instance.hello(str)
    f(str);
    f = std::bind(&goodbye, std::placeholders::_1);
    // equivalent to goodbye(str)
    f(str);    
    return 0;
}


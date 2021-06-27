/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_class.exe ./cpp/keyword_class.cpp && (cd ../_build/cpp/;./keyword_class.exe)
https://en.cppreference.com/w/cpp/keyword/class
*/
class Foo;  // forward declaration of a class
class Bar { // definition of a class
  public:
    Bar(int i) : m_i(i) {}
  private:
    int m_i;
};
template <class T> // template argument
void qux() {
    T t;
}
int main()
{
    Bar Bar(1);
    class Bar Bar2(2); // elaborated type
}


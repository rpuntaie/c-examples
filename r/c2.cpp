/*
g++ -std=c++20 -o ../_build/r/c2.exe r/c2.cpp && (cd ../_build/r;./c2.exe)
*/
#include <utility>
#include <vector>
#include <string>
#include <initializer_list>
using std::initializer_list;
struct MyData{
  MyData(int, double, char){};
};
//
template <typename T, typename... Args>
T createT(Args&&... args){
  return T(std::forward<Args>(args)... );
}
//
typedef std::vector<int> IntVec;
int main()
{
  int a= createT<int>();
  int b= createT<int>(1);
  std::string s= createT<std::string>("Only for testing.");
  MyData myData2= createT<MyData>(1, 3.19, 'a');
  IntVec intVec= createT<IntVec>(initializer_list<int>({1, 2, 3}));
  return 0;
}

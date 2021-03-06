/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_hash_operator.exe ./cpp/utility_hash_operator.cpp && (cd ../_build/cpp/;./utility_hash_operator.exe)
https://en.cppreference.com/w/cpp/utility/hash/operator()
*/
#include <functional>
#include <iostream>
#include <string>
struct Employee {
  std::string name;
  unsigned int ID;
};
namespace std {
template <>
class hash<Employee> {
 public:
  size_t operator()(const Employee &employee) const
  {
    // computes the hash of an employee using a variant 
    // of the Fowler-Noll-Vo hash function
    size_t result = 2166136261;
    for (size_t i = 0, ie = employee.name.size(); i != ie; ++i) {
      result = (result * 16777619) ^ employee.name[i];
    }
    return result ^ (employee.ID << 1);
  }
};
}
int main()
{
  Employee employee;
  employee.name = "Zaphod Beeblebrox";
  employee.ID = 42;
  std::hash<Employee> hash_fn;
  std::cout << hash_fn(employee) << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_type_info_operator_cmp.exe ./cpp/types_type_info_operator_cmp.cpp && (cd ../_build/cpp/;./types_type_info_operator_cmp.exe)
https://en.cppreference.com/w/cpp/types/type_info/operator_cmp
*/
#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>
class person
{
  public:
   person(std::string&& n) : _name(n) {}
   virtual const std::string& name() const{ return _name; }
  private:
    std::string _name;
};
class employee : public person
{
   public:
     employee(std::string&& n, std::string&& p) :
         person(std::move(n)), _profession(std::move(p)) {}
     const std::string& profession() const { return _profession; }
   private:
     std::string _profession;
};
void somefunc(const person& p)
{
   if(typeid(person) == typeid(p))
   {
      std::cout << p.name() << " is not an employee\n";
   }
   else if(typeid(employee) == typeid(p))
   {
      std::cout << p.name() << " is an employee ";
      auto& emp = dynamic_cast<const employee&>(p);
      std::cout << "who works in " << emp.profession() << '\n';
   }
}
int main()
{
   somefunc(employee{"Paul","Economics"});
   somefunc(person{"Kate"});
#  if defined(__cpp_lib_constexpr_typeinfo) // C++23
   if constexpr (typeid(employee) != typeid(person)) {
      std::cout << "class `employee` != class `person`\n";
   } 
#  endif
}


/*
g++ -std=c++20 -o ../_build/r/cf.exe r/cf.cpp && (cd ../_build/r;echo "2 3" | ./cf.exe)
*/

#include<iostream>

class Fraction{
public:
  Fraction(int num= 0, int denom= 0):numerator(num), denominator(denom){}
  friend std::istream& operator>> (std::istream& in, Fraction& frac);
  friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);
private:
  int numerator;
  int denominator;
};

std::istream& operator>> (std::istream& in, Fraction& frac){
  in >> frac.numerator;
  in >> frac.denominator;
  return in;
}
std::ostream& operator<< (std::ostream& out, const Fraction& frac){
  out << frac.numerator << "/" << frac.denominator;
  return out;
}

int main()
{
  Fraction frac(3, 4);
  std::cout << frac; // 3/4
  std::cout << "Enter two numbers: ";
  Fraction fracDef;
  std::cin >> fracDef; // <1 2>
  std::cout << fracDef; // 1/2
}

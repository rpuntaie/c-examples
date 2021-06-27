/*
g++ -std=c++20 -o ../_build/r/c6.exe r/c6.cpp && (cd ../_build/r;./c6.exe)
*/

#include <memory>
#include <iostream>

using namespace std;

struct Son;
struct Daughter;

struct Mother{
  ~Mother(){cout << "Mother gone" << endl;}
  void setSon(const shared_ptr<Son> s ){mySon= s;}
  void setDaughter(const shared_ptr<Daughter> d){myDaughter= d;}
  shared_ptr<const Son> mySon;
  weak_ptr<const Daughter> myDaughter;
};
struct Son{
  Son(shared_ptr<Mother> m):myMother(m){}
  ~Son(){cout << "Son gone" << endl;}
  shared_ptr<const Mother> myMother;
};
struct Daughter{
  Daughter(shared_ptr<Mother> m):myMother(m){}
  ~Daughter(){cout << "Daughter gone" << endl;}
  shared_ptr<const Mother> myMother;
};
int main(){
  shared_ptr<Mother> mother= shared_ptr<Mother>(new Mother);
  shared_ptr<Son> son= shared_ptr<Son>(new Son(mother) );
  shared_ptr<Daughter> daugh= shared_ptr<Daughter>(new Daughter(mother));
  mother->setSon(son);
  mother->setDaughter(daugh);
}

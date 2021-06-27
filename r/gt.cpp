/*
g++ -std=c++20 -pthread -o ../_build/r/gt.exe r/gt.cpp && (cd ../_build/r;./gt.exe)
*/

#include <iostream>
#include <mutex>
#include <latch>
#include <barrier>
#include <thread>

namespace s1{
std::latch workDone(6);
std::latch goHome(1);

std::mutex coutMutex;
void synchronizedOut(const std::string& s) {
    std::lock_guard<std::mutex> lo(coutMutex);
    std::cout << s;
}
class Worker {
public:
Worker(std::string n): name(n) { }
void operator() (){
    // notify the boss when work is done
    synchronizedOut(name + ": " + "Work done!\n");
    workDone.count_down();
    // waiting before going home
    goHome.wait();
    synchronizedOut(name + ": " + "Good bye!\n");
    }
private:
    std::string name;
};
void s1() {
  std::cout << '\n';
  std::cout << "BOSS: START WORKING! " << '\n';
  Worker herb("Herb");
  std::thread herbWork(herb);
  Worker scott("Scott");
  std::thread scottWork(scott);
  Worker bjarne("Bjarne");
  std::thread bjarneWork(bjarne);
  Worker andrei("Andrei");
  std::thread andreiWork(andrei);
  Worker andrew("Andrew");
  std::thread andrewWork(andrew);
  Worker david("David");
  std::thread davidWork(david);
  workDone.wait();
  std::cout << '\n';
  goHome.count_down();
  std::cout << "BOSS: GO HOME!" << '\n';
  herbWork.join();
  scottWork.join();
  bjarneWork.join();
  andreiWork.join();
  andrewWork.join();
  davidWork.join();
}

}

namespace s2{
std::barrier workDone(6);
std::mutex coutMutex;
void synchronizedOut(const std::string& s) {
  std::lock_guard<std::mutex> lo(coutMutex);
  std::cout << s;
}
class FullTimeWorker {
public:
  FullTimeWorker(std::string n): name(n) { }
  void operator() () {
    synchronizedOut(name + ": " + "Morning work done!\n");
    workDone.arrive_and_wait(); // Wait until morning work is done
    synchronizedOut(name + ": " + "Afternoon work done!\n");
    workDone.arrive_and_wait(); // Wait until afternoon work is done
  }
private:
  std::string name;
};
class PartTimeWorker {
public:
  PartTimeWorker(std::string n): name(n) { }
  void operator() () {
    synchronizedOut(name + ": " + "Morning work done!\n");
    workDone.arrive_and_drop(); // Wait until morning work is done
  }
private:
  std::string name;
};
void s2() {
  std::cout << '\n';
  FullTimeWorker herb(" Herb");
  std::thread herbWork(herb);
  FullTimeWorker scott(" Scott");
  std::thread scottWork(scott);
  FullTimeWorker bjarne(" Bjarne");
  std::thread bjarneWork(bjarne);
  PartTimeWorker andrei(" Andrei");
  std::thread andreiWork(andrei);
  PartTimeWorker andrew(" Andrew");
  std::thread andrewWork(andrew);
  PartTimeWorker david(" David");
  std::thread davidWork(david);
  herbWork.join();
  scottWork.join();
  bjarneWork.join();
  andreiWork.join();
  andrewWork.join();
  davidWork.join();
}
}


int main(){
  s1::s1();
  s2::s2();
}

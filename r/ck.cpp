/*
g++ -std=c++20 -pthread -o ../_build/r/ck.exe r/ck.cpp && (cd ../_build/r;./ck.exe)
*/

#include <chrono>
#include <iostream>
#include <deque>
#include <future>

using std::chrono::duration;
using std::chrono::system_clock;
using std::launch;
using namespace std;

struct SumUp{
  int operator()(int beg, int end){
    for (int i= beg; i < end; ++i ) sum += i;
    return sum;
  }
private:
  int beg;
  int end;
  int sum{0};
};

void pk()
{
  SumUp sumUp1, sumUp2;
  packaged_task<int(int, int)> sumTask1(sumUp1);
  packaged_task<int(int, int)> sumTask2(sumUp2);
  future<int> sum1= sumTask1.get_future();
  future<int> sum2= sumTask2.get_future();
  deque< packaged_task<int(int, int)>> allTasks;
  allTasks.push_back(move(sumTask1));
  allTasks.push_back(move(sumTask2));
  int begin{1};
  int increment{5000};
  int end= begin + increment;
  while (not allTasks.empty()){
    packaged_task<int(int, int)> myTask= move(allTasks.front());
    allTasks.pop_front();
    thread sumThread(move(myTask), begin, end);
    begin= end;
    end += increment;
    sumThread.detach();
  }
  auto sum= sum1.get() + sum2.get();
  cout << sum; 
}

void product(std::promise<int>&& intPromise, int a, int b)
  {intPromise.set_value(a*b);}
void pf()
{
  int a= 20;
  int b= 10;
  std::promise<int> prodPromise;
  std::future<int> prodResult = prodPromise.get_future();
  std::thread prodThread(product, std::move(prodPromise), a, b);
  std::cout << "20*10= " << prodResult.get();
  prodThread.join();
}

void doTheWork(){
  std::cout << "Processing shared data." << std::endl;
  }
void waitingForWork(std::future<void>&& fut){
  std::cout << "Worker: Waiting for work." <<
  std::endl;
  fut.wait();
  doTheWork();
  std::cout << "Work done." << std::endl;
  }
void setDataReady(std::promise<void>&& prom){
  std::cout << "Sender: Data is ready." <<
  std::endl;
  prom.set_value();
  }
void fw() {
  std::promise<void> sendReady;
  auto fut= sendReady.get_future();
  std::thread t1(waitingForWork, std::move(fut));
  std::thread t2(setDataReady, std::move(sendReady));
  t1.join();
  t2.join();
  }

int main()
{
  auto begin= system_clock::now();
  auto asyncLazy= std::async(launch::deferred, []{ return system_clock::now(); });
  auto asyncEager= std::async(launch::async, []{ return system_clock::now(); });
  std::this_thread::sleep_for(std::chrono::seconds(1));
  auto lazyStart= asyncLazy.get() - begin;
  auto eagerStart= asyncEager.get() - begin;
  auto lazyDuration= duration<double>(lazyStart).count();
  auto eagerDuration= duration<double>(eagerStart).count();
  std::cout << lazyDuration << " sec" << std::endl; // 1.00018 sec.
  std::cout << eagerDuration << " sec" << std::endl; // 0.00015489 sec

  pk();

  pf();

  fw();
}

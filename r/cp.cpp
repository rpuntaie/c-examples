/*
g++ -std=c++20 -pthread -o ../_build/r/cp.exe r/cp.cpp && (cd ../_build/r;./cp.exe)
*/

#include <atomic>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>

std::atomic_int x, y;
int r1, r2;
void writeX(){
  x.store(1);
  r1= y.load();
}
void writeY(){
  y.store(1);
  r2= x.load();
}

using namespace std;
void helloFunction(){
  cout << "function" << endl;
}
class HelloFunctionObject {
public:
  void operator()() const {
    cout << "function object" << endl;
  }
};

auto lf = []{ cout << "lambda function" << endl; };

void printStringCopy(string s){ cout << s; }
void printStringRef(const string& s){ cout << s; }

// mutex recursive_mutex timed_mutex recursive_timed_mutex shared_timed_mutex
mutex mutexCout;
void mt()
{
  struct Worker{
    Worker(string n):name(n){};
    void operator() (){
      for (int i= 1; i <= 3; ++i){
        this_thread::sleep_for(chrono::milliseconds(200));
        lock_guard lg(mutexCout);//mutexCout.lock();
        cout << name << ": " << "Work " << i << endl;
        //mutexCout.unlock();
      }
    }
  private:
    string name;
  };
  thread herb= thread(Worker("Herb"));
  thread andrei= thread(Worker(" Andrei"));
  thread scott= thread(Worker (" Scott"));
  thread bjarne= thread(Worker(" Bjarne"));
  herb.join();andrei.join();scott.join();bjarne.join();
}

void th()
{
  using std::this_thread::sleep_for;
  using std::this_thread::get_id;
  struct Sleeper{
    Sleeper(int& i_):i{i_}{};
    void operator() (int k){
      for (unsigned int j= 0; j <= 5; ++j){
        sleep_for(std::chrono::milliseconds(100));
        i += k;
      }
      std::cout << get_id(); // undefined behaviour
    }
  private:
    int& i;
  };
  int valSleeper= 1000;
  std::thread t(Sleeper(valSleeper), 5);
  t.join();
  std::cout << valSleeper << endl; // undefined behaviour
}

struct CriticalData{
  mutex mut;
};
void deadLockResolved(CriticalData& a, CriticalData& b){
  unique_lock<mutex>guard1(a.mut, defer_lock);
  cout << this_thread::get_id() << ": get the first lock" << endl;
  this_thread::sleep_for(chrono::milliseconds(1));
  unique_lock<mutex>guard2(b.mut, defer_lock);
  cout << this_thread::get_id() << ": get the second lock" << endl;
  cout << this_thread::get_id() << ": atomic locking";
  lock(guard1, guard2);
}
void defer()
{
CriticalData c1;
CriticalData c2;
thread t1([&]{ deadLockResolved(c1, c2); });
thread t2([&]{ deadLockResolved(c2, c1); });
t1.join();t2.join();
}

void reader_writer()
{
  std::shared_timed_mutex sharedMutex;
  std::unique_lock<std::shared_timed_mutex> writerLock(sharedMutex);
  std::shared_lock<std::shared_timed_mutex> readerLock(sharedMutex);
  std::shared_lock<std::shared_timed_mutex> readerLock2(sharedMutex);
}

once_flag onceFlag;
void do_once(){
  call_once(onceFlag, []{ cout << "Only once." << endl; });
}
void cw()
{
thread t1(do_once);
thread t2(do_once);
t1.join();t2.join();
}

std::mutex coutMutex;
thread_local std::string s("hello from ");
void addThreadLocal(std::string const& s2){
  s+= s2;
  std::lock_guard<std::mutex> guard(coutMutex);
  std::cout << s << std::endl;
  std::cout << "&s: " << &s << std::endl;
  std::cout << std::endl;
}
void tl()
{
  std::thread t1(addThreadLocal, "t1");
  std::thread t2(addThreadLocal, "t2");
  std::thread t3(addThreadLocal, "t3");
  std::thread t4(addThreadLocal, "t4");
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

struct conditionl
{
  std::mutex mutex_;
  std::condition_variable condVar;
  bool dataReady= false;
  void doTheWork(){
    std::cout << "Processing shared data." << std::endl;
  }
  void waitingForWork(){
    std::cout << "Worker: Waiting for work." << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, [this]{ return dataReady; });
    doTheWork();
    std::cout << "Work done." << std::endl;
  }
  void setDataReady(){
    std::lock_guard<std::mutex> lck(mutex_);
    dataReady=true;
    std::cout << "Sender: Data is ready." << std::endl;
    condVar.notify_one();
  }
  void operator()()
  {
    std::thread t1(&conditionl::waitingForWork,this);
    std::thread t2(&conditionl::setDataReady,this);
    t1.join();
    t2.join();
  }
};

int main()
{
  x= 0;
  y= 0;
  thread a(writeX);
  thread b(writeY);
  a.join();
  b.join();
  cout << r1 << r2 << endl;

  thread t1(helloFunction); // function
  HelloFunctionObject helloFunctionObject;
  thread t2(helloFunctionObject); // function object
  thread t3(lf);//[]{ cout << "lambda function"; }); // lambda function
  t1.join(); t2.join();

  t2 = move(t3);
  t2.join();

  string s{"C++"};
  thread tPerCopy([=]{ cout << s; }); // C++
  thread tPerCopy2(printStringCopy, s); // C++
  tPerCopy.join();
  tPerCopy2.join();
  thread tPerReference([&]{ cout << s; }); // C++
  thread tPerReference2(printStringRef, s); // C++
  tPerReference.join();
  tPerReference2.join();
  cout << endl;

  th();

  cout << thread::hardware_concurrency();
  std::thread nt1([]{ cout << this_thread::get_id(); });
  std::thread nt2([]{ cout << this_thread::get_id(); });
  cout << nt1.get_id();
  cout << nt2.get_id();
  nt1.swap(nt2);
  cout << nt1.get_id();
  nt1.join();nt2.join();

  mt();

  defer();

  cw();

  tl();
}


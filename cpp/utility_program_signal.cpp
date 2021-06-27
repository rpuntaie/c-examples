/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_signal.exe ./cpp/utility_program_signal.cpp && (cd ../_build/cpp/;./utility_program_signal.exe)
https://en.cppreference.com/w/cpp/utility/program/signal
*/
#include <csignal>
#include <iostream>
namespace
{
  volatile std::sig_atomic_t gSignalStatus;
}
void signal_handler(int signal)
{
  gSignalStatus = signal;
}
int main()
{
  // Install a signal handler
  std::signal(SIGINT, signal_handler);
  std::cout << "SignalValue: " << gSignalStatus << '\n';
  std::cout << "Sending signal " << SIGINT << '\n';
  std::raise(SIGINT);
  std::cout << "SignalValue: " << gSignalStatus << '\n';
}


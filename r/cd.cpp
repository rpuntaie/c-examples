/*
g++ -std=c++20 -o ../_build/r/cd.exe r/cd.cpp && (cd ../_build/r;./cd.exe)
*/

#include <filesystem>
#include <iostream>
#include <fstream>
#include <chrono>

#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>

#include <sys/socket.h>

namespace fs = std::filesystem;

using namespace std::chrono_literals;

void printPerms(fs::perms perm){
  std::cout << ((perm & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
  << ((perm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
  << ((perm & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
  << ((perm & fs::perms::group_read) != fs::perms::none ? "r" : "-")
  << ((perm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
  << ((perm & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
  << ((perm & fs::perms::others_read) != fs::perms::none ? "r" : "-")
  << ((perm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
  << ((perm & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
  << std::endl;
}

void perms() {
  std::ofstream("rainer.txt");
  std::cout << "Initial file permissions for a file: ";
  printPerms(fs::status("rainer.txt").permissions()); // (1)
  fs::permissions("rainer.txt", fs::perms::all | // (2)
  fs::perms::owner_all | fs::perms::group_all);
  std::cout << "Adding all bits to owner and group: ";
}

auto to_time_t(auto ftime) {
  return std::chrono::system_clock::to_time_t(
      std::chrono::file_clock::to_sys(ftime));
}

void ft()
{
  fs::path path = fs::current_path() / "rainer.txt";
  std::ofstream(path.c_str());
  auto ftime = fs::last_write_time(path); // (1)
  std::time_t cftime = to_time_t(ftime); // (2)
  std::cout << "Write time on server " // (3)
  << std::asctime(std::localtime(&cftime));
  std::cout << "Write time on server " // (4)
  << std::asctime(std::gmtime(&cftime)) << std::endl;
  fs::last_write_time(path, ftime + 2h); // (5)
  ftime = fs::last_write_time(path); // (6)
  cftime = to_time_t(ftime);
  std::cout << "Local time on client "
  << std::asctime(std::localtime(&cftime)) << std::endl;
}

void spc()
{
fs::space_info root = fs::space("/");
fs::space_info usr = fs::space("/usr");
std::cout << ". Capacity Free Available\n"
<< "/ " << root.capacity << " "
<< root.free << " " << root.available << "\n"
<< "usr " << usr.capacity << " "
<< usr.free << " " << usr.available;
}

void printStatus(const fs::path& path_){
  std::cout << path_;
  if(!fs::exists(path_)) std::cout << " does not exist";
  else{
    if(fs::is_block_file(path_)) std::cout << " is a block file\n";
    if(fs::is_character_file(path_)) std::cout << " is a character device\n";
    if(fs::is_directory(path_)) std::cout << " is a directory\n";
    if(fs::is_fifo(path_)) std::cout << " is a named pipe\n";
    if(fs::is_regular_file(path_)) std::cout << " is a regular file\n";
    if(fs::is_socket(path_)) std::cout << " is a socket\n";
    if(fs::is_symlink(path_)) std::cout << " is a symlink\n";
    }
}

void tp()
{
  try{
    fs::remove_all("rain.txt");
  }catch(...){};

  fs::create_directory("rain.txt");
  printStatus("rain.txt");
  std::ofstream("rain.txt/regularFile.txt");
  printStatus("rain.txt/regularFile.txt");
  fs::create_directory("rain.txt/directory");
  printStatus("rain.txt/directory");
  mkfifo("rain.txt/namedPipe", 0644);
  printStatus("rain.txt/namedPipe");
  struct sockaddr_un addr;
  addr.sun_family = AF_UNIX;
  std::strcpy(addr.sun_path, "rain.txt/socket");
  int fd = socket(PF_UNIX, SOCK_STREAM, 0);
  bind(fd, (struct sockaddr*)&addr, sizeof addr);
  printStatus("rain.txt/socket");
  try{
    fs::remove_all("symlnk.txt");
  }catch(...){};
  fs::create_symlink("rain.txt/regularFile.txt", "symlnk.txt");
  printStatus("symlnk.txt");
  printStatus("dummy.txt");
  fs::remove_all("rain.txt");
}

int main()
{
  try{
    fs::remove_all("sand.txt");
    fs::remove_all("sym.txt");
  }
  catch(std::exception){
  }
  std::cout << "Current path: " << fs::current_path() << std::endl; // (1)
  std::string dir= "sand.txt/a/b";
  fs::create_directories(dir); // (2)
  std::ofstream("sand.txt/file1.txt");
  fs::path sym_txt= fs::current_path() /= "sand.txt"; // (3)
  sym_txt /= "syma";
  fs::create_symlink("a", "sym.txt"); // (4)
  std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
  std::cout << "fs::exists(sym_txt): " << fs::exists(sym_txt) << std::endl;
  std::cout << "fs::symlink(sym_txt): " << fs::is_symlink(sym_txt) << std::endl;
  for(auto& p: fs::recursive_directory_iterator("sand.txt")) // (5)
    std::cout << p << std::endl;
  for(auto& p: fs::directory_iterator("sand.txt"))
     std::cout << p.path() << '\n';
  fs::remove_all("sand.txt");
  //
  perms();
  ft();
  spc();
  tp();
}


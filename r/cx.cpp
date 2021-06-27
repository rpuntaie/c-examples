/*
g++ -std=c++20 -o ../_build/r/cx.exe r/cx.cpp && (cd ../_build/r;./cx.exe)
*/
#include <iostream>
#include <regex>
#include <string>

using std::regex_constants::ECMAScript;
using std::regex_constants::icase;

using namespace std::string_literals;


void showCaptureGroups(const std::string& regEx, const std::string& text) {
  std::regex rgx(regEx);
  std::smatch smatch;
  if (std::regex_search(text, smatch, rgx)){
    std::cout << regEx << text << smatch[0] << " " << smatch[1]
    << " "<< smatch[2] << " " << smatch[3] << std::endl;
  }
}

void srch()
{
  // regular expression holder for time
  std::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");
  // const char*
  std::cmatch cmatch;
  const char* ctime{"Now it is 23:10."};
  if (std::regex_search(ctime, cmatch, crgx)){
  std::cout << ctime << std::endl; // Now it is 23:10.
  std::cout << "Time: " << cmatch[0] << std::endl; // Time: 23:10
  }
  // std::string
  std::smatch smatch;
  std::string stime{"Now it is 23:25."};
  if (std::regex_search(stime, smatch, crgx)){
    std::cout << stime << std::endl; // Now it is 23:25.
    std::cout << "Time: " << smatch[0] << std::endl; // Time: 23:25
  }
  // regular expression holder for time
  std::wregex wrgx(L"([01]?[0-9]|2[0-3]):[0-5][0-9]");
  // const wchar_t*
  std::wcmatch wcmatch;
  const wchar_t* wctime{L"Now it is 23:47."};
  if (std::regex_search(wctime, wcmatch, wrgx)){
    std::wcout << wctime << std::endl; // Now it is 23:47.
    std::wcout << "Time: " << wcmatch[0] << std::endl; // Time: 23:47
    }
  // std::wstring
  std::wsmatch wsmatch;
  std::wstring wstime{L"Now it is 00:03."};
  if (std::regex_search(wstime, wsmatch, wrgx)){
    std::wcout << wstime << std::endl; // Now it is 00:03.
    std::wcout << "Time: " << wsmatch[0] << std::endl; // Time: 00:03
  }
}

void replc()
{
  using namespace std;
  string future{"Future"};
  string unofficialName{"The unofficial name of the new C++ standard is C++0x."};
  regex rgxCpp{R"(C\+\+0x)"};
  string newCppName{"C++11"};
  string newName{regex_replace(unofficialName, rgxCpp, newCppName)};
  regex rgxOff{"unofficial"};
  string makeOfficial{"official"};
  string officialName{regex_replace(newName, rgxOff, makeOfficial)};
  cout << officialName << endl;
}

int main()
{
  std::string theQuestion="C++ or c++, that's the question.";
  std::string regExprStr(R"(c\+\+)");
  std::regex rgx(regExprStr);
  std::smatch smatch;
  if (std::regex_search(theQuestion, smatch, rgx)){
    std::cout << "case sensitive: " << smatch[0]; // c++
  }
  std::regex rgxIn(regExprStr, ECMAScript|icase);
  if (std::regex_search(theQuestion, smatch, rgxIn)){
    std::cout << "case insensitive: " << smatch[0]; // C++
  }

  showCaptureGroups("abc+"s, "abccccc"s);
  showCaptureGroups("(a+)(b+)"s, "aaabccc"s);
  showCaptureGroups("((a+)(b+))"s, "aaabccc"s);
  showCaptureGroups("(ab)(abc)+"s, "ababcabc"s);

  std::string privateAddress="192.168.178.21";
  std::string regEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
  std::regex gx(regEx);
  std::smatch atch;
  if (std::regex_match(privateAddress, atch, gx)){
    for (auto cap: atch){
      std::cout << "capture group: " << cap << std::endl;
      if (cap.matched){
        std::for_each(cap.first, cap.second, [](int v){
        std::cout << std::hex << v << " ";});
        std::cout << std::endl;
        }
    }
  }

  srch();
  replc();
}


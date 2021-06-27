/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_stack_push.exe ./cpp/container_stack_push.cpp && (cd ../_build/cpp/;./container_stack_push.exe)
https://en.cppreference.com/w/cpp/container/stack/push
*/
#include <map>
#include <stack>
#include <array>
#include <iostream>
#include <stdexcept>
#include <string_view>
class BrainHackInterpreter {
    std::map<unsigned, unsigned> open_brackets, close_brackets;
    unsigned program_pos_{0};
    std::array<std::uint8_t, 32768> data_;
    int data_pos_{0};
    void collect_brackets_positions(const std::string_view program) {
        std::stack<unsigned> brackets_stack;
        for (auto pos{0U}; pos != program.length(); ++pos) {
            const char c{program[pos]};
            if ('[' == c) {
                brackets_stack.push(pos);
            } else if (']' == c) {
                if (brackets_stack.empty()) {
                    throw std::runtime_error("brackets [] do not match!");
                } else {
                    open_brackets[brackets_stack.top()] = pos;
                    close_brackets[pos] = brackets_stack.top();
                    brackets_stack.pop();
                }
            }
        }
        if (!brackets_stack.empty())
            throw std::runtime_error("brackets [] do not match!");
    }
    void check_data_pos(int pos) {
        if (pos < 0 or pos >= static_cast<int>(data_.size()))
            throw std::out_of_range{"data pointer out of bound"};
    }
  public:
    BrainHackInterpreter(const std::string_view program) {
        collect_brackets_positions(program);
        data_.fill(0);
        for (; program_pos_ < program.length(); ++program_pos_) {
            switch (program[program_pos_]) {
                case '<': check_data_pos(--data_pos_); break;
                case '>': check_data_pos(++data_pos_); break;
                case '-': --data_[data_pos_]; break;
                case '+': ++data_[data_pos_]; break;
                case '.': std::cout << data_[data_pos_]; break;
                case ',': std::cin >> data_[data_pos_]; break;
                case '[':
                    if (data_[data_pos_] == 0)
                        program_pos_ = open_brackets[program_pos_];
                    break;
                case ']':
                    if (data_[data_pos_] != 0)
                        program_pos_ = close_brackets[program_pos_];
                    break;
            }
        }
    }
};
int main()
{
    BrainHackInterpreter
    {
        "++++++++[>++>>++>++++>++++<<<<<-]>[<+++>>+++<-]>[<+"
        "+>>>+<<-]<[>+>+<<-]>>>--------.<<+++++++++.<<----.>"
        ">>>>.<<<------.>..++.<++.+.-.>.<.>----.<--.++.>>>+."
    };
}


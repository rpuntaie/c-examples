/*
g++ -std=c++20 -c r/tf.cpp
*/

#include <concepts>
#include <string>

template<typename T>
class optional{
public:
    optional() = default;

    // trivial copy-constructor
    optional(const optional&) = default;

    // non-trivial copy-constructor
    optional(const optional& rhs)
        requires(!std::is_trivially_copy_constructible_v<T>){
        // ...
    }

    // trivial destructor
    ~optional() = default;

    // non-trivial destructor
    ~optional() requires(!std::is_trivial_v<T>){
        // ...
    }
    // ...
private:
    T value;
};

static_assert(std::is_trivial_v<optional<int>>);
static_assert(!std::is_trivial_v<optional<std::string>>);

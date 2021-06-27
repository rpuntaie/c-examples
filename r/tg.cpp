/*
g++ -std=c++20 -c r/tg.cpp
*/

#include <compare>

template<typename T1, typename T2>
void TestComparisons(T1 a, T2 b)
{
    (a < b), (a <= b), (a > b), (a >= b), (a == b), (a != b);
}

struct S2
{
    int a;
    int b;
};

struct S1
{
    int x;
    int y;

    // support homogeneous comparisons
    auto operator<=>(const S1&) const = default;
    // this is required because there's operator==(const S2&) which prevents
    // implicit declaration of defaulted operator==()
    bool operator==(const S1&) const = default;

    // support heterogeneous comparisons
    std::strong_ordering operator<=>(const S2& other) const
    {
        if (auto cmp = x <=> other.a; cmp != 0)
            return cmp;
        return y <=> other.b;
    }

    bool operator==(const S2& other) const
    {
        return (*this <=> other) == 0;
    }
};

void wrapper(){
TestComparisons(S1{}, S1{});
TestComparisons(S1{}, S2{});
TestComparisons(S2{}, S1{});
}

template<typename T>
struct X
{
    friend constexpr std::partial_ordering operator<=>(X, X) requires(sizeof(T) != 1) = default;
    // implicitly declares:
    // friend constexpr bool operator==(X, X) requires(sizeof(T) != 1) = default;

    [[nodiscard]] virtual std::strong_ordering operator<=>(const X&) const = default;
    // implicitly declares:
    //[[nodiscard]] virtual bool operator==(const X&) const = default; 
};

struct S3{
    int x;      // int-s are strongly ordered
    double d;   // but double-s are partially ordered
    // thus, the resulting category is std::partial_ordering
    auto operator<=>(const S3&) const = default;
};
static_assert(std::is_same_v<decltype(S3{} <=> S3{}), std::partial_ordering>);

// They must be members or friends and only friends can take by-value.
// 
struct S4
{
    int x;
    int y;
    // member version must have op(const T&) const; form
    auto operator<=>(const S4&) const = default;

    // friend version can take arguments by const-reference or by-value
    // friend auto operator<=>(const S4&, const S4&) = default;
    // friend auto operator<=>(S4, S4) = default;
};

// Can be out-of-class defaulted, just like special member functions.
// 
struct S5
{
    int x;
    std::strong_ordering operator<=>(const S5&) const;
    bool operator==(const S5&) const;
};

std::strong_ordering S5::operator<=>(const S5&) const = default;
bool S5::operator==(const S5&) const = default;

// Defaulted `operator<=>()` uses `operator<=>()` of class members or
// their ordering can be synthesized using existing `Member::operator==()` and `Member::operator<()`.
// Note that it works only for members and not for the class itself,
// existing `T::operator<()` is never used in defaulted `T::operator<=>()`.
// 
// not in our immediate control
struct Legacy
{
    bool operator==(Legacy const&) const;
    bool operator<(Legacy const&) const;
};

struct S6
{
    int x;
    Legacy l;
    // deleted because Legacy doesn't have operator<=>(), comparison category
    // can't be deduced
    auto operator<=>(const S6&) const = default;
};

struct S7
{
    int x;
    Legacy l;

    std::strong_ordering operator<=>(const S7& rhs) const = default;
    /*
    Since comparison category is provided explicitly, ordering can be
    synthesized using operator<() and operator==(). They must return exactly
    `bool` for this to work. It will work for weak and partial ordering as well.
    
    Here's an example of synthesized operator<=>():
    std::strong_ordering operator<=>(const S7& rhs) const
    {
        // use operator<=>() for int
        if(auto cmp = x <=> rhs.x; cmp != 0) return cmp;

        // synthesize ordering for Legacy using operator<() and operator==()
        if(l == rhs.l) return std::strong_ordering::equal;
        if(l < rhs.l) return std::strong_ordering::less;
        return std::strong_ordering::greater;
    }
    */
};

struct NoEqual
{
    bool operator<(const NoEqual&) const = default;
};

struct S8
{
    NoEqual n;
    // deleted, NoEqual doesn't have operator<=>()
    // auto operator<=>(const S8&) const = default;

    // deleted as well because NoEqual doesn't have operator==()
    std::strong_ordering operator<=>(const S8&) const = default;
};

// struct W
// {
//     std::weak_ordering operator<=>(const W&) const = default;
// };
// 
// struct S9
// {
//     W w;
//     // ask for strong_ordering but W can provide only weak_ordering, this will
//     // yield an error during instantiation
//     std::strong_ordering operator<=>(const S9&) const = default;
//     void f()
//     {
//         (S9{} <=> S9{});    // error
//     }
// };

// // `union` and reference members are not supported.
// // 
// struct S4
// {
//     int& r;
//     // deleted because of reference member
//     auto operator<=>(const S4&) const = default;
// };

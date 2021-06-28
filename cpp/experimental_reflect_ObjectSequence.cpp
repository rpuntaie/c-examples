/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_reflect_ObjectSequence.exe ./cpp/experimental_reflect_ObjectSequence.cpp && (cd ../_build/cpp/;./experimental_reflect_ObjectSequence.exe)
https://en.cppreference.com/w/cpp/experimental/reflect/ObjectSequence
*/
#include<type_traits>
#include<tuple>
#include<cmath>
#include<experimental/reflect>
using reflect = std::experimental::reflect;
template<reflect::Typed... Ms>
using tuple_from_seq_t = std::tuple<reflect::get_reflected_type_t<
    reflect::get_type_t<Ms>>...>;
template<reflect::Record T>
using collect_tuple = reflect::unpack_sequence_t<
    tuple_from_seq_t,
    reflect::get_data_members<T>>;
int main()
{
    static_assert(reflect::ObjectSequence<
                      reflect::get_data_members<reflexpr(std::div_t)>>, "");
    static_assert(std::is_same<collect_tuple<reflexpr(std::div_t)>,
                               std::tuple<int, int>>::value, "");
}


/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_unique_resource_make_unique_resource_checked.exe ./cpp/experimental_unique_resource_make_unique_resource_checked.cpp && (cd ../_build/cpp/;./experimental_unique_resource_make_unique_resource_checked.exe)
https://en.cppreference.com/w/cpp/experimental/unique_resource/make_unique_resource_checked
*/
#include <cstdio>
#include <experimental/scope>
int main()
{
    // avoid calling fclose when fopen fails
    auto file = std::experimental::make_unique_resource_checked(
        std::fopen("potentially_nonexistent_file.txt", "r"),
        nullptr,
        [](std::FILE *fptr){ std::fclose(fptr); }
    );
    if (file.get()) {
        std::puts("The file exits.");
    }
    else {
        std::puts("The file does not exist.");
    }
}


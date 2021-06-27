/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_gslice_array.exe ./cpp/numeric_valarray_gslice_array.cpp && (cd ../_build/cpp/;./numeric_valarray_gslice_array.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/gslice_array
*/
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <valarray>
int main()
{
    std::valarray<int> data(32);
    std::iota(std::begin(data), std::end(data), 0);
    const std::size_t offset = 1, z = 2, y = 3, x = 4;
    const std::valarray<std::size_t> sizes{z, y, x};
    const std::valarray<std::size_t> strides{15, 5, 1};
    const std::gslice gslice = std::gslice(offset, sizes, strides);
    // indices are generated according to the formula:
    // index[k] = offset + [0,1,2)*15 + [0,1,2,3)*5 + [0,1,2,3,4)*1
    //          = offset + inner_product(sizes[k], strides);
    // where sizes[k] = {[0,z), [0,y), [0,x)}, while the rightmost index (x)
    // runs fastest. As a result we have following set of indices:
    //  index[0]  = 1 + 0*15 + 0*5 + 0*1 = 1
    //  index[1]  = 1 + 0*15 + 0*5 + 1*1 = 2
    //  index[2]  = 1 + 0*15 + 0*5 + 2*1 = 3
    //  index[3]  = 1 + 0*15 + 0*5 + 3*1 = 4
    //  index[4]  = 1 + 0*15 + 1*5 + 0*1 = 6
    //  index[5]  = 1 + 0*15 + 1*5 + 1*1 = 7
    //  index[6]  = 1 + 0*15 + 1*5 + 2*1 = 8
    //  index[7]  = 1 + 0*15 + 1*5 + 3*1 = 9
    //  ...
    //  index[22] = 1 + 1*15 + 2*5 + 2*1 = 28
    //  index[23] = 1 + 1*15 + 2*5 + 3*1 = 29
    const std::valarray<int> indices = data[gslice];
    for (unsigned i=0; i != indices.size(); ++i) {
        std::cout << std::setfill('0') << std::setw(2) << indices[i] << ' ';
    }
    std::cout << "\nTotal indices: " << indices.size() << '\n';
    assert(indices.size() == x*y*z);
    data = 0;
    std::gslice_array<int> gslice_array = data[gslice];
    gslice_array = 1;
    // Cells that correspond to generated indices = '1', skipped cells = '0'.
    for (auto i : data) { std::cout << i << ' '; }
    std::cout << "\nSum of ones = " << data.sum() << '\n';
}


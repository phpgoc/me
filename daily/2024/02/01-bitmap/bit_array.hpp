//
// Created by 杨殿擎 on 2024/2/1.
//

#ifndef INC_01_BITMAP_META_PROGRAMING_H
#define INC_01_BITMAP_META_PROGRAMING_H
#include <utility>

constexpr unsigned int count_1_bit(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

template<unsigned int N>
constexpr std::array<unsigned int, N> range_array(){
    std::array<unsigned int, N> arr{};
    for (unsigned int i = 0; i < N; ++i) {
        arr[i] = count_1_bit(i);
    }
    return arr;
}
#endif//INC_01_BITMAP_META_PROGRAMING_H

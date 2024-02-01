//
// Created by 杨殿擎 on 2024/2/1.
//

#include "bitmap.h"

#include <iostream>
#include <set>

void set_seed() {
    srand(time(nullptr));
}
void set_rand_n(bitmap &b,  unsigned int n) {
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        int rd  = rand()%b.size();
        s.insert(rd);
    }
    for (auto i : s) {
        b.set_unchecked(i);
//        std::cout << i << " ";
    }
    std::cout << "set length:" << s.size() << "\n";
}
int main() {
    set_seed();
    bitmap b(100000000);
    set_rand_n(b, 20000000);
    auto start = std::chrono::steady_clock::now();
    std::cout << b.count_every_bit() << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    start = std::chrono::steady_clock::now();
    std::cout << b.count_every_byte() << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}
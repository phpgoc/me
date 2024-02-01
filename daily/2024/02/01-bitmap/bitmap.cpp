#include "bitmap.h"

#include <iostream>
#include <cstring>


bitmap::bitmap(unsigned int length)  {
    this->bit_length = length;
    data = new DATA_TYPE[data_length()];
    clear();
}

bitmap::~bitmap() {
    delete[] data;
}



void bitmap::set_unchecked(unsigned int index) noexcept {
    unsigned int data_index = index / sizeof(DATA_TYPE) / 8;
    unsigned  int remain = index %(sizeof(DATA_TYPE) *8);
    data[data_index] |= ((DATA_TYPE)1 << remain);
//    std::cout << "index:"<< index <<",data:" << data[data_index]<<std::endl;
}

void bitmap::unset_unchecked(unsigned int index) noexcept {
    data[index/sizeof(DATA_TYPE)/8] &= ~((DATA_TYPE) 1 << (index % (sizeof(DATA_TYPE)*8)));
}


bool bitmap::get_unchecked(unsigned int index) noexcept {
    unsigned int data_index = index / sizeof(DATA_TYPE) / 8;
    unsigned  int remain = index %(sizeof(DATA_TYPE) *8);
    bool res = data[data_index] & ((DATA_TYPE) 1 << remain);
    if(res){
//        std::cout << "data_index:" << data_index <<",remain:" << remain ;
//        std::cout << "index:" << index << "\n";
    }
    return res;
}


void bitmap::clear() {
    memset(data, 0, bit_length /sizeof(DATA_TYPE));
}

unsigned int bitmap::size() {
    return bit_length;
}

unsigned int bitmap::count_every_bit() {
    unsigned int count = 0;
    for (unsigned int i = 0; i < bit_length; ++i) {
        if (get_unchecked(i)) {
            ++count;
        }
    }
    return count;
}

unsigned int bitmap::count_every_byte() {
    constexpr std::array<unsigned int, 256> count_table = range_array<256>();

    unsigned char *p = reinterpret_cast<unsigned char*>(data);
    unsigned int count = 0;
    for (unsigned int i = 0; i < data_length()*sizeof(DATA_TYPE); ++i) {
        count += count_table[p[i]];
    }
    return count;
}

int bitmap::data_length() const {
    if(bit_length % (sizeof(DATA_TYPE)*8) != 0){
        return bit_length/sizeof(DATA_TYPE)/8+1;
    }else{
        return bit_length/sizeof(DATA_TYPE)/8;
    }
}


#ifndef INC_01_BITMAP_BITMAP_H
#define INC_01_BITMAP_BITMAP_H

#include <array>
#include <utility>

#include "bit_array.hpp"

class bitmap {
    using DATA_TYPE = long;

public:
    bitmap(unsigned int length);
    ~bitmap();
    void set_unchecked(unsigned int index) noexcept;
    void unset_unchecked(unsigned int index) noexcept;
    bool get_unchecked(unsigned int index) noexcept;
    void clear();
    unsigned int size() ;
    unsigned int count_every_bit();
    unsigned int count_every_byte();
    int data_length() const;

private:
    DATA_TYPE *data;
    unsigned int bit_length;



};

#endif//INC_01_BITMAP_BITMAP_H

#pragma once

template<int Z> class ring {
private:
    int data;
public:
    ring<Z>(int i) : data(i) {}
    ring<Z>() {}
    int getValue(void) const{
        return data;
    }

    friend ring<Z> operator+(ring<Z> a, ring<Z> b) {
        ring<Z> result(0);
        result.data = ((a.data + b.data) % Z);
        return result;
    }
    friend ring<Z> operator*(ring<Z> a, ring<Z> b) {
        return ((a.data * b.data) % Z);
    }
    
};



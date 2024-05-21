#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void incr(T &x) {
    ++x;
}

template <typename T, typename U>
void iter(T* array, unsigned int len, U ft) {
    for (unsigned int i = 0; i < len; ++i) {
        ft(array[i]);
    }
	std::cout << std::endl;
}

#endif
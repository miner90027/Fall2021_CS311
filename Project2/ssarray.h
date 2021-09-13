/*
 * SSArray.h
 * Aleks McCormick
 * 2021/09/10
 * Fall 2021 CS 311
 * The header file for a somewhat smart array template class
 */

#ifndef FALL2021_CS311_SSARRAY_H
#define FALL2021_CS311_SSARRAY_H

#include <cassert> // for assert
#include <ostream> // for std::ostream

/* Class Invariants:
 * _size >= 0
 *
 */

template<typename Type>
class SSArray{
public:
    SSArray();

    explicit SSArray(std::size_t size);

    explicit SSArray(std::size_t size, Type value);


    std::size_t size();

private:
    std::size_t _size;
    Type _value;
};


template<typename Type>
SSArray<Type>::SSArray():_size(8) {}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size):_size(size) {

}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size, Type value):_size(size) {

}

template<typename Type>
std::size_t SSArray<Type>::size() {
    return _size;
}

#endif //FALL2021_CS311_SSARRAY_H

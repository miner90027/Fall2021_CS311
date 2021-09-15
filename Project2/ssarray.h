/*
 * SSArray.h
 * Aleks McCormick
 * 2021/09/10
 * Fall 2021 CS 311
 * The header file for a somewhat smart array template class
 * 		No source file - template class
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

	template<typename Type>
	friend bool operator==(const SSArray<Type> &lhs, const SSArray<Type> &rhs);
	template<typename Type>
	friend bool operator<(const SSArray<Type> &lhs, const SSArray<Type> &rhs);
	
public:
    SSArray();

    explicit SSArray(std::size_t size);

    explicit SSArray(std::size_t size, Type value);

	~SSArray();

    std::size_t size();
	std::size_t* begin();
	std::size_t* end();

    Type& operator[](int location);

    using size_type = std::size_t;
    using value_type = Type;

private:
	Type* _array;
    std::size_t _size;
};


template<typename Type>
SSArray<Type>::SSArray():SSArray(8) {}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size):_size(size) {
	_array = new Type[_size];
}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size, Type value):_size(size){

    _array = new Type[_size];
    for(int i = 0; i < _size; ++i){
        _array[i] = value;
    }

}

template<typename Type>
SSArray<Type>::~SSArray() {
	delete[] _array;
}


template<typename Type>
std::size_t SSArray<Type>::size() {
    return _size;
}

template<typename Type>
std::size_t *SSArray<Type>::begin() {
	return *_array[0];
}

template<typename Type>
std::size_t *SSArray<Type>::end() {
	return *_array[_size];
}

template<typename Type>
bool operator==(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return false;
}

template<typename Type>
bool operator<(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return false;
}

template<typename Type>
Type &SSArray<Type>::operator[](const int location) {
    return _array[location];
}




template<typename Type>
bool operator!=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(rhs == lhs);
}

template<typename Type>
bool operator>(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return rhs<lhs;
}

template<typename Type>
bool operator<=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return ! (rhs>lhs);
}

template<typename Type>
bool operator>=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return ! (rhs<lhs);
}

#endif //FALL2021_CS311_SSARRAY_H

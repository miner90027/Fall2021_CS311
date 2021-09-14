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
 * size_type >= 0
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

	Type value_type;
    std::size_t size_type{};

private:
	Type _array;
};


template<typename Type>
SSArray<Type>::SSArray():SSArray(8) {}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size):size_type(size) {
	_array = new Type[size_type];
}

template<typename Type>
SSArray<Type>::SSArray(std::size_t size, Type value):size_type(size) {
	_array = new Type[size_type][value];
}

template<typename Type>
SSArray<Type>::~SSArray() {
	delete[] _array;
}


template<typename Type>
std::size_t SSArray<Type>::size() {
    return size_type;
}

template<typename Type>
std::size_t *SSArray<Type>::begin() {
	return &_array;
}

template<typename Type>
std::size_t *SSArray<Type>::end() {
	return &size_type;
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

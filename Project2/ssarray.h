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

#include <cassert>   // for assert
#include <cstddef>   // for std::size_t
#include <utility>   // for std::copy
#include <algorithm> // for std::swap

/* Class Invariants:
 * _size > 0
 * _array is a valid ptr
 */

template<typename Type>
class SSArray{

public:

	using size_type = std::size_t;
	using value_type = Type;

	// default cotr
    SSArray():SSArray(8){}

	// ctor that takes a size param
    explicit SSArray(size_type size):_size(size) {
		_array = new Type[_size];
	}

	// ctor that takes a size & value
    explicit SSArray(size_type size, Type value):_size(size){
		_array = new Type[_size];
		for(int i = 0; i < _size; ++i){
			_array[i] = value;
		}
	}

	// copy ctor
    SSArray(const SSArray<Type> & other){
		_size = other.size();
		_array = new Type[_size];
		std::copy(other.begin(), other.end(), begin());
	}

	// copy assignment operator
    SSArray & operator=(const SSArray<Type> & rhs){
		SSArray<Type> rhsCopy(rhs);
		mswap(rhsCopy);
		return *this;
	}

	//move ctor
    SSArray(SSArray<Type> && other) noexcept  {
		_size = other._size;
		_array = other._array;

		other._size = 0;
		other._array = nullptr;
	}

	// move assignment operator
    SSArray & operator=(SSArray<Type> && rhs) noexcept{
		mswap(rhs);
		return *this;
	}

	// dctor
	~SSArray(){
		delete[] _array;
	}

    [[nodiscard]] size_type size() const &{
		return _size;
	}

	Type* begin(){
		return _array;
	}

	Type* end(){
		return _array + _size;
	}

	const Type* begin() const {
		return _array;
	}

	const Type* end() const{
		return _array + _size;
	}

    Type& operator[](int location) const{
		return _array[location];
	}

private:

	void mswap(SSArray<Type> & other) noexcept{
		std::swap(_array, other._array);
		std::swap(_size, other._size);
	}

	Type* _array;
    size_type _size{};
};


template<typename Type>
bool operator==(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
    bool ret = lhs.size()== rhs.size();
    for (std::size_t i = 0;ret && i < lhs.size(); ++i) {
            ret = (lhs[i] == rhs[i]);
    }
    return ret;
}

template<typename Type>
bool operator<(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	for(std::size_t i = 0; i < rhs.size() && i < lhs.size() ; ++i)
	{
		if(lhs[i] < rhs[i]) return true;
		else if (rhs[i] < lhs[i]) return false;
	}

	return rhs.size() > lhs.size();
}

template<typename Type>
bool operator!=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(rhs == lhs);
}

template<typename Type>
bool operator>(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return rhs < lhs;
}

template<typename Type>
bool operator<=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(lhs > rhs);
}

template<typename Type>
bool operator>=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(lhs < rhs);
}

#endif //FALL2021_CS311_SSARRAY_H

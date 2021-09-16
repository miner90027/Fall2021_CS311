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

public:
	// default cotr
    SSArray():SSArray(8){}

	// ctor that takes a size param
    explicit SSArray(std::size_t size):_size(size) {
		_array = new Type[_size];
	}

	// ctor that takes a size & value
    explicit SSArray(std::size_t size, Type value):_size(size){
		_array = new Type[_size];
		for(int i = 0; i < _size; ++i){
			_array[i] = value;
		}
	}

	// copy ctor
    SSArray(const SSArray & other){
		_size = other.size();
		_array = new Type[_size];
		for(int i = 0; i < _size; ++i){
			_array[i] = other[i];
		}
	}

	// copy assignment operator
    SSArray & operator=(const SSArray & rhs){
		return *this;
	}

	//move ctor
    SSArray(SSArray && other) noexcept  {

	}

	// move assignment operator
    SSArray & operator=(SSArray && other) noexcept{
		return *this;
	}

	// dctor
	~SSArray(){
		delete[] _array;
	}

    std::size_t size() const &{
		return _size;
	}
	Type* begin()const &{
		return &_array[0];
	}
	Type* end() const &{
		return &_array[_size];
	}

    Type& operator[](int location) const{
		return _array[location];
	}

    using size_type = std::size_t;
    using value_type = Type;

private:
	Type* _array;
    std::size_t _size{};
};


template<typename Type>
bool operator==(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
    bool ret = lhs.size()== rhs.size();
    for (int i = 0;ret && i < lhs.size(); ++i) {
            ret = (lhs[i] == rhs[i]);
    }
    return ret;
}

template<typename Type>
bool operator<(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
    bool ret = true;
    for(int i = 0; ret && i < lhs.size() ; ++i)
    {
        ret = (lhs[i] < rhs[i]);
    }
    return ret;
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
	return !(rhs<lhs);
}

template<typename Type>
bool operator>=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return ! (rhs>lhs);
}

#endif //FALL2021_CS311_SSARRAY_H

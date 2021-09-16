/*
 * SSArray.h
 * Aleks McCormick
 * 2021/09/10
 * Fall 2021 CS 311
 * The header file for a somewhat smart array template class
 */

#ifndef FALL2021_CS311_SSARRAY_H
#define FALL2021_CS311_SSARRAY_H

#include <cassert>   // for assert
#include <cstddef>   // for std::size_t
#include <utility>   // for std::copy
#include <algorithm> // for std::swap

/*
 * Class Invariants:
 * _size >= 0
 * _array is a valid ptr that can be deleted
 */

template<typename Type>
class SSArray{
public:
	/******************************************/
	/***         Public Member Types        ***/
	/******************************************/

	// member type for the size
	using size_type = std::size_t;

	//member type for the data type
	using value_type = Type;

	/******************************************/
	/***         Basic Constructors         ***/
	/******************************************/

	// default cotr
    SSArray():SSArray(8){}

	// ctor that takes a size param
    explicit SSArray(size_type size):_size(size) {
		assert(_size >= 0);
		_array = new Type[_size];
	}

	// ctor that takes a size & value
    explicit SSArray(size_type size, Type value):_size(size){
		assert(_size >= 0);
		_array = new Type[_size];
		for(int i = 0; i < _size; ++i){
			_array[i] = value;
		}
	}

	/******************************************/
	/***            The Big Five:           ***/
	/***      Move & Copy Ctors & Dctor     ***/
	/******************************************/

	// copy ctor
    SSArray(const SSArray<Type> & other){
		assert(_size >= 0);
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

	// move ctor
    SSArray(SSArray<Type> && other) noexcept  {
		assert(_size >= 0);
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

	/******************************************/
	/***      Public Member Functions       ***/
	/******************************************/

	// size()
	// returns the size of the object
    [[nodiscard]] size_type size() const &{
		return _size;
	}

	// operator[]
	// returns the value in the array at the specified location
	// Precondition:
	// 	- location must be a value between 0 & size - 1
	Type& operator[](int location) const{
		assert(location >= 0 && location < _size);
		return _array[location];
	}

	/******************************************/
	/***     Iterator Member Functions      ***/
	/******************************************/

	// begin()
	// returns a pointer to the beginning of the array
	Type* begin(){
		return _array;
	}

	// end()
	// returns a pointer to the end of the array
	Type* end(){
		return _array + _size;
	}

	// const begin()
	// returns a pointer to the beginning of the array
	// can be used with const objects
	const Type* begin() const {
		return _array;
	}

	// const end()
	// returns a pointer to the end of the array
	// can be used with const objects
	const Type* end() const{
		return _array + _size;
	}

private:

	/******************************************/
	/***      Private Member Functions      ***/
	/******************************************/

	// mswap()
	// used to swap the member variables for 2 SSArray objects
	// Not visible to the client code
	void mswap(SSArray<Type> & other) noexcept{
		std::swap(_array, other._array);
		std::swap(_size, other._size);
	}

	/******************************************/
	/***      Private Member Variables      ***/
	/******************************************/

	// stores the pointer to the beginning of the array
	Type* _array;

	// stores the size of the array
    size_type _size;
};

/******************************************/
/***     Global Boolean Operators       ***/
/******************************************/

// operator==
// returns true when all items in SSArray objects are equal
// and their size is equal
// Preconditions:
//  - Both objects must be of the same type
template<typename Type>
bool operator==(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
    bool ret = lhs.size()== rhs.size();
    for (std::size_t i = 0;ret && i < lhs.size(); ++i) {
            ret = (lhs[i] == rhs[i]);
    }
    return ret;
}

// operator<
// returns true when all items in the first SSArray object is
//  less than the other or if the size of the first object is < the other
//	Preconditions:
//   - Both objects must be of the same type
template<typename Type>
bool operator<(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	for(std::size_t i = 0; i < rhs.size() && i < lhs.size() ; ++i)
	{
		if(lhs[i] < rhs[i]) return true;
		else if (rhs[i] < lhs[i]) return false;
	}

	return rhs.size() > lhs.size();
}


// operator!=
// returns the opposite of operator==
// Preconditions:
//  - Both objects must be of the same type
template<typename Type>
bool operator!=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(rhs == lhs);
}


// operator>
// returns the opposite of operator<
// Preconditions:
//  - Both objects must be of the same type
template<typename Type>
bool operator>(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return rhs < lhs;
}


// operator<=
// returns true if the first object isn't greater than the second
// Preconditions:
//  - Both objects must be of the same type
template<typename Type>
bool operator<=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(lhs > rhs);
}


// operator>=
// returns true if the first object isn't less than the second
// Preconditions:
//  - Both objects must be of the same type
template<typename Type>
bool operator>=(const SSArray<Type> &lhs, const SSArray<Type> &rhs) {
	return !(lhs < rhs);
}

#endif //FALL2021_CS311_SSARRAY_H
/*
 * fstarray.h
 * VERSION 6
 * Glenn G. Chappell
 * Started: 2021-10-12
 * Updated: 2021-10-20
 *
 * VERSION 7
 * Aleks McCormick & Chuluunbat Purev
 * Updated: 2021-10-27
 *
 * For CS 311 Fall 2021
 * Header for template class FSTArray
 * Frightfully smart array of typename<UserSpecifiedType>
 * Project 5
 */

/*
 * History:
 * - v1:
 *   - Bare-bones only, does not compile. Header & source files,
 *     #ifndef, #include, empty class definition.
 * - v2:
 *   - Add member types value_type, size_type, iterator, const_iterator.
 *   - Add dummy versions (at least) of all member functions, including
 *     dummy return statements for non-void functions. Package compiles.
 *   - Add data members.
 *   - Add class invariants.
 *   - Write (untested versions of) the following member functions:
 *     default ctor, ctor from size (these two are single func), dctor,
 *     op[], size, empty, begin, end, push_back, pop_back.
 * - v3:
 *   - Document exception-safety guarantees for most functions.
 *   - Write copy ctor.
 * - v4:
 *   - Revise class invariants to allow for _data being nullptr if _size
 *     is zero.
 *   - Revise ctor from size, copy ctor accordingly.
 *   - Write move ctor.
 *   - Mark various functions as noexcept.
 * - v5:
 *   - Move func defs to source file: copy & move ops, resize, insert,
 *     erase, swap.
 * - v6:
 *   - Add _capacity data member.
 *   - Revise class invariants & ctors accordingly.
 *   - Add constant DEFAULT_CAP and use it in setting the capacity in
 *     default ctor/ctor from size.
 * - v7:
 *   - Converted to template class; moved func defs from source file to header
 *   - Implemented resize member function to make array resizeable
 *   - Implemented swap member function
 *   - Implemented the insert and erase member functions to make the
 *     array size modifiable through the addition or deletion of stored data
 *   - Updated and verified exception safety where necessary
 */

#ifndef FALL2021_CS311_FSTARRAY_H
#define FALL2021_CS311_FSTARRAY_H

#include <cstddef>      // For std::size_t
#include <algorithm>    // For std::max & std::copy
#include <utility>      // For std::move
#include <iterator>     // For std::distance


/******************************************/
/***              FSTArray               ***/
/***          Class definition          ***/
/******************************************/

// class FSTArray
// Frightfully Smart Array of typename<UserSpecifiedType>.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.

template <typename Type>
class FSTArray {

/******************************************/
/***        Public Member Types         ***/
/******************************************/
public:

    // value_type: type of data items
    using value_type = Type;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

/******************************************/
/***       Internal Use Constants       ***/
/******************************************/
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

/******************************************/
/***         Ctors, Op=, Dctor          ***/
/******************************************/
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit FSTArray(size_type size=0)
        :_capacity(std::max(size, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(size),
         _data(_capacity == 0 ? nullptr
                              : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    FSTArray(const FSTArray<Type> & other)
            :_capacity(other._capacity),
             _size(other.size()),
             _data(other._capacity == 0 ? nullptr
                                        : new value_type[other._capacity])
    {
        try{
        std::copy(other.begin(), other.end(), begin()); // This could throw; error passed to client code
        }
        catch(...){
            delete [] _data; // delete allocated ptr if error thrown
            throw;
        }
    }

    // Move ctor,
    // No-Throw Guarantee
    FSTArray(FSTArray<Type> && other) noexcept
            :_capacity(other._capacity),
             _size(other._size),
             _data(other._data)
    {
		other._capacity = 0;
		other._size = 0;
		other._data = nullptr;
    }

    // Copy assignment operator
    // No-Throw Guarantee
    FSTArray & operator=(const FSTArray<Type> & other)
    {
        auto obj = other;   
        swap(obj); // Cannot throw
        return *this;
    }

    // Move assignment operator
    // No-Throw Guarantee
    FSTArray & operator=(FSTArray<Type> && other) noexcept
    {
        swap(other); // Cannot throw
        return *this; 
    }

    // Dctor
    // No-Throw Guarantee
    ~FSTArray()
    {
        delete [] _data;
    }

/******************************************/
/***     General Public Operators       ***/
/******************************************/
public:

    // operator[] - non-const & const
    // Pre:
    //  	0 <= index < _size
    //  	_data cannot be null,
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }

/******************************************/
/***     General Public Functions       ***/
/******************************************/
public:

    // size
    // No-Throw Guarantee
    [[nodiscard]] size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    [[nodiscard]] bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // Preconditions:
    //  	newSize >= 0
	// Note - The resize function can only throw when incrementing _size
	//  		causes the function to increment _capacity; decrementing the _size
	//  		does not change the _capacity.
	//  		Therefore, resize can only throw if newSize >= _capacity.
    // Strong Guarantee
    void resize(size_type newSize)
    {
		// Resize if _size is not >= _capacity
        if(newSize < _capacity){
			// If newSize is < 0 then set the _size to 0
			//  	_size gets newSize otherwise
			(newSize < 0 ? _size = 0 : _size = newSize);
            return; // Exit the function
        }
		// Reallocate & copy if _size is >= _capacity

        size_type newCapacity = _capacity; // Set a local variable to the current capacity

		// Double the newCapacity while it is smaller or equal to the newSize
        while(newCapacity <= newSize) {
            newCapacity *= 2;
        }

		// Create new value_type ptr
		// Initialize the temp ptr to have a size of newCapacity
		auto temp = new value_type[newCapacity]; // This could throw; Error passed to client code
		// If the above new throws, then ptr is never created and doesn't need to be deleted

        try{
			// Copy all the values from the current array into the temp array
            std::copy(begin(), end(), temp); // This could throw
        }
        catch(...){ // Catch error and delete allocated ptr
            delete [] temp;
            throw; // Pass error to client code
        }

        delete [] _data; // deallocate the original array

		// Re-assign all old values to new values
		// AKA - Commit changes
        _data = temp;
        _capacity = newCapacity;
        _size = newSize;
		// Cannot delete temp because ownership of the ptr was passed to _data
    }

    // insert
    // Strong Guarantee
    iterator insert(iterator pos,
                    const value_type & item)
    {
		// Find the index indicated by the passed iterator
        size_type index = size_type(std::distance(begin(), pos)); // This does not throw

		// Call resize function to increase the size by 1
        resize(size()+1); // Could possibly throw, in which case no change is made

		// Shift all the data stored in the array from the index to the end
		//  	over by 1
		// Uses move for efficiency, and because it is noexcept
        std::move(begin() + index, end(), begin()+index + 1); // Cannot throw

        _data[index] = item; // Replace the old data stored at index with the new data

        return begin() + index; // Return the pointer to the item inserted
    }

    // erase
    // No-throw Guarantee
    iterator erase(iterator pos)
    {
		// Shift all the values in front of the given pos
		//  	down one; overwriting the value at pos
        std::move(pos+1, end(), pos); // Cannot throw

        resize(_size-1); // Resize last to erase the last index
		// The above implementation of the resize function cannot throw
		//  	the resize function can only throw when incrementing _size
		//  	causes the function to increment _capacity; decrementing the _size
		//  	does not change the _capacity. Therefore, resize can only throw if 
		//  	newSize >= _capacity, which will never happen when decrementing. 

		// Return the pos of the deleted item which was replaced with the item after it
		// Returns end if the item removed was the last item in the array
        return pos; 
    }

    // push_back
    // Strong Guarantee
    void push_back(const value_type & item)
    {
		// Insert an item at the end of the array
        insert(end(), item); // Can throw; error passed to client code, no changes made
    }

    // pop_back
    // No-throw Guarantee
    void pop_back()
    {
		// Erase the last item in the array
        erase(end()-1); // Cannot throw
    }

    // swap
    // No-Throw Guarantee
    void swap(FSTArray & other) noexcept
    {
		// Use std::swap to exchange the data members of *this with other
        std::swap(_data, other._data);
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
    }

/******************************************/
/***           Data Members             ***/
/******************************************/
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class FSTArray


#endif  //#ifndef FALL2021_CS311_FSTARRAY_H
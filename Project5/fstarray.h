/*
 * fsarray.h
 * VERSION 6
 * Glenn G. Chappell
 * Started: 2021-10-12
 * Updated: 2021-10-20
 *
 * Finished by:
 * Aleks McCormick & Purev
 * 2021/10/22
 *
 * For CS 311 Fall 2021
 * Header for class FSTArray
 * Frightfully smart array of int
 * Preliminary to Project 5
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
 */

#ifndef FILE_FSARRAY_H_INCLUDED
#define FILE_FSARRAY_H_INCLUDED

#include <cstddef>      // For std::size_t
#include <algorithm>    // For std::max & std::copy


/******************************************/
/***              FSTArray               ***/
/***          Class definition          ***/
/******************************************/

// class FSTArray
// Frightfully Smart Array of int.
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
        std::copy(other.begin(), other.end(), begin());
        // The above call to std::copy does not throw, since it copies int
        // values. But if value_type is changed, then the call may throw, in
        // which case this copy ctor may need to be rewritten.
    };

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
    // ??? Guarantee
    FSTArray & operator=(const FSTArray<Type> & other)
    {
        // TODO: WRITE THIS!!!>
        return *this; // DUMMY
    }

    // Move assignment operator
    // No-Throw Guarantee
    FSTArray & operator=(FSTArray<Type> && other) noexcept
    {
        // TODO: WRITE THIS!!!
        return *this; // DUMMY
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
    //     ???
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
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
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
    // ??? Guarantee
    void resize(size_type newsize)
    {
        // TODO: WRITE THIS!!!
    }

    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item)
    {
        // TODO: WRITE THIS!!!
        return begin();  // DUMMY
    }

    // erase
    // ??? Guarantee
    iterator erase(iterator pos)
    {
        // TODO: WRITE THIS!!!
        return begin();  // DUMMY
    }

    // push_back
    // ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(FSTArray & other) noexcept
    {
        // TODO: WRITE THIS!!!
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


#endif  //#ifndef FILE_FSARRAY_H_INCLUDED


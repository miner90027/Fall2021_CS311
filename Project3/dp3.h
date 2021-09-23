/*
 * dp3.h
 * Aleks McCormick
 * 202/09/17
 * Fall 2021 CS 311
 * Header file for Project 3 functions
 * Modified from the Skeletal file created by Prof. Chappell
 */

#ifndef FALL2021_CS311_DP3_H
#define FALL2021_CS311_DP3_H

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range
#include <algorithm>   // For std::unique && std::sort
#include <iterator>    // For std::distance


/******************************************/
/***      Non-template Functions        ***/
/******************************************/

// gcd() -> Implementation in source file
// Calculates the greatest common divisor of 2 ints
// Function is recursive
// Does Not Throw
int gcd(int a, int b);

// didItThrow() -> Implementation in source file
// Used to determine if a function passed to it trows an exception
// Sets a passed bool variable accordingly
// Re-throws the error that the passed function throws
// Preconditions:
//  * ff is a valid function that can be called without parameters
void didItThrow(const std::function<void()> & ff, bool & threw);

/******************************************/
/***        Template Functions          ***/
/******************************************/

// lookup()
// Finds and returns the value stored in the nth item in the
//    singly linked list, LLNode
// Preconditions:
//  * head is a valid pointer to the beginning of a linked list
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index){

	// Verify that the LLNode isn't empty
	// Throw an out_of_range exception stating that the list is empty
    if(!head) {
		throw std::out_of_range("The given LLNode is empty. Therefore the given index is out of range.");
	}

	// create a variable for storing the size of the list & initialize to 0
    std::size_t size = 0;

	// create a temporary pointer to the next item in the list
	auto* temp = head->_next;

	// to determine the size of the list
	//   iterate through each item in the list using the temp pointer
	//   & increment the size counter
    while(temp) {
		temp = temp->_next;
		++size;
	}

	// verify that the given index is valid place in the list
	// throw an out_of_range error if the index < 0 or if it is larger than the list
    if(index < 0 || index > size)
        throw std::out_of_range("The given index is not within the range of the given LLNode.");

	// Iterate through each item in the list until the specified index
    for(std::size_t i = 0;i < index; ++i){
        head = head->_next;
    }

	// delete the temporary pointer
	delete temp;

	// return the data stored in the nth item of the list
    return head->_data;
}

// uniqueCount()
// counts the number of unique items in a specified range
// Does Not Throw
// Preconditions:
// 	* first & last are both valid iterators
//  * first & last are random access iterators
template <typename RAIter>
std::size_t uniqueCount(RAIter first, RAIter last) {
	// sort the range of data
	std::sort(first, last);

	// remove all duplicates and create a pointer to the new end of the range
	auto uLast = std::unique(first, last);

	// return the size of the range without the duplicates
    return std::distance(first, uLast);
}

#endif  //FALL2021_CS311_DP3_H


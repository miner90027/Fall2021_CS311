/*
 * dp3.h
 * Aleks McCormick
 * 202/09/17
 * Fall 2021 CS 311
 * Header file for Project 3 functions
 */

#ifndef FALL2021_CS311_DP3_H
#define FALL2021_CS311_DP3_H

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range
#include <algorithm>   // For std::unique && std::sort
#include <iterator>    // For std::distance

template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index){

    if(!head) {
		throw std::out_of_range("The given LLNode is empty.");
	}

    std::size_t size = 0;

	auto* temp = head->_next;

    while(temp) {
		temp = temp->_next;
		++size;
	}

    if(index < 0 || index > size)
        throw std::out_of_range("The given index is not within the range of the LLNode.");

    for(std::size_t i = 0; head && i < index; ++i){
        head = head->_next;
    }

	delete temp;
    return head->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff, bool & threw);


template <typename RAIter>
std::size_t uniqueCount(RAIter first, RAIter last) {

	std::sort(first, last);
	auto uLast = std::unique(first, last);
	std::size_t count = std::distance(first, uLast);

    return count;
}


// Implementation in source file
int gcd(int a, int b);


#endif  //FALL2021_CS311_DP3_H


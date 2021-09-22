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


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index){

    if(head->_next == nullptr)
        throw std::out_of_range("The given LLNode is empty.");

    std::size_t size = 0;
    auto* temp = head->_next;

    while(temp != nullptr){
        ++size;
        temp = temp->_next;
    }

    if(index < 0 || index > size)
        throw std::out_of_range("The given index is not within the range of the LLNode.");


    for(int i = 0; i <= index; ++i){
        head = head->_next;
    }

    return head->_data; // Dummy return
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff, bool & threw);


template <typename RAIter>
std::size_t uniqueCount(RAIter first, RAIter last) {
    return std::size_t(42);  // Dummy return
    // TODO: WRITE THIS!!!
}


// Implementation in source file
int gcd(int a, int b);


#endif  //FALL2021_CS311_DP3_H


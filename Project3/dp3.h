/*
 * dp3.cpp
 * Aleks McCormick
 * 202/09/17
 * Fall 2021 CS 311
 * Source file for Project 3 functions
 */

#ifndef FALL2021_CS311_DP3_H
#define FALL2021_CS311_DP3_H

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index){
    return ValueType();  // Dummy return
    // TODO: WRITE THIS!!!
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


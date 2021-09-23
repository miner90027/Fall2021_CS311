/*
 * dp3.cpp
 * Aleks McCormick
 * 202/09/17
 * Fall 2021 CS 311
 * Source file for Project 3 functions
 * Modified from the Skeletal file created by Prof. Chappell
 */

#include "dp3.h"       // For Project 3 prototypes & templates
#include <functional>  // For std::function

// didItThrow()
// Used to determine if a function passed to it trows an exception
// Sets a passed bool variable accordingly
// Re-throws the error that the passed function throws
// Preconditions:
//  * ff is a valid function that can be called without parameters
void didItThrow(const std::function<void()> & ff, bool & threw) {
	try{
		// set the bool to false
		threw = false;

		// run the function
		ff();
	}
	// catch all errors
	catch(...)
	{
		// set the bool to true
		threw = true;

		// re-throw the caught error
		throw;
	}
}

// gcd()
// Calculates the greatest common divisor of 2 ints
// Function is recursive
// Does Not Throw
int gcd(int a, int b) {
    // base case
    if (a == 0)
        return b;

    // check if a > b & run again swapping values
    if(a > b)
        return gcd(b,a);

    // return the remainder of b/a and a
    return gcd(b % a, a);
}

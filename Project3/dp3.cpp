/*
 * dp3.cpp
 * Aleks McCormick
 * 202/09/17
 * Fall 2021 CS 311
 * Source file for Project 3 functions
 */

#include "dp3.h"       // For Project 3 prototypes & templates
#include <functional>  // For std::function
using std::function;


void didItThrow(const function<void()> & ff, bool & threw) {
	try{
		threw = false;
		ff();
	}
	catch(...)
	{
		threw = true;
		throw;
	}
}


int gcd(int a, int b) {
    // bse case
    if (a == 0)
        return b;
    // check if a > b & run again swapping values
    if(a > b)
        return gcd(b,a);

    // return the remainder of b/a and a
    return gcd(b % a, a);
}

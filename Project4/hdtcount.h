/*
 * hdtcount.h
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * Header file for Project 4
 */

#ifndef FALL2021_CS311_HDTCOUNT_H
#define FALL2021_CS311_HDTCOUNT_H

#include <vector> // For std::vector

/******************************************/
/***         Global Member Types        ***/
/******************************************/
//define the data type of the board as a 2D-vector
using boardType = std::vector<std::vector<int>>;

// Define container class to contain all the functions
// Invariants: None
class HDTCounter{
	/******************************************/
	/***      Public Friend Functions       ***/
	/******************************************/
public:
	// hdtCount()
	// Wrapper function that Returns the total possible number of ways dominoes can be placed
	//  on a board of a given siz given that there are 2 places on the board that do not exist
	// The only public facing function for the class; made friend to be accessed by client
	// Function does not throw
	// Preconditions:
	//  	both dim_x & dim_y must be >= 0
	//   	all the forbid_x variables must fall within the values between 0 & x
	//   	all the forbid_y variables must fall within the values between 0 & y
	friend int hdtCount(int dim_x, int dim_y, int forbid1_x,
						int forbid1_y, int forbid2_x, int forbid2_y);

	/******************************************/
	/***            The Big Five:           ***/
	/***          Move & Copy Ctors         ***/
	/***        Default Ctor & Dctor        ***/
	/******************************************/
	//default the basic ctor & dctor
	HDTCounter() = default;
	~HDTCounter() = default;
	
	// make all copy & move ctors private
	// class cannot be copied or moved
	// delete all copy & move ctors

	// Copy ctor
	HDTCounter(const HDTCounter &) = delete;
	// Move ctor
	HDTCounter(HDTCounter &&) = delete;
	// Copy assignment operator
	HDTCounter & operator=(const HDTCounter &) = delete;
	// Move assignment operator
	HDTCounter & operator=(HDTCounter &&) = delete;
	
	/******************************************/
	/***     Private Member Functions       ***/
	/******************************************/
private:
	// hdtCount_recurse()
	// Recursive workhorse function for hdtCount()
	// Returns the total number of possible solutions for a given board
	// Function does not throw
	// Preconditions:
	//		Board must be a valid 2D vector of ints
	//		Squares left must be a value of 0 or greater
	int hdtCount_recurse(boardType & board, int squaresLeft);

	// checkHorizontal()
	// Returns if a domino can be placed horizontally on the given board at the given
	//  coordinates
	// Function does not throw
	// Preconditions:
	//		board must be a valid boardType
	static bool checkHorizontal(const boardType & board, unsigned int x,unsigned int y);
	
	static bool checkVertical(const boardType & board, unsigned int x, unsigned int y);
	
	static bool checkRange(const boardType & board, unsigned int x, unsigned int y);
};

#endif //FALL2021_CS311_HDTCOUNT_H

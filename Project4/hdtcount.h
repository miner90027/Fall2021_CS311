/*
 * hdtcount.h
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
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
	// Preconditions:
	//  	both dim_x & dim_y must be >= 0
	//   	all the forbid_x variables must fall within the values between 0 & x
	//   	all the forbid_y variables must fall within the values between 0 & y
	friend int hdtCount(unsigned int dim_x, unsigned int dim_y, unsigned int forbid1_x,
						unsigned int forbid1_y, unsigned int forbid2_x, unsigned int forbid2_y);

	/******************************************/
	/***     Private Member Functions       ***/
	/******************************************/
private:

	int hdtCount_recurse(boardType & board, unsigned int squaresLeft);
	bool checkHorizontal(const boardType & board, unsigned int x, unsigned int y);
	bool checkVertical(const boardType & board, unsigned int x, unsigned int y);
	bool checkRange(const boardType & board, unsigned int x, unsigned int y);
};

#endif //FALL2021_CS311_HDTCOUNT_H

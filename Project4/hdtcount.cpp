/*
 * hdtcount.cpp
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * Source file for HDTCount
 */

#include "hdtcount.h"

/******************************************/
/***      Public Friend Functions       ***/
/******************************************/

// hdtCount()
// Wrapper function that Returns the total possible number of ways dominoes can be placed
//  on a board of a given siz given that there are 2 places on the board that do not exist
// The only public facing function for the class; made friend to be accessed by client
// Preconditions:
//  	both dim_x & dim_y must be >= 1
//  	all the forbid_x variables must fall within the values between 0 & dim_x
//  	all the forbid_y variables must fall within the values between 0 & dim_y
int hdtCount(int dim_x, int dim_y, int forbid1_x, int forbid1_y,
			 int forbid2_x, int forbid2_y){

     // create the board using the x & y values given
     // default all spaces to 0
     boardType board(dim_x, std::vector<int>(dim_y, 0));

     // Set both of the forbidden spaces = to 1
     board[forbid1_x][forbid1_y] = 1;
     board[forbid2_x][forbid2_y] = 1;

     // Create a HDTCounter object
     // Must be done in order to call the recursive workhorse function
     HDTCounter a;

     //call and return the value returned by the workhorse function
    return a.hdtCount_recurse(board,(dim_y * dim_x) - 2);
}

/******************************************/
/***     Private Member Functions       ***/
/******************************************/

// hdtCount_recurse()
// Recursive workhorse function for hdtCount()
// Returns the total number of possible solutions for a given board
// Not visible to client code
// Function does not throw
// Preconditions:
//  	Board must be a valid 2D vector of ints
//  	Squares left must be a value between 0 & the total number of squares
//  	   that can be held in the board - the 2 forbidden spaces
int HDTCounter::hdtCount_recurse(boardType & board, int squaresLeft) {

    // Base case
    // if the number of squares remaining is 0
    //   then return 1
    if (squaresLeft == 0){
        return 1;
    }

    // initialize the solutions to zero
    int solutions = 0;

    //iterate through all the values in the board
    for(unsigned int x = 0; x < board.size(); ++x) {
        for (unsigned int y = 0; y < board[0].size(); ++y) {

            // Check to see if the current space is not empty
            // If true, then continue through the loop
            // If false, check everything
            // Causes loop to iterate until the current space is empty
            if (board[x][y] == 1)
                continue;

            // Check the next vertical space on the board
            if (checkVertical(board, x, y)) {
                // Place a domino vertically on the board
                board[x][y] = 1;
                board[x][y + 1] = 1;

                // Make recursive call adding the result to solutions
                // Decrement the number of squares remaining by 2 (the size of a domino)
                solutions += hdtCount_recurse(board, squaresLeft -2);

                // Remove the domino from the board
                board[x][y] = 0;
                board[x][y + 1] = 0;
            }

            // Place a domino horizontally on the board
            if (checkHorizontal(board, x, y)) {
                // Place a domino horizontally on the board
                board[x][y] = 1;
                board[x + 1][y] = 1;

                // Make recursive call adding the result to solutions
                // Decrement the number of squares remaining by 2 (the size of a domino)
                solutions += hdtCount_recurse(board, squaresLeft-2);

                // Remove the domino from the board
                board[x][y] = 0;
                board[x + 1][y] = 0;
            }

            // After making both recursive calls, exit the loops by setting the iterators
            //   to the size of the board they represent
            x = board.size();
            y = board[0].size();
        }
    }

    // Return the total number of full solutions
    return solutions;
}

// checkHorizontal()
// Returns if a domino can be placed horizontally on the given board at the given
//  coordinates
// Not visible to client code
// Function does not throw
// Preconditions:
//  	board must be a valid boardType
bool HDTCounter::checkHorizontal(const boardType & board, unsigned int x, unsigned int y){
    // Check to make sure that the next space horizontally on the board is a valid space
    // Check to make sure that the next space horizontally on the board is empty
	return checkRange(board, x +1, y) && (board[x+1][y] == 0);
}

// checkVertical()
// Returns true if a domino can be placed vertically on the given board at the given
//  coordinates
// Not visible to client code
// Function does not throw
// Preconditions:
//  	board must be a valid boardType
bool HDTCounter::checkVertical(const boardType & board, unsigned int x, unsigned int y){
    // Check to make sure that the next space vertically on the board is a valid space
    // Check to make sure that the next space vertically on the board is empty
    return checkRange(board, x, y+1) && (board[x][y+1] == 0);
}

// checkRange()
// Returns true if the given x, y coordinates are within the range of the given board
// Not visible to client code
// Function does not throw
// Preconditions:
//  	board must be a valid boardType
bool HDTCounter::checkRange(const boardType & board, unsigned int x,unsigned int y){
    // Verify that the x & y values are within the range of the given board
	return (x < board.size() && y < board[0].size());
}
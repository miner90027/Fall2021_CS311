/*
 * hdtcount.cpp
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
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
//  	both dim_x & dim_y must be >= 0
//   	all the forbid_x variables must fall within the values between 0 & x
//   	all the forbid_y variables must fall within the values between 0 & y
int hdtCount(int dim_x, int dim_y, int forbid1_x, int forbid1_y,
			 int forbid2_x, int forbid2_y){

	 // create the board using the x & y values given
	 // default all spaces to 0
     boardType board(dim_x, std::vector<int>(dim_y, 0));

	 // Set both of the forbidden spaces = to 1
     board[forbid1_x][forbid1_y] = 1;
     board[forbid2_x][forbid2_y] = 1;

	 //create a HDTCounter object
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
// Function does not throw
// Preconditions:
//		Board must be a valid 2D vector of ints
//		Squares left must be a value of 0 or greater
int HDTCounter::hdtCount_recurse(boardType & board, int squaresLeft) {


	if (squaresLeft == 0){
		return 1;
	}
	int solutions = 0;

		for(unsigned int x = 0; x < board.size(); ++x) {
			for (unsigned int y = 0; y < board[0].size(); ++y) {

				if (board[x][y] == 1)
					continue;

				if (checkVertical(board, x, y)) {
					board[x][y] = 1;
					board[x][y + 1] = 1;

					solutions += hdtCount_recurse(board, squaresLeft -2);

					board[x][y] = 0;
					board[x][y + 1] = 0;

				}

				if (checkHorizontal(board, x, y)) {
					board[x][y] = 1;
					board[x + 1][y] = 1;

					solutions += hdtCount_recurse(board, squaresLeft-2);

					board[x][y] = 0;
					board[x + 1][y] = 0;
				}

				x = board.size();
				y = board[0].size();
			}
		}

	return solutions;

}

// checkHorizontal()
// Returns if a domino can be placed horizontally on the given board at the given
//  coordinates
// Function does not throw
// Preconditions:
//		board must be a valid boardType
bool HDTCounter::checkHorizontal(const boardType & board, unsigned int x, unsigned int y){
	return checkRange(board, x +1, y) && (board[x+1][y] == 0);
}

bool HDTCounter::checkVertical(const boardType & board, unsigned int x, unsigned int y){
    return checkRange(board, x, y+1) && (board[x][y+1] == 0);
}

bool HDTCounter::checkRange(const boardType & board, unsigned int x,unsigned int y){
	return (x < board.size() && y < board[0].size());
}
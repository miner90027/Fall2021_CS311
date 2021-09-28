/*
 * hdtcount.cpp
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#include "hdtcount.h"
#include <iostream>

int hdtCount(unsigned int dim_x, unsigned int dim_y, unsigned int forbid1_x, unsigned int forbid1_y,
			 unsigned int forbid2_x, unsigned int forbid2_y){

	if(dim_x == 1 && dim_y == 1) return 0;

     boardType board(dim_x, std::vector<int>(dim_y, 0));
     board[forbid1_x][forbid1_y] = 1;
     board[forbid2_x][forbid2_y] = 1;

return hdtCount_recurse(board, 0, 0,0,(dim_y * dim_x) - 2); // dummy return
}


int hdtCount_recurse(boardType & board,  int curr_x,  int curr_y, int partialSolutions, unsigned int squaresLeft){


	if(squaresLeft == 0)
		return 1;

	if(checkHorizontal(board, curr_x, curr_y)){
		squaresLeft -= 2;
		partialSolutions += hdtCount_recurse(board, curr_x+1, curr_y, partialSolutions, squaresLeft);
	}

	if(checkVertical(board, curr_x, curr_y)){
		squaresLeft -= 2;
		partialSolutions += hdtCount_recurse(board, curr_x, curr_y+1, partialSolutions, squaresLeft);
	}

    return partialSolutions; // dummy return
}

bool checkHorizontal(boardType & board, int x, int y){
	if(x < board.size() - 1 && y < board[0].size())
	{
		if(board[x+1][y] == 0)
			return true;
	}
	return false;
}

bool checkVertical(boardType & board, unsigned int x, unsigned int y){
	if(y < board[0].size() - 1 && x < board.size())
	{
		if(board[x][y + 1] == 0)
			return true;
	}
	return false;
}
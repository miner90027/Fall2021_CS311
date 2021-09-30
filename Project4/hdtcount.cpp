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

return hdtCount_recurse(board, 0, 0,(dim_y * dim_x) - 2); // dummy return
}


int hdtCount_recurse(boardType & board,  int curr_x,  int curr_y, unsigned int squaresLeft, int partialSolutions, int
solutions){


	if(squaresLeft == 0){
        return 1;
    }

    if(checkVertical(board, curr_x, curr_y)){
        squaresLeft -= 2;
        partialSolutions += hdtCount_recurse(board, curr_x, curr_y+1, squaresLeft, partialSolutions, solutions);

        if(checkHorizontal(board, curr_x, curr_y)) {
            squaresLeft -= 2;
            solutions += hdtCount_recurse(board, curr_x + 1, curr_y, squaresLeft, partialSolutions, solutions);
        }
    }

    return solutions; // dummy return
}

bool checkHorizontal(boardType & board, int x, int y){
	return checkRange(board, x +1, y) && (board[x][y] != 1 && board[x+1][y] == 0);
}

bool checkVertical(boardType & board, int x, int y){
    return checkRange(board, x, y+1) && (board[x][y] != 1 && board[x][y+1] == 0);
}

bool checkDomino(boardType & board, int x, int y) {
	return checkHorizontal(board, x, y) || checkVertical(board, x, y);
}

bool checkRange(boardType & board, int x, int y){
	return (x < board.size() && y < board[0].size());
}
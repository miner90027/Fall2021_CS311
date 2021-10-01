/*
 * hdtcount.cpp
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#include "hdtcount.h"

int hdtCount(unsigned int dim_x, unsigned int dim_y, unsigned int forbid1_x, unsigned int forbid1_y,
			 unsigned int forbid2_x, unsigned int forbid2_y){

	if(dim_x == 1 && dim_y == 1) return 0;

     boardType board(dim_x, std::vector<int>(dim_y, 0));
     board[forbid1_x][forbid1_y] = 1;
     board[forbid2_x][forbid2_y] = 1;

	 HDTCounter a;
return a.hdtCount_recurse(board,(dim_y * dim_x) - 2);
}


int HDTCounter::hdtCount_recurse(boardType & board, unsigned int squaresLeft) {


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

bool HDTCounter::checkHorizontal(const boardType & board, unsigned int x, unsigned int y){
	return checkRange(board, x +1, y) && (board[x+1][y] == 0);
}

bool HDTCounter::checkVertical(const boardType & board, unsigned int x, unsigned int y){
    return checkRange(board, x, y+1) && (board[x][y+1] == 0);
}

bool HDTCounter::checkRange(const boardType & board, unsigned int x, unsigned int y){
	return (x < board.size() && y < board[0].size());
}
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

return hdtCount_recurse(board,(dim_y * dim_x) - 2); // dummy return
}


int hdtCount_recurse(boardType & board, unsigned int squaresLeft) {

	//std::cout << "new recurse\n\tsquaresLeft: " << squaresLeft << std::endl;
	if (squaresLeft == 0){
		//std::cout << "Solutions: " << +1 << std::endl;
		return 1;
	}
	int solutions = 0;

		for(unsigned int x = 0; x < board.size(); ++x) {
			for (unsigned int y = 0; y < board[0].size(); ++y) {

				if (board[x][y] == 1)
					continue;

				if (checkVertical(board, x, y)) {
					//std::cout << "\t\tChecking Vertical..." << std::endl;
					board[x][y] = 1;
					board[x][y + 1] = 1;

					solutions += hdtCount_recurse(board, squaresLeft -2);

					board[x][y] = 0;
					board[x][y + 1] = 0;

				}

				if (checkHorizontal(board, x, y)) {
					//std::cout << "\t\tChecking Horizontal..." << std::endl;
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

	//std::cout << "\ttotal: " << solutions << std::endl;
	return solutions;

}

bool checkHorizontal(const boardType & board, unsigned int x, unsigned int y){
	return checkRange(board, x +1, y) && (board[x+1][y] == 0);
}

bool checkVertical(const boardType & board, unsigned int x, unsigned int y){
    return checkRange(board, x, y+1) && (board[x][y+1] == 0);
}

bool checkRange(const boardType & board, unsigned int x, unsigned int y){
	return (x < board.size() && y < board[0].size());
}
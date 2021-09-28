/*
 * hdtcount.cpp
 * Aleks McCormick
 * 2021/09/24
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#include "hdtcount.h"

int hdtCount(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y){
     boardType board(dim_x, std::vector<int>(dim_y, 0));
     board[forbid1_x][forbid1_y] = 1;
     board[forbid2_x][forbid2_y] = 1;

return hdtCount_recurse(board, 0); // dummy return
}


int hdtCount_recurse(boardType & board, int partialSolutions){
    return 1; // dummy return
}
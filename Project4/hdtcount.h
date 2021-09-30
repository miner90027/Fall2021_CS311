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

using boardType = std::vector<std::vector<int>>;
int hdtCount(unsigned int dim_x, unsigned int dim_y, unsigned int forbid1_x, unsigned int forbid1_y, unsigned int forbid2_x, unsigned int forbid2_y);

int hdtCount_recurse(boardType & board, int curr_x, int curr_y, unsigned int squaresLeft, int partialSolutions = 0, int
solutions = 0);
bool checkHorizontal(boardType & board, int x, int y);
bool checkVertical(boardType & board, int x, int y);

int checkDomino(boardType & board, int x, int y);
bool checkRange(boardType & board, int x, int y);

#endif //FALL2021_CS311_HDTCOUNT_H

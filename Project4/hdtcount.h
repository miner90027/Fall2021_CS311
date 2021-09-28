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

int hdtCount_recurse(boardType & board, unsigned int curr_x, unsigned int curr_y, int partialSolutions, unsigned int squaresLeft);
bool checkHorizontal(boardType & board, int x, int y);
bool checkVertical(boardType & board, unsigned int x, unsigned int y);

#endif //FALL2021_CS311_HDTCOUNT_H

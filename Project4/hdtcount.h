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
int hdtCount(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y);

int hdtCount_recurse(boardType & board, int partialSolutions);

#endif //FALL2021_CS311_HDTCOUNT_H

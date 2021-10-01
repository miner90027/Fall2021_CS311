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

class HDTCounter{
public:
	friend int hdtCount(unsigned int dim_x, unsigned int dim_y, unsigned int forbid1_x, unsigned int forbid1_y, unsigned int forbid2_x, unsigned int forbid2_y);

private:
	int hdtCount_recurse(boardType & board, unsigned int squaresLeft);
	bool checkHorizontal(const boardType & board, unsigned int x, unsigned int y);
	bool checkVertical(const boardType & board, unsigned int x, unsigned int y);
	bool checkRange(const boardType & board, unsigned int x, unsigned int y);
};

#endif //FALL2021_CS311_HDTCOUNT_H

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

int hdtCount_recurse(){
	return 0; // dummy return
}

std::vector<std::vector<int>> initBoard(int xParam, int yParam){
	std::vector<std::vector<int>> board(xParam, std::vector<int>(yParam));
	return board; // return the board
};

#endif //FALL2021_CS311_HDTCOUNT_H

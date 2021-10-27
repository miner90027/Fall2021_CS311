/*
 * FILE NAME
 * Aleks McCormick
 * YYYY/MM/DD
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#include <iostream>
#include "fstarray.h"

int main(){
	FSTArray<int> tst;
	for(int i = 0; i < 50; ++i){
		std::cout << "size: " << tst.size() << "  tst[i]: ";
		tst.push_back(i);
		std::cout << tst[i] << std::endl;
	}



    return 0;
}

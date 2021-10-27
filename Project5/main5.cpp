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
	FSTArray<int> fsf(100);
/*
    tst.resize(20);
    tst[19]= 200;
    std::cout << tst[19]<< std::endl;
*/
	for(int i = 0; i < 50; ++i){
		std::cout << "size: " << tst.size() << "  tst[i]: ";
		tst.push_back(i);
		//tst[i] = i;
		std::cout << tst[i] << std::endl;
	}

    /*
    fsf[20]= 30;
    std::cout << fsf[20] << std::endl;

	tst.swap(fsf);
    //tst[20]= 30;
    std::cout << tst[20] << std::endl;
     */
    return 0;
}

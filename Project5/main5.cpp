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

    //test resize
    /*
    tst.resize(200);
    for(std::size_t i = 0; i < tst.size(); ++i){
        tst[i] = i;
        std::cout << "index: " << i << " value: " << tst[i] << std::endl;
    }

    std::cout << "size: " << tst.size() << std::endl;
*/
    //test insert
/*
    for(int i = 0; i < 50; ++i){
        std::cout << "size: " << tst.size() << "  tst[i]: ";
        tst.push_back(i);
        //tst[i] = i;
        std::cout << tst[i] << std::endl;
    }
*/

    //test swap function
    /*
    fsf[20]= 30;
    std::cout << fsf[20] << std::endl;

	tst.swap(fsf);
    //tst[20]= 30;
    std::cout << tst[20] << std::endl;
     */
    return 0;
}

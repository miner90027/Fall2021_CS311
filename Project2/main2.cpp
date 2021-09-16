//
// Created by aleks on 08/29/21.
//
#include <iostream>
#include "ssarray.h"

int main() {
	SSArray<int> def(5, 20);
    SSArray<int> oth(5,19);
    std::cout << (oth != def) << std::endl;
	return 0;
}

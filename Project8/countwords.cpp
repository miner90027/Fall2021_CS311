/*
 * countwords.cpp
 * Aleks McCormick
 * 2021/11/22
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


int main(){

	string fileName;

	cout << "Please enter a file path." << endl;
	getline(cin, fileName);

	cout << "Input: " << fileName << endl;
	return 0;
}
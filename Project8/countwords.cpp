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
using std::ifstream;


int main(){

	// String to store the user input file name
	string fileName;

	cout << "Please enter the file path for the file you wish to open.\nFile path:";
	getline(cin, fileName);

	ifstream fileIn(fileName);
	if(!fileIn){
		cout << "The input file could not be opened. Please specify a file to open, my need to specify the file path." << endl;
		return -1;
	}

	cout << "Input: " << fileName << endl;
	return 0;
}
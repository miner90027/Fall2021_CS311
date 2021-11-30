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
	ifstream fileIn(fileName);

	// Receive the file path from the user
	// Verify that the file can be found.
	// Prompt the user for a file until a valid file is input
	do{
		cout << "Please enter the file path for the file you wish to open.\nFile path:";
		getline(cin, fileName);
		fileIn = std::ifstream (fileName);

		if(!fileIn)
			cout << "The input file could not be found. "
					"Please specify a file to open, my need to specify the absolute file path." << endl;
	}while(!fileIn);

	cout << "Input: " << fileName << endl;
	return 0;
}
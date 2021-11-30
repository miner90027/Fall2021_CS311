/*
 * countwords.cpp
 * Aleks McCormick
 * 2021/11/22
 * Fall 2021 CS 311
 * Project 8 Exercise A
 * Counts the number of words in a file
 */

#include <iostream> 	// For std::cout , std::cin , std::endl;
#include <fstream>  	// For std::ifstream
#include <string>   	// For std::string , std::getline
#include <map>      	// For std::map

// using statements for the library functions used for printing
//  	I am too lazy to write out "std::" before every cout or endl
using std::cout;
using std::cin;
using std::endl;


int main(){

	// String to store the user input file name
	std::string fileName;
	std::ifstream fileIn(fileName);

	// Prompt the user for a file until a valid file is input
	do{
		// Receive the file path from the user
		cout << "Please enter the file path for the file you wish to open.\nFile path:";
		std::getline(cin, fileName);
		fileIn = std::ifstream (fileName);

		// Verify that the file can be found.
		if(!fileIn)
			cout << "The input file could not be found or opened. "
					"Please specify a file to open, you my need to specify the absolute file path." << endl;
	}while(!fileIn);

	// map to store the words in the file
	std::map<std::string, int> data;
	// Temp string to store each word wile iterating over the file
	std::string word;

	// Get each word from the file and store it in the string
	while(fileIn >> word){
		// Store the string in the map & increment the associated int
		++data[word];
	}

	// Print out the total number of words by getting the size of the map
	cout << "Number of distinct words: " << data.size() << endl << endl;

	// Preform an in-order traversal of the map printing each Key-Value pair in
	//  	lexicographic order
	for(const auto & kvp: data){
		cout << kvp.first << ": " << kvp.second << endl;
	}

	// Close the file
	fileIn.close();
	return 0;
}
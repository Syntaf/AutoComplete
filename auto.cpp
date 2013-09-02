//program structure runs as follows:
// Linux distribution --  ./auto wordList inputFile
// Windows distribution -- auto wordList inputFile
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include "autoCompleteConfig.h"

bool openGood(std::ifstream&);
void readDictionary(std::ifstream&, std::vector<std::string>&);

typedef std::vector<std::string>::iterator vecIter

int main(int argc, char* argv[])
{
	std::ifstream wordFile, inFile;
	std::vector<std::string> dictionary;
	//cmake build version(as specified in cmake header
	std::cout << "VERSION " << MAJOR << "." << MINOR << std::endl;
	//if the user enters no args
	if(argc == 1) {
		std::cout << "Usage: ./auto <wordList> <inputFile>" << std::endl;
		return 1;
	//testing for retarded user
	} else if(argc == 2) {
		std::cout << "Error, must provide inputFile" << std::endl;
		return 1;
	
	//open dictionary text file
	if(!openGood(wordFile)) {
		std::cout << "Error, dictionary file could not be opened\n";
		return 1;
	}
	//now open input file with the words we need to complete
	if(!openGood(inFile)) {
		std::cout << "Error, input file could not be opened\n";
		return 1;
	}	
	//grab dictionary words and store them in vector		
	readDictionary(wordFile, dictionary);

	

	
	
	return 0;
}

// test if file passed to function is valid and can be read
bool openGood(std::ifstream& file)
{
	//...
}

// read data from file into vector, I feel a vector is much more
// optimized for standard data types than say, a linked list. open
// for debate though, a hash table might also be a viable data structure
void readDictionary(char*, std::vector<std::string> &vec)
{
	//...
}

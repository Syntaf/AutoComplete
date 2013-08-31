//program structure runs as follows:
// Linux distribution --  ./auto wordList inputFile
// Windows distribution -- auto wordList inputFile
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <vector>
#include "autoCompleteConfig.h"

bool fileGood(char*);
void readDictionary(char*, std::vector<std::string>&);

int main(int argc, char* argv[])
{
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
	}
	
	/*		TO BE IMPLEMENTED
	//test if the user entered correct files
	if(!fileGood(argv[1])) {
		std::cout << "Error, wordList file cannot be loaded" << std::endl;
		return 1;
	}
	if(!fileGood(argv[2])) {
		std::cout << "Error, inputFile cannot be loaded" << std::endl;
	}
	*/

	dictionary.push_back("dictionary vector");
	for(auto i = dictionary.begin(); i != dictionary.end(); ++i) {
		std::cout << *i << std::endl;
	}
	
		

	return 0;
}

// test if file passed to function is valid and can be read
bool fileGood(char*)
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

// program structure runs as follows:
// Linux distribution --  ./auto wordList inputFile
// Windows distribution -- auto wordList inputFile
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include "autoCompleteConfig.h"
#include <queue>

bool openGood(std::ifstream&, char* argv);
void readDictionary(std::ifstream&, std::vector<std::string>&, char* argv);
void readInput(std::ifstream&, std::vector<std::string>&, char* argv);

typedef std::vector<std::string>::iterator vecIter;

int main(int argc, char* argv[])
{

	std::cout << std::left;	
	std::ifstream wordFile, inFile;
	std::queue<std::string> matchingCase;
	std::vector<std::string> dictionary, input;
	// cmake build version(as specified in cmake header
	std::cout << "VERSION " << MAJOR << "." << MINOR << std::endl;
	// if the user enters no args
	if(argc == 1) {
		std::cout << "Usage: ./auto <wordList> <inputFile>" << std::endl;
		return 1;
	// testing for retarded user
	} else if(argc == 2) {
		std::cout << "Error, must provide inputFile" << std::endl;
		return 1;
	}	
	// open dictionary text file
	if(!openGood(wordFile,argv[1])) {
		std::cout << "Error, dictionary file could not be opened\n";
		return 1;
	}
	// now open input file with the words we need to complete
	if(!openGood(inFile,argv[2])) {
		std::cout << "Error, input file could not be opened\n";
		return 1;
	}

#ifdef USE_INPUT	
	readDictionary(wordFile, dictionary,argv[1]);
	readInput(inFile, input,argv[2]);
#else
	//--------------------------------------------------------------------
	std::cout << "USE_INPUT SET TO OFF....GENERATING DICTIONARY\n\n";
	input.push_back("par");
	dictionary.push_back("testing");
	dictionary.push_back("gone");
	dictionary.push_back("parachute");
	dictionary.push_back("imaginary");
	dictionary.push_back("paraglide");
	//--------------------------------------------------------------------
#endif	
	for(int k = 0; k < input.size(); ++k) {
	int len = (input.at(k)).length();
	// truth false variable to end out while loop
	bool found = false;
	// create an iterator pointing to the first element of the dictionary
	vecIter i = dictionary.begin();
	// this while loop is not complete, a condition needs to be made
	while(!found && i != dictionary.end()) {
		// take a substring the dictionary word(the length is dependent on
		// the input value) and compare
		if( (*i).substr(0,len) == input.at(k) ) {
			// so a word is found! push onto the queue
			matchingCase.push(*i);
		}
		// move iterator to next element of data
		++i; 	
	}

	}
	int counter = 0;
	// print contents of queue	
	while(!matchingCase.empty()) {
		//make sure to display our queue in the order we found them
		std::cout << std::setw(15) << matchingCase.front();
		//pop off the front of the queue
		matchingCase.pop();
		if(counter % 5 == 0)
			std::cout << std::endl;
		counter++;
	}
	std::cout << std::endl;

	return 0;
}


// test if file passed to function is valid and can be read
bool openGood(std::ifstream& file, char* argv)
{
	file.open(argv);
	if (file.is_open()){
	//if file can be opened
	return true;
	//return true

	} if (!file.is_open()){
	//file cannot be open
	return false;
	//return false
	}else{
	std::cout << "Crash." << std::endl;
	return false;
	}
}

// read data from file into vector, I feel a vector is much more
// optimized for standard data types than say, a linked list. open
// for debate though, a hash table might also be a viable data structure
void readDictionary(std::ifstream& inFile, std::vector<std::string>& vec, char* argv)
{
	std::string line;

	inFile >> line;
	vec.push_back(line);
	while(inFile) {
		inFile >> line;
		vec.push_back(line);
	}

}

void readInput(std::ifstream& inFile, std::vector<std::string> &vec, char* argv)
{
	std::string line;
	inFile >> line;
	vec.push_back(line);
	while(inFile){
		inFile >> line;
		vec.push_back(line);
	}

}

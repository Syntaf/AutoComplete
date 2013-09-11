// program structure runs as follows:
// Linux distribution --  ./auto wordList inputFile
// Windows distribution -- auto wordList inputFile
#include <iostream>
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
bool search(std::vector<std::string>&, std::vector<std::string>&,
	    std::queue<std::string>&);

typedef std::vector<std::string>::iterator vecIter;

int main(int argc, char* argv[])
{
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
	if(!openGood(wordFile, argv[1])) {
		std::cout << "Error, dictionary file could not be opened\n";
		return 1;
	}
	// now open input file with the words we need to complete
	if(!openGood(inFile, argv[2])) {
		std::cout << "Error, input file could not be opened\n";
		return 1;
	}

#ifdef USE_INPUT	
	readDictionary(wordFile, dictionary, argv[1]);
	readInput(inFile, input, argv[2]);
#else
	//--------------------------------------------------------------------
	input.push_back("par");
	dictionary.push_back("apple");
	dictionary.push_back("and");
	dictionary.push_back("batman");
	dictionary.push_back("gone");
	dictionary.push_back("imaginary");
	dictionary.push_back("parachute");
	dictionary.push_back("paraglide");
	dictionary.push_back("testing");
	dictionary.push_back("zoo");
	//--------------------------------------------------------------------
#endif	

	//check to make sure list is sorted!
	//--check, ok done

	if(!search(dictionary, input, matchingCase)) {
		std::cout << "no words have been found matching...." << std::endl;
		return 1;
	}

	// print contents of queue	
	while(!matchingCase.empty()) {
		//make sure to display our queue in the order we found them
		std::cout << matchingCase.front() << std::endl;
		//pop off the front of the queue
		matchingCase.pop();
	}

	return 0;
}

// test if file passed to function is valid and can be read
bool openGood(std::ifstream& file, char* argv)
{
	file.open(argv);
	if (file.is_open()){
	std::cout << "File was opened in openGood." << std::endl;
	//if file can be opened
	return true;
	//return true

	} if (!file.is_open()){
	std::cout << "File could not be opened in openGood." << std::endl;
	//file cannot be open
	return false;
	//return false
}	else{
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

//same as read dictionary, but for our input file
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
//search function uses a binary search algorithm on a given vector. It is important
//to note that the string MUST be sorted before being passed into binary search
//or you are going to have a very bad time. Currently only finds one word but must
//be developed to catch all similar words
bool search(std::vector<std::string>& dict, std::vector<std::string>& in,
	    std::queue<std::string>& out)
{
	int first=0, last= dict.size() -1;
	while(first <= last)
	{
		int middle = (first+last)/2;

		std::string sub = (dict.at(middle)).substr(0,in.at(0).length());
		int comp = (in.at(0)).compare(sub);
		//if comp returns 0(found word matching case)
		if(comp == 0){
			out.push(dict.at(middle));
			return true;
		}
		//if not, take top half
		else if (comp > 0)
			first = middle + 1;
		//else go with the lower half
		else
			last = middle - 1;
	}
	return false;
}


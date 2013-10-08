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
int search(std::vector<std::string>&, std::string);

typedef std::vector<std::string>::iterator vecIter;

int main(int argc, char* argv[])
{
	//word and input file, output file and data structures to hold information
	std::ifstream wordFile, inFile;
	std::ofstream out;
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

	readDictionary(wordFile, dictionary, argv[1]);
	readInput(inFile, input, argv[2]);

	//condition: word file MUST be sorted
	//--check, ok done
	out.open("out.dat");
	//for each element in our "find word" vector
	for(int i = 0; i < input.size()-1; i++){
		std::vector<std::string>::const_iterator pos = std::lower_bound(
			dictionary.begin(),
			dictionary.end(),
			input.at(i));
		for( ; pos != dictionary.end(); ++pos) {
			if(pos->compare(0,(input.at(i)).size(),input.at(i)) == 0)
			{
				matchingCase.push(*pos);
			}
			else break;
		}	
	}

	// print contents of queue, counter for format
	int counter = 0;	
	while(!matchingCase.empty()) {
		//make sure to display our queue in the order we found them
		std::cout << std::setw(15) << matchingCase.front();
		out << std::setw(15) << matchingCase.front();
		//pop off the front of the queue
		matchingCase.pop();
		counter++;
		//format counter for displaying, 5 per line
		if(counter % 5 == 0) {
			std::cout << std::endl;
			out << std::endl;
		}
	}
	std::cout << std::endl;
	out.close();
	return 0;
}

// test if file passed to function is valid and can be read
bool openGood(std::ifstream& file, char* argv)
{
	file.open(argv);
	if (!file.is_open()){
		//file cannot be opened, error out
		std::cerr << "FILE ERROR...CANNOT BE OPENED" << std::endl;
		return false;
	}
	//file cannot be open
	return true;
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

/* OUTDATED BY STD::LOWER_BOUND
//search function uses a binary search algorithm on a given vector. It is important
//to note that the string MUST be sorted before being passed into binary search
//or you are going to have a very bad time. Currently finds index for first match
//and return int for main loop to start search from that point
int search(std::vector<std::string>& dict, std::string in)
{	
		//for each element in the input vector
		//find all possible word matches and push onto the queue
		int first=0, last= dict.size() -1;
		while(first <= last)
		{
			int middle = (first+last)/2;
			std::string sub = (dict.at(middle)).substr(0,in.length());
			int comp = in.compare(sub);
			//if comp returns 0(found word matching case)
			if(comp == 0) {
				return middle;		
			}
			//if not, take top half
			else if (comp > 0)
				first = middle + 1;
			//else go with the lower half
			else
				last = middle - 1;
		}
	//word not found... return failure
	return -1;
}
*/

AutoComplete
============

Code competition description:
The code challenge problem is as follows: You must build an autocomplete program in 
one of these languages: Java, C++, Ruby, Python, or PHP. The metric for winning the 
competition is going to be based on time to complete, so optimization is important. 
This means that if your program executes our input set faster than anyone else you 
win. Just to forewarn you though, our input set is going to be exceedingly large.

NOTE TO READER: this readme file is in progress, because of this there is some deprecated instructions
		. ignore all lines starting with '**' currently!

COMPILING

This program uses a cmake build system currently in development, so some special 
instructions are needed in order to build.

	LINUX SYSTEMS
		**DEPRECATED []Make sure you first off have a designated compiler that supports C++11
		**DEPRECATED []Know your c++11 flags needed
				clang requires '-std=c++11'
				gnu requires   '-std=c++0x'
		(RECOMMENDED) create a seperate directory in the repository for the building
		of the program, this allows all of the left over cmake files to be kept seperate
		from the repository.
		
		Now cd into your corresponding directory and type 'cmake' (This currently will
		not work, READ BELOW) followed by the location of CMakeLists.txt, if you did 
		not create a build directory(I hate you) just 'cmake' is suffice, but commonly 
		if build is a subdirectory you would type 'cmake ..' to let the system know your
		CMakeLists.txt file is just outside of the directory.

		After cmake finishes doing it's buissness, all you need to do is type 'make' and
		your program should be compiled and located in your 'bin' directory in the main
		repo. This is where it should end
	
	** DEPRECATED NOTE CURRENTLY*****
		You're going to need to add a few extra things in your cmake, at the moment i'm
		trying to write a cmake build system that supports c++11, but it's still in the
		making. you will need to add these two things before the file location:
				-Your compiler(if you choose not to use the default)
				-The C++11 compile flags
		
		An example execution of cmake using clang and c++11 would be:

				: cd build
				: cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS=-std=c++11 ..

		WINDOWS SYSTEMS
			[]Fuck windows

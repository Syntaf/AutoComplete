AutoComplete
============

Code competition description:
The code challenge problem is as follows: You must build an autocomplete program in 
one of these languages: Java, C++, Ruby, Python, or PHP. The metric for winning the 
competition is going to be based on time to complete, so optimization is important. 
This means that if your program executes our input set faster than anyone else you 
win. Just to forewarn you though, our input set is going to be exceedingly large.


COMPILING


	LINUX SYSTEMS
		(IMPORTANT)  create a seperate directory in the repository for the building
		of the program, this allows all of the left over cmake files to be kept seperate
		from the repository.
		
		[] change into your build directory that you created above
		[] build the makefiles using cmake, make sure to specify the location of the
		   CMakeLists.txt (in this case it should just be in the directory below)
		[] type 'make' and watch the program build! the executables location should be
		   in the BIN folder

		an example build of the program might be:
			user@ubuntu:~/AutoComplete$ mkdir build
			user@ubuntu:~/AutoComplete$ cd build
			user@ubuntu:~/AutoComplete/build$ cmake ..
			user@ubuntu:~/AutoComplete/build$ make
			user@ubuntu:~/AutoComplete/build$ cd .. && cd bin
			user@ubuntu:~/AutoComplete/bin$ ./auto test.dat test2.dat

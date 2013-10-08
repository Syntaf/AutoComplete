AutoComplete
============
Program designed to give all possible word options to a set of characters given to the program
via files.

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

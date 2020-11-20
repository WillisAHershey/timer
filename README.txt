Willis A. Hershey
WillisAHershey@gmail.com

Simple command-line timer for POSIX systems.

Assuming you have gcc installed and sudoing privileges, a simple 'sudo make install' should get you up and running

Use by typing timer fololowed by some recognizable command and any arguments necessary i.e.

~/$ timer command arg1 arg2 ...

Timer will pass your command and all arguments to the system command parser and time how long it takes for the command to complete, then print the time

If you don't have sudoing privileges, 'make' will build the program, and you'll have to make sure its properly referenced by directory in order for the command parser to find it and run it

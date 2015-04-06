# Author: TJ Maynes
# File: Makefile

CFLAGS = -Wall -o
PROGRAM = main

main:
	g++ main.cpp $(CFLAGS) $(PROGRAM)

clean:
	rm -f $(PROGRAM)

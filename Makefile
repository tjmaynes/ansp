# Author: TJ Maynes
# File: Makefile

CFLAGS = -Wall -o
PROGRAM = main

main:
	g++ main.cpp $(CFLAGS) $(PROGRAM)

test:
	gdb ./main

clean:
	rm -f $(PROGRAM)

# Author: TJ Maynes
# File: Makefile

CFLAGS = -Wall -o
PROGRAM = main

main:
	g++ main.cpp $(CFLAGS) $(PROGRAM)

run:
	./main > output.txt

test:
	./test.sh

clean:
	rm -f $(PROGRAM)

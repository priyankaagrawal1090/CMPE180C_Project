# *****************************************************
# Variables to control Makefile operation 
CC = g++
CFLAGS = -pthread -std=c++14

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cc sort.h main.h test.h
	$(CC) $(CFLAGS) -c main.cc

clean:
	rm -rf main main.o
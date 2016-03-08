CC=g++
SOURCES=*.cc */*.cc */*/*.cc
EXEC=Grandmaster
CFLAGS=-std=c++11 -Wall
all: 
		$(CC) $(SOURCES) -o $(EXEC) $(CFLAGS)

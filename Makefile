CC=g++
SOURCES=*.cc */*.cc */*/*.cc
EXEC=Grandmaster
CFLAGS=-std=c++11
all: 
		$(CC) $(SOURCES) -o $(EXEC) $(CFLAGS)

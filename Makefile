CC = g++

SOURCES = main.cpp Vector.cpp

all:
	$(CC) $(SOURCES) -o main

run:
	@./main

clean:
	@rm -rf *.o main
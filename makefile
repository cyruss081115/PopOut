TGT = play
CC = g++
CFLAGS = -Wall -std=c++17
DIR = ./PopOut/

$(TGT): $(DIR)main.cpp $(DIR)PopOut.cpp
	$(CC) $(CFLAGS) $(DIR)main.cpp $(DIR)PopOut.cpp -o $(TGT)

.PHONY: clean
clean:
	rm -f $(TGT)
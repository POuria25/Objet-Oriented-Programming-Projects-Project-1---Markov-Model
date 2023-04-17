# Tools & flags
CC=g++
CFLAGS=--std=c++17 -Wall -Wextra
LD=g++
LDFLAGS=

# Files
EXEC=markov
MODULES=main.cpp markov_model.cpp
OBJECTS=main.o markov_model.o
.PHONY: all markov
all: $(EXEC)
	./markov 2 english.txt french.txt italian.txt spanish.txt --- test_english1.txt test_english2.txt test_english3.txt test_french1.txt test_french2.txt test_french3.txt test_german1.txt test_german2.txt test_german3.txt  test_spanish1.txt test_spanish2.txt test_spanish3.txt test_italian1.txt test_italian2.txt test_italian3.txt

markov: $(OBJECTS)
		$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)
		
main.o: main.cpp
		$(CC) -c main.cpp -o main.o $(CFLAGS)

markov_model.o: markov_model.cpp
		$(CC) -c markov_model.cpp -o markov_model.o $(CFLAGS)


clean:
		rm -f *.o $(EXEC) *~

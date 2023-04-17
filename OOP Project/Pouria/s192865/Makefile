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
	./$(EXEC) 2 materials/training/english.txt materials/training/french.txt materials/training/german.txt materials/training/italian.txt materials/training/spanish.txt --- materials/tests/test_english1.txt materials/tests/test_french1.txt materials/tests/test_german1.txt materials/tests/test_italian1.txt materials/tests/test_spanish1.txt

markov: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)
		
main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(CFLAGS)

markov_model.o: markov_model.cpp
	$(CC) -c markov_model.cpp -o markov_model.o $(CFLAGS)


clean:
	rm -f *.o $(EXEC) *~

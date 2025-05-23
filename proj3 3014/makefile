SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++14 -Wall -g
RM=rm -rf
HEADERS=${wildcard *.hpp}

.PHONY: clean

# Target rules
main: main.o patient.o text-menu-app.o patients.o
	$(CXX) -o $@ $^

test: test.o patient.o patients.o
	$(CXX) -o $@ $^
	./test

# General compilation rules
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Rule to test run your code with the exact same input used in the sample run
test-run: main
	echo -e "1\n2\nLorelei Saad\nJohn Smith\n24\nM\nmale\nMale\n3\n1\n1\n4\n" | ./main

clean:
	$(RM) *.o main test-all *.gc* *.dSYM

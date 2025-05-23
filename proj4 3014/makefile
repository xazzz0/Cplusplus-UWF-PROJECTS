SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++14 -Wall -g
RM=rm -rf
OUTPUTS=output.txt test-output.txt

.PHONY: clean

# Target rules
main: main.o patient.o text-menu-app.o patients.o
	$(CXX) -o $@ $^

test-all: test.o patient.o patients.o
	$(CXX) -o $@ $^
	./test-all

# General compilation rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Rule to test run your code with the exact same input used in the sample run
test-run: main
	echo -e "not-exist.txt\npatients.txt\n1\n2\n-1\n4\n2\nJohn Smith\n17\nM\nMale\n1\n3\noutput.txt\n4\n" | ./main

clean:
	$(RM) *.o main test-all *.gc* *.dSYM $(OUTPUTS)

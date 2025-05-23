#########################################################
#                                                       #
#     Prof. Blackthorn's Simple Makefile Template       #
#                                                       #
#  Description:                                         #
#    - Compiles source files listed in SOURCES using    #
#      g++ with C++17 standard.                         #
#    - Outputs an executable named TARGET.              #
#                                                       #
#  Usage:                                               #
#    - "make" or "make all" to compile and run the code.#
#    - "make clean" to remove the executable and        #
#      temporary swap files, clear the terminal,        #
#      and display the directory listing.               #
#                                                       #
#  Note: Update the SOURCES variable as needed.         #
#########################################################

CXX       = g++
CXXFLAGS  = -std=c++17 -Wall
SOURCES   = Character.cpp
TARGET    = main

TEST_SOURCES = test_suite.cpp Character.cpp
TEST_TARGET = test

all: $(TARGET)

$(TARGET): $(SOURCES)
	@$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
	@ls

$(TEST_TARGET): $(TEST_SOURCES)
	@$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)
	@ls

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@find . -type f -name "*.sw[klmnop]" -delete
	@clear
	@ls


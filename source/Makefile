# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Include directories
INCLUDES = -Iinclude/

# Source files
SOURCES = $(wildcard *.cpp)

# Executable name
EXEC = search

# Rules
all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(EXEC) $(SFMLFLAGS)

clean:
	rm -f $(EXEC)


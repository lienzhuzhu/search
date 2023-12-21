# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Include directories
INCLUDES = -Iinclude/ -I/opt/homebrew/include/

LINKFLAGS = -L/opt/homebrew/lib
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = $(wildcard *.cpp)

# Executable name
EXEC = search

# Rules
all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(EXEC) $(LINKFLAGS) $(SFMLFLAGS)

clean:
	rm -f $(EXEC)


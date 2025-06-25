# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable name
TARGET = hello_world

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run clean 
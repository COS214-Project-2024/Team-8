# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source files - including dependencies
SOURCES = Main.cpp \
         Government.cpp \
         Policies.cpp \
         EconomicPolicies.cpp \
         PublicServicesPolicies.cpp \
         Command.cpp \
         Citizen.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = government

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
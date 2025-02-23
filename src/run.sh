#!/bin/bash

# Output filename
OUTPUT="program"

# Check if main.cpp exists
if [ ! -f "main.cpp" ]; then
    echo "Error: main.cpp not found in current directory"
    exit 1
fi

clear

# Compile the program
echo "Compiling main.cpp..."
if clang++ main.cpp -o $OUTPUT -std=c++20 -Wall -Wextra; then
    echo "Compilation successful!"
    
    # Make the program executable
    chmod +x $OUTPUT
    
    # Run the program
    echo -e "\nRunning the program:\n"
    ./$OUTPUT
    
    # Clean up
    rm $OUTPUT
else
    echo "Compilation failed!"
    exit 1
fi

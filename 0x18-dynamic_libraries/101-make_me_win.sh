#!/bin/bash

# Compile the custom shared library
gcc -shared -fPIC -o libwin.so win.c

# Set LD_PRELOAD to the path of the custom shared library
export LD_PRELOAD=$PWD/libwin.so

# Run the gm program with the desired numbers
./gm 9 8 10 24 75 9

# Clean up the shared library
rm libwin.so

#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -C -fPIC *.c
gcc -shared -o liball.so *.o

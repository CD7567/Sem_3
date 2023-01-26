#!bin/bash

# Script to compare run time of std::printf and syscall::write:

gcc time_sys.c -o sys
gcc time_std.c -o std

printf "Time of std::printf:\n\n"

time ./std

printf "\n\nTime of syscall::write:\n\n"

time ./sys

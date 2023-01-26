#!/bin/bash

# Script to execute syscall_intro

gcc intro.c -o intro

printf "Syscall trace of syscall_intro.c:\n\n\n"

strace ./intro


printf "\n\nActual output of syscall_intro.c:\n\n\n"

./intro

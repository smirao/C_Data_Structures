#!/bin/bash
GIVEN_PATH=~/Desktop/C_Data_Structures
gcc -lstdc++ "${GIVEN_PATH}/src/main.c" -o "${GIVEN_PATH}/bin/main" && "${GIVEN_PATH}/bin/main"
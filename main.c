#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a5.h"

int main(int argc, char ** argv){
    // exit condition
    if(argc != 2){
        return EXIT_FAILURE;
    }

    // variables
    int x; // x coordinate
    int y; // y coordinate
    int rad; // radius

    // opening file
    FILE * file = fopen(argv[1], 'r');

    // file error
    if(file == NULL){
        return EXIT_FAILURE;
    }
}
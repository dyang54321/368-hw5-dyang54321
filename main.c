#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "a5.h"

static int compare(const void * a, const void * b){
    return (((Node*)a)->x - ((Node*)b)->x);
}

int main(int argc, char ** argv){
    // exit condition
    if(argc != 2){
        return EXIT_FAILURE;
    }

    // file open
    FILE * file = fopen(argv[1], "r"); // file pointer

    // file error
    if(file == NULL){
        return EXIT_FAILURE;
    }

    // variables
    int i = 0; // init index
    int xp; // point x coordinate
    int yp; // point y coordinate
    int x; // center x coordinate
    int y; // center y coordinate
    int rad; // radius
    char temp[20]; // temporary storage for pts

    // finding number of points
    while(fgets(temp, sizeof(temp), file) != NULL){
        i++; // increment index
    }

    fseek(file, 0, SEEK_SET); // resetting file

    Node * pts = malloc(i * sizeof(Node)); // allocating i nodes for list

    i = 0; // resetting index back to zero

    // inserting nodes into list
    while(fscanf(file, "%d %d", &xp, &yp) == 2){
        // init
        Node new; // making new node
        new.x = xp; // x coord
        new.y = yp; // y coord
        new.left = NULL; // right link
        new.right = NULL; // left link

        pts[i] = new; // appending to list

        i++; // incrementing count
    }

    // sorting
    qsort(pts, i, sizeof(Node), compare);

    // creating tree
    Node * root = createTree(pts, i);

    // program
    while(scanf("%d %d %d", &x, &y, &rad) == 3){
        // x range
        int xlow = x - rad; // x lower limit
        int xhigh = x + rad; // y upper limit

        // count
        int num = count(root, xlow, xhigh, x, y, rad);

        // printing
        printf("%d\n", num);
    }

    // freeing memory
    free(pts);
    fclose(file);
}
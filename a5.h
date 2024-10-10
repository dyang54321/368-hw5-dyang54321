#ifndef A4_H
#define A4_H
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int x; // x coordinate
    int y; // y coordinate
    struct Node *left; // left node
    struct Node *right; // right node
} Node;

Node * createTree(Node * pts, int n);
Node * createTreeHelper(Node * pts, int start, int end);
int count(Node * root, int low, int high, int x, int y, int r);
int yCheck(Node * root, int x, int y, int r);

#endif
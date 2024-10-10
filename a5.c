#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "a5.h"

Node * createTree(Node * pts, int n){
    return createTreeHelper(pts, 0, n-1);
}

Node * createTreeHelper(Node * pts, int start, int end){
    // base case
    if(start > end){
        return NULL;
    }

    // midde
    int mid = start + (end - start) / 2;

    // root node
    Node * root = &pts[mid]; // create root node
    root->left = createTreeHelper(pts, start, mid - 1); // left subtree
    root->right = createTreeHelper(pts, mid + 1, end); // right subtree

    return root;
}

int count(Node * root, int low, int high, int x, int y, int r){
    // base case
    if(root == NULL){
        return 0;
    }

    // special case
    if(root->x == high && root->x == low){
        return yCheck(root, x, y, r);
    }

    // in range
    if(root->x <= high && root->x >= low){
        return yCheck(root, x, y, r) + count(root->left, low, high, x, y, r) + count(root->right, low, high, x, y, r);
    }

    // less than range
    else if(root->x < low){
        return count(root->right, low, high, x, y, r);
    }

    // greater than range
    else{
        return count(root->left, low, high, x, y, r);
    }
}

int yCheck(Node * root, int x, int y, int r){
    // init
    int diff = sqrt((r * r) - ((root->x - x) * (root->x - x))); // difference up / down to y
    int ylow = y - diff; // y lower limit value
    int yhigh = y + diff; // y upper limit value

    // checking range
    if(root->y < ylow || root->y > yhigh){
        return 0;
    }

    return 1;
}

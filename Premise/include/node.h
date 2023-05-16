#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>

//gcc -E for preprocessor 
//gcc -s for just compilation 
//gcc -c for both compilation and assembler 
struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int);

#endif
#include <stdio.h> 
#include <stdlib.h> 

struct Node{
    char vartype[10];
    struct Node* next;
};

struct List{
    struct Node *val;
    struct List* next; 
};



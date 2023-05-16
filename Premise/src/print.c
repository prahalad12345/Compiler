#include "print.h"


void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
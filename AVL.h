//
// Created by ravi on 7/9/20.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include <iostream>

class node{
public:
    int key;
    node* left;
    node* right;
    int height;
    node(int k):key(k),left(NULL),right(NULL),height(1){}
};

class AVL {

public:

    node* insert(node* root, int val);
    void display(node* root);
private:
    node* rotateLeft(node* root);
    node* rotateRight(node* root);
};


#endif //AVL_AVL_H

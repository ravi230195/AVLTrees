#include <iostream>
#include "AVL.h"

int main() {
    std::cout << "--------AVL Tree-----" << std::endl;

    AVL* avl =  new AVL();
    node* root = NULL;
    root = avl->insert(root, 1);
    root = avl->insert(root, 2);
    root = avl->insert(root, 3);
    avl->display(root);
    root = avl->insert(root, 0);
    root = avl->insert(root, -1);
    root = avl->insert(root, -2);
    avl->display(root);
    root = avl->insert(root, 4);
    root = avl->insert(root, 6);
    root = avl->insert(root, 8);
    root = avl->insert(root, 9);
    root = avl->insert(root, 10);
    root = avl->insert(root, -8);
    avl->display(root);
    return 0;
}

//
// Created by ravi on 7/9/20.
//

#include "AVL.h"
#include <algorithm>
#include <queue>

using namespace std;

namespace {

    int height(node* root)
    {
        if(root == NULL)
            return 0;
        return root->height;
    }

    int setHeight(node* root)
    {
        return 1 + std::max(height(root->left), height(root->right));
    }

    int balance(node* root)
    {
        return height(root->left) - height(root->right);
    }

    template<typename T>
    void print(vector<vector<T>> A)
    {
        for(auto i:A) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

}

node* AVL::insert(node* root, int val) {
    if(root == NULL)
        return new node(val);
    else if(root->key > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    //Update the height
    root->height = setHeight(root);

    //check for the inbalance

    int nodeBalance = balance(root);
    if(nodeBalance > 1)
    {
        /*
         * Check For two case
         * 1. left left  -> right Rotation at root
         * 2. left right -> left Rotation at root->left and right rotation at root
         */

        // Left Left
        if(height(root->left->left) >= height(root->left->right))
            root = rotateRight(root);
        else {
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if(nodeBalance < -1)
    {
        /*
         * Check For two case
         * 1. Right Right  -> left Rotation at root
         * 2. Right left   -> right Rotation at root->right and left rotation at root
         */
        if(height(root->right->right) >= height(root->right->left))
            root = rotateLeft(root);
        else{
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

node* AVL::rotateLeft(node *root) {
    node* newNode = root->right;
    root->right = newNode->left;
    newNode->left = root;
    root->height = setHeight(root);
    newNode->height = setHeight(newNode);
    return newNode;
}

node* AVL::rotateRight(node *root) {
    node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = setHeight(root);
    newRoot->height = setHeight(newRoot);
    return newRoot;
}

void AVL::display(node *root) {
    cout<<"AVL DISPLAY \n";
    queue<node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        vector<int> res;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            res.push_back(q.front()->key);
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        ans.push_back(res);
    }
    print<int>(ans);
}
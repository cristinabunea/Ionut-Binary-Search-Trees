#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template <typename T>
class BinarySearchTree {
private:
    unique_ptr<TreeNode<T>> root;

public:
    // TreeNode<T>* currentNode = nullptr;
    
    void write(ostream & o) const {
        root->write(o);
    }

    TreeNode<T>* insert(const T & data) {
        if (!root){
            root = unique_ptr<TreeNode<T>>(new TreeNode<T>(data));
            return root.get();
        } else {
            bool inserting = true;  
            TreeNode<T>* currentNode = root.get();

            while(inserting) {
                inserting = false;
                if (data < currentNode->getData()) {
                    if (currentNode->leftChild) {
                        currentNode = currentNode->leftChild.get();
                        inserting = true;
                    } else {
                        TreeNode<T> * newNode = new TreeNode<T>(data);
                        currentNode->setLeftChild(newNode);
                        return newNode;
                    }
                } else if (currentNode->getData() < data ) {
                    if (currentNode->rightChild) {
                        currentNode = currentNode->rightChild.get();
                        inserting = true;
                    } else {
                        TreeNode<T> * newNode = new TreeNode<T>(data);
                        currentNode->setRightChild(newNode);
                        return newNode;
                    }
                } else {
                    return currentNode;
                }
            }
        }
        return nullptr;
    }
    
};


// do not edit below this line

#endif

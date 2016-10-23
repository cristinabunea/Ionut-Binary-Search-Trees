#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template<typename T>
class TreeNode {

public:
    T data;
    unique_ptr<TreeNode> leftChild;
    unique_ptr<TreeNode> rightChild;
    TreeNode<T>* parent;

    TreeNode(const T & myData) 
    : data(myData), parent(nullptr) {}

    void setLeftChild(TreeNode* child) {
        leftChild.reset(child);
        leftChild->parent = this;
    }

    void setRightChild(TreeNode* child) {
        rightChild.reset(child);
        rightChild->parent = this;
    }

    void write(ostream & o) const {
        if (leftChild){
            leftChild->write(o);
        }

        o << " " << this->data << " ";

        if (rightChild) {
            rightChild->write(o);
        }
    }
    
    T getData() const{
        return data;
    }
};

template <typename TT>

class TreeNodeIterator{
private:
    TreeNode<TT>* current;

public:
    TreeNodeIterator(TreeNode<TT>* currentTreeNode)
    : current(currentTreeNode) {}
    
    TT & operator*() {
        return current->data;
    }

    bool operator==(const TreeNodeIterator<TT> & secondItr) const {
        return current == secondItr.current;
    }

    bool operator!=(const TreeNodeIterator<TT> & secondItr) const {
        return current != secondItr.current;
    }

    void operator++() {
        TreeNode<TT>* mostLeft = current;
        TreeNode<TT>* master = current;        
        if (current->rightChild.get()){
            current = current->rightChild.get();
            mostLeft = getMostLeft(current);

            if (mostLeft != current){
                current = mostLeft;
            } 
        } else if (current->parent) {

            TT x = current->getData();
            master = current->parent;
            TT y = master->getData();

            while(y < x){

                if (master->parent) {
                    master = master->parent;
                    y = master->getData();
                } else {
                    y = x;
                    current = nullptr;
                }
            }
            if (x < y){
                current = master;
            }
        } else {
            current = nullptr;
        }        
    }

    TreeNode<TT>* getMostLeft(TreeNode<TT>* root) {
        TreeNode<TT>* currentNode = root;
        while(currentNode->leftChild.get()) {
            currentNode = currentNode->leftChild.get();
        }
        return currentNode;
    }
};

// do not edit below this line

#endif

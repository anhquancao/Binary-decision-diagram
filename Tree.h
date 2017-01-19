//
// Created by Son Tung Do on 1/13/17.
//

#ifndef PROJECT_S1_TREE_H
#define PROJECT_S1_TREE_H


#include "Node.h"
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class Tree {
public:
    Tree();

    Tree(Node *root, int nbOfNode);

    ~Tree();

    Node *getRoot() const;

    void setRoot(Node *root);

    int getNbOfNode() const;

    void setNbOfNode(int nbOfNode);

    void insertNode(int data);

    void deleteNode();

    bool search(int a);

    void show();

private:
    Node *root;
    int nbOfNode;

};


#endif //PROJECT_S1_TREE_H

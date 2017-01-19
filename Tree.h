//
// Created by Son Tung Do on 1/13/17.
//

#ifndef PROJECT_S1_TREE_H
#define PROJECT_S1_TREE_H


#include "Node.h"


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

    void deleteNode(Node node);

    bool search(int a);
private:
    Node *root;
    int nbOfNode;

};


#endif //PROJECT_S1_TREE_H

//
// Created by Son Tung Do on 1/13/17.
//

#include "Tree.h"

Tree::Tree() {

}

Tree::Tree(Node *root, int nbOfNode) : root(root), nbOfNode(nbOfNode) {}

Tree::~Tree() {

}

Node *Tree::getRoot() const {
    return root;
}

void Tree::setRoot(Node *root) {
    Tree::root = root;
}

int Tree::getNbOfNode() const {
    return nbOfNode;
}

void Tree::setNbOfNode(int nbOfNode) {
    Tree::nbOfNode = nbOfNode;
}

void Tree::insertNode() {

}

void Tree::deleteNode() {

}

bool Tree::search(int a) {
    return false;
}

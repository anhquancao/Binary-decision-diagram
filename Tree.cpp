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

Node* recInsertNode(Node *node, int data) {
    Node *currentNode = node;
    if (currentNode == nullptr) {
        currentNode->setData(data);
    } else {
        if (data > currentNode->getData()) {
            if (currentNode->getRightNode() != nullptr) {
                currentNode = currentNode->getRightNode();
                recInsertNode(currentNode, data);
            } else {
                Node* newNode = new Node(data);
                currentNode->setRightNode(*newNode);
            }
        } else {
            if (currentNode->getLeftNode() != nullptr) {
                currentNode = currentNode->getLeftNode();
                recInsertNode(currentNode, data);
            } else {
                Node* newNode = new Node(data);
                currentNode->setLeftNode(*newNode);
            }
        }
    }

    return currentNode;
}

void Tree::insertNode(int data) {
    this->root = recInsertNode(this->root, data);
    this->nbOfNode += 1;
}

void Tree::deleteNode(Node node) {
    if (node.getLeftNode() == nullptr && node.getRightNode() == nullptr) {

    }

    if (node.getRightNode()) {

    }
}

bool recSearch(int a, Node *node) {
    bool result = false;
    Node *currentNode = node;
    if (currentNode->getData() == a) {
        result = true;
    } else {
        if (a > currentNode->getData()) {
            if (currentNode->getRightNode() != nullptr) {
                currentNode = currentNode->getRightNode();
                result = recSearch(a, currentNode);
            } else {
                return false;
            }
        } else {
            if (currentNode->getLeftNode() != nullptr) {
                currentNode = currentNode->getLeftNode();
                result = recSearch(a, currentNode);
            } else {
                return false;
            }
        }
    }

    return result;
}

bool Tree::search(int a) {
    bool result = false;
    Node *currentNode = this->getRoot();
    recSearch(a, currentNode);
    return result;
}

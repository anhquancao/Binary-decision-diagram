//
// Created by Son Tung Do on 1/13/17.
//


#include "Tree.h"

Tree::Tree() {
    this->nbOfNode = 0;
}

Tree::Tree(Node *root, int nbOfNode) : root(root), nbOfNode(nbOfNode) {}

void clearTree(Node *node) {
    if (node != nullptr) {
        clearTree(node->getLeftNode());
        clearTree(node->getRightNode());
        delete node;
    }
}

Tree::~Tree() {
    clearTree(this->root);
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

/**
 * Recursive insert node function
 * @param root
 * @param data
 */
Node *recInsertNode(Node *root, int data) {

    if (root == NULL) {
        root = new Node(data, NULL, NULL);
    } else {
        if (data < root->getData()) {
            if (root->getLeftNode() == nullptr) {
                root->setLeftNode(new Node(data, NULL, NULL));
            } else {
                recInsertNode(root->getLeftNode(), data);
            }

        } else {
            if (root->getRightNode() == nullptr) {
                root->setRightNode(new Node(data, NULL, NULL));
            } else {
                recInsertNode(root->getRightNode(), data);
            }
        }
    }
    return root;
}

void Tree::insertNode(int data) {
    this->nbOfNode += 1;
    this->root = recInsertNode(this->root, data);
}


void Tree::deleteNode() {

}

bool Tree::search(int a) {
    return false;
}


/**
 * Recursive print node of the tree
 * @param root
 * @param data
 */
void recShow(Node *p, int indent = 0) {
    if (p != NULL) {
        if (p->getRightNode()) {
            recShow(p->getRightNode(), indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->getRightNode()) std::cout << " /\n" << std::setw(indent) << ' ';
        std::cout << p->getData() << "\n ";
        if (p->getLeftNode()) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            recShow(p->getLeftNode(), indent + 4);
        }
    }
}

void Tree::show() {
    recShow(this->root);
}

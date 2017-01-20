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
//    clearTree(this->root);
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
        if (data <= root->getData()) {
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


void Tree::deleteNode(int data) {
    Node *node = this->root;
    Node *parentNode = NULL;
    bool isLeft = false;
    bool isRight = false;
    while (true) {
//        cout << node->getData() << " : " << data << endl;
        if (node->getLeftNode() == NULL && node->getRightNode() == NULL) {
            if (isLeft) {
                parentNode->setLeftNode(NULL);
            } else if (isRight) {
                parentNode->setRightNode(NULL);
            } else {
                this->setRoot(NULL);
            }
            delete node;
            break;
        } else {
            if (data > node->getData()) {
                if (node->getRightNode() != NULL) {
                    parentNode = node;
                    node = node->getRightNode();
                    isRight = true;
                    continue;
                } else {
                    cout << "Value not in tree";
                    break;
                }
            } else if (data < node->getData()) {
                if (node->getLeftNode() != NULL) {
                    parentNode = node;
                    node = node->getLeftNode();
                    isLeft = true;
                    continue;
                } else {
                    cout << "Value not in tree";
                    break;
                }
            } else {
                if (node->getLeftNode() != NULL && node->getRightNode() == NULL ||
                    node->getLeftNode() == NULL && node->getRightNode() != NULL) {
                    if (node->getLeftNode() != NULL) {
                        if (isLeft) {
                            parentNode->setLeftNode(node->getLeftNode());
                        }
                        if (isRight) {
                            parentNode->setRightNode(node->getLeftNode());
                        }

                    }
                    if (node->getRightNode() != NULL) {
                        if (isLeft) {
                            parentNode->setLeftNode(node->getRightNode());
                        }
                        if (isRight) {
                            parentNode->setRightNode(node->getRightNode());
                        }
                    }
                    delete node;
                    break;
                } else {
                    Node *min = node->getRightNode();
                    Node *parentMinNode = node;
                    bool isRight = true;
                    while (min->getLeftNode() != NULL) {
                        isRight = false;
                        parentMinNode = min;
                        min = min->getLeftNode();
                    }
                    if (isRight){
                        parentMinNode->setRightNode(min->getRightNode());
                    }else{
                        parentMinNode->setLeftNode(min->getRightNode());
                    }
                    node->setData(min->getData());
                    delete min;
                    break;
                }
            }
        }

    }
}

bool recSearch(int data, Node *node) {
    Node *currentNode = node;
    if (currentNode == NULL) {
        return false;
    } else {
        if (currentNode->getData() == data) {
            return true;
        } else {
            if (data > currentNode->getData()) {
                if (currentNode->getRightNode() != NULL) {
                    return recSearch(data, currentNode->getRightNode());
                } else {
                    return false;
                }
            } else {
                if (currentNode->getLeftNode() != NULL) {
                    return recSearch(data, currentNode->getLeftNode());
                } else {
                    return false;
                }
            }
        }
    }
}

bool Tree::search(int data) {
    Node *currentNode = this->getRoot();
    return recSearch(data, currentNode);
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

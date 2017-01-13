//
// Created by Son Tung Do on 1/13/17.
//

#include "Node.h"

Node::Node() {

}

Node::Node(int data) : data(data) {
}

Node::~Node() {

}

int Node::getData() {
    return this->data;
}

Node *Node::getLeftNode() const {
    return this->leftNode;
}

Node *Node::getRightNode() const {
    return this->rightNode;
}

void Node::setData(int data) {
    this->data = data;
}

void Node::setLeftNode(Node &node) {
    this->leftNode = &node;
}

void Node::setRightNode(Node &node) {
    this->rightNode = &node;
}

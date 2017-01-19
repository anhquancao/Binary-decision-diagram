//
// Created by Son Tung Do on 1/13/17.
//

#include "Node.h"

Node::Node() {

}

Node::Node(int data){
    this->data = data;
}

Node::~Node() {

}

int Node::getData() {
    return this->data;
}

Node *Node::getLeftNode() {
    return this->leftNode;
}

Node *Node::getRightNode() {
    return this->rightNode;
}

void Node::setData(int data) {
    this->data = data;
}

void Node::setLeftNode(Node *node) {
    this->leftNode = node;
}

void Node::setRightNode(Node *node) {
    this->rightNode = node;
}

Node::Node(int data, Node *leftNode, Node *rightNode) : data(data), leftNode(leftNode), rightNode(rightNode) {}

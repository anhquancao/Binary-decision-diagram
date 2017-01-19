//
// Created by Son Tung Do on 1/13/17.
//

#ifndef PROJECT_S1_NODE_H
#define PROJECT_S1_NODE_H


class Node {

    int data;
    Node *leftNode;
    Node *rightNode;


public:
    //Constructor
    Node();

    Node(int data);

    Node(int data, Node *leftNode, Node *rightNode);

    //Destructor
    ~Node();

    //Getter

    int getData();

    Node * getLeftNode();

    Node * getRightNode();

    // Setter
    void setData(int data);

    void setLeftNode(Node *node);

    void setRightNode(Node *node);
};


#endif //PROJECT_S1_NODE_H

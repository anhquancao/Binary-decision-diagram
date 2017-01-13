//
// Created by Son Tung Do on 1/13/17.
//

#ifndef PROJECT_S1_NODE_H
#define PROJECT_S1_NODE_H


class Node {
    int data;
    Node *leftNode;
    Node *rightNode;

    //Constructor
    Node();

    Node(int data);

    //Destructor
    ~Node();

    //Getter

    int getData();

    Node *getLeftNode() const;

    Node *getRightNode() const;

    // Setter
    void setData(int data);

    void setLeftNode(Node &node);

    void setRightNode(Node &node);
};


#endif //PROJECT_S1_NODE_H

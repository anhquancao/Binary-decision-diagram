#include <iostream>
#include "Tree.h"


using namespace std;

int main() {
    Tree tree;
    tree.insertNode(26);
    tree.insertNode(3);
    tree.insertNode(2);
    tree.insertNode(15);
    tree.insertNode(37);
    tree.insertNode(38);
    tree.insertNode(25);
    tree.insertNode(80);
    tree.insertNode(45);

    tree.show();
    return 0;
}
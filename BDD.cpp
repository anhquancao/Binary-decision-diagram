//
// Created by Quan Cao on 2/25/17.
//

#include "BDD.h"

unsigned int BDD::nodeHash(int var, BDD *high, BDD *low) {
    return BDD::triple((unsigned int) var, (unsigned int) high, (unsigned int) low) % BDD_NODE_SIZE;
}

unsigned int BDD::pair(unsigned int a, unsigned int b) {
    return (a + b) * (a + b + 1) / 2 + a;
}

unsigned int BDD::triple(unsigned int var, unsigned int low, unsigned int high) {
    return BDD::pair(high, BDD::pair(var, low));
}

BDD::BDD(int var, BDD *low, BDD *high) : index(var), high(high), low(low) {
}

BDD *BDD::makeNode(int var, BDD *low, BDD *high) {
    unsigned int hash = BDD::nodeHash(var, low, high);
    // no bucket is matched
    if (BDDTable[hash] == 0) {
        BDDTable[hash] = new BDD(var, high, low);
        return BDDTable[hash];
    } else {
        BDD *node = BDDTable[hash]; // 1st node in the bucket
        // Search the bucket for the right node
        while (node->next && !node->sameAs(var, low, high))
            node = node->next;
        if (node->sameAs(var, low, high)) {
            // found matching node in the bucket
            return node;
        } else {
            // no matching node in the bucket
            // make new node and add it to the bucket
            BDD *newNode = new BDD(var, low, high);
            node->next = newNode;
        }
    }
}


bool BDD::sameAs(int var, BDD *newLow, BDD *newHigh) {
    return this->index == var && this->low == newLow && this->high == newHigh;
}


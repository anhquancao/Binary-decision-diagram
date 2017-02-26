//
// Created by Quan Cao on 2/25/17.
//

#include "BDD.h"

unsigned int BDD::nodeHash(int var, BDD *low, BDD *high) {
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

BDD *BDD::restrict(BDD *subTree, int var, bool val) {
    if (subTree->index > var) {
        return subTree;
    } else if (subTree->index < var) {
        return BDD::makeNode(subTree->index,
                             BDD::restrict(subTree->low, var, val),
                             BDD::restrict(subTree->high, var, val));
    } else {
        if (val) {
            return BDD::restrict(subTree->high, var, val);
        } else {
            return BDD::restrict(subTree->low, var, val);
        };
    }
}

BDD *BDD::ithVar(int i) {
    numVars++;
    BDDTable[0]->index = numVars;
    BDDTable[1]->index = numVars;
    return BDD::makeNode(i, BDDFalse(), BDDTrue());
}

BDD *BDD::ITE(BDD *I, BDD *T, BDD *E) {
    if (I == BDD::BDDTrue()) return T;
    if (I == BDD::BDDFalse()) return E;
    if (T == E) return T;
    if (T == BDDTrue() && E == BDDFalse()) return I;

    int splitVar = I->index;
    if (splitVar > T->index) { splitVar = T->index; }
    if (splitVar > E->index) { splitVar = E->index; }

    BDD *Ixt = BDD::restrict(I, splitVar, true);
    BDD *Txt = BDD::restrict(T, splitVar, true);
    BDD *Ext = BDD::restrict(E, splitVar, true);
    BDD *posFtor = BDD::ITE(Ixt, Txt, Ext);

    BDD *Ixf = BDD::restrict(I, splitVar, true);
    BDD *Txf = BDD::restrict(T, splitVar, true);
    BDD *Exf = BDD::restrict(E, splitVar, true);
    BDD *negFtor = BDD::ITE(Ixf, Txf, Exf);

    BDD *result = BDD::makeNode(splitVar, posFtor, negFtor);
    return result;
}




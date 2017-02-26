//
// Created by Quan Cao on 2/25/17.
//

#ifndef PROJECT_S1_BDD_H
#define PROJECT_S1_BDD_H

#include <cstdlib>

class BDD {
private:

    static unsigned int pair(unsigned int a, unsigned int b);

    static unsigned int triple(unsigned int var, unsigned int low, unsigned int high);

public:

    int index; // lower index = closer to the top
    BDD *high;  // point to the THEN BDD
    BDD *low; // point to the ELSE BDD
    BDD *next; // point to the NEXT BDD in the bucket

    static unsigned int BDD_NODE_SIZE = 1000;
    static BDD **BDDTable = (BDD **) calloc(BDD_NODE_SIZE, sizeof(BDD *));

    static int numVars = 0;


    BDD(int var, BDD *low, BDD *high);

    static BDD *BDDFalse() {
        if (BDDTable[0] == 0) {
            BDDTable[0] = new BDD(numVars + 1, NULL, NULL);
        }
        return BDDTable[0];
    }

    static BDD *BDDTrue() {
        if (BDDTable[1] == 0) {
            BDDTable[1] = new BDD(numVars + 1, NULL, NULL);
        }
        return BDDTable[1];
    }

    static unsigned int nodeHash(int var, BDD *low, BDD *high);

    static unsigned int numvars = 0;

    static BDD *makeNode(int var, BDD *low, BDD *high);

    static BDD *restrict(BDD *subTree, int var, bool val);

    static BDD *ithVar(int i);

    static BDD *ITE(BDD *I, BDD *T, BDD *E);

    bool sameAs(int var, BDD *newLow, BDD *newHigh);

};


#endif //PROJECT_S1_BDD_H

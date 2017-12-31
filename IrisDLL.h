// Lauren Sherman
// A specific DLL implementation designed for the Fisher Iris data.  The specifics of DLLs are inherited from DLinkedList

#ifndef LAB2_IRISDLL_H
#define LAB2_IRISDLL_H

#include <iostream>

using namespace std;

#include "IrisNode.h"
#include "DLinkedList.h"

class IrisDLL : public DLinkedList<IrisNode> {

private:

    // additional class member to hold the 4-dimensional sum of the sepal and petal measurements,
    // this is done in IrisDLL::insert() and IrisDLL::remove()
    IrisNode IrisSum;


public:

    // constructor
    IrisDLL(): DLinkedList<IrisNode>(), IrisSum(0,0.0,0.0,0.0,0.0)
    {
    }

    // Iris DLL insert()
    void insert(const IrisNode & XXX)
    {
        IrisSum.addNode(XXX); //calls addNode to update sum
        addFront(XXX); //add to the front of Iris Sum
    }

    // Iris DLL remove()
    void remove()
    {
        removeFront();

    }

    // get IrisSum
    IrisNode getSum() const
    {
        return IrisSum; //return IrisSum
    }

    // get IrisAverage
    IrisNode getAverage() const
    {
        return IrisSum.divNode(getSize()); //return IrisSum divided by size
    }

};


#endif //LAB2_IRISDLL_H

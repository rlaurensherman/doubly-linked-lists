// Lauren Sherman
// Class for Fisher iris data

#ifndef LAB2_IRISNODE_H
#define LAB2_IRISNODE_H

#include <cmath>
#include <iostream>

using namespace std;

class IrisNode {

    friend istream& operator>>(istream & IN, IrisNode & myIris);
    friend ostream & operator<<(ostream & OUT, const IrisNode & myIris);

private:
    int id;
    float sepalLength;
    float sepalWidth;
    float petalLength;
    float petalWidth;

public:

    IrisNode()
    {
        id = 0;
        sepalLength = 0.0;
        sepalWidth = 0.0;
        petalLength = 0.0;
        petalWidth = 0.0;
    }

    IrisNode(const int myId,const  float mysL, const float mysW, const float mypL, const float mypW)
    {
        id = myId;
        sepalLength = mysL;
        sepalWidth = mysW;
        petalLength = mypL;
        petalWidth = mypW;
    }


    // methods to compute 4-dimensional sum, division by constant, difference and twoNorm for Fisher Iris data
    void addNode(const IrisNode &);
    IrisNode divNode(const float ) const;
    void subNode(const IrisNode &);
    double twoNorm(const IrisNode & YYY) const;

};


#endif //LAB2_IRISNODE_H

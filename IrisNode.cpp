// Lauren Sherman

#include "IrisNode.h"
#include "IrisDLL.h"

istream& operator>>(istream & IN, IrisNode & myIris)
{
    IN >> myIris.id;
    IN >> myIris.sepalLength;
    IN >> myIris.sepalWidth;
    IN >> myIris.petalLength;
    IN >> myIris.petalWidth;

    return IN;
}

ostream & operator<<(ostream & OUT, const IrisNode & myIris)
{
    OUT << myIris.id << "  ";
    OUT << myIris.sepalLength << "  ";
    OUT << myIris.sepalWidth << "  ";
    OUT << myIris.petalLength << "  ";
    OUT << myIris.petalWidth << "  ";

    return OUT;
}

// Function to compute the sums
void IrisNode::addNode(const IrisNode & XXX)
{
    sepalLength = sepalLength + XXX.sepalLength; //add sepal lengths
    sepalWidth = sepalWidth + XXX.sepalWidth; //add sepal widths
    petalLength = petalLength + XXX.petalLength; //add petal lengths
    petalWidth = petalWidth + XXX.petalWidth; //add petal widths
}

// Function to compute division
IrisNode IrisNode::divNode(const float zzz) const
{
    return IrisNode(0, sepalLength/zzz, sepalWidth/zzz, petalLength/zzz, petalWidth/zzz); //divide each dimension by the float
}

// Function to compute the differences
void IrisNode::subNode(const IrisNode & XXX)
{
    sepalLength = sepalLength - XXX.sepalLength; //subtract sepal lengths
    sepalWidth = sepalWidth - XXX.sepalWidth; //subtract sepal widths
    petalLength = petalLength - XXX.petalLength; //subtract petal lengths
    petalWidth = petalWidth - XXX.petalWidth; //petal widths
}


// Function to compute the Euclidian distance between this and YYY
double IrisNode::twoNorm(const IrisNode & YYY) const
{
    double a = sepalLength - YYY.sepalLength; //subtract sepal lengths
    double b = sepalWidth - YYY.sepalWidth; //subtract sepal widths
    double c = petalLength - YYY.petalLength; //subtract petal lengths
    double d = petalWidth - YYY.petalWidth; //subtract petal widths

    double edist; //Euclidian distance variable
    edist = (a*a) + (b*b) + (c*c) + (d*d); //square each of the 4 subtracted dimensions and add together
    edist = sqrt(edist); //take the square root

    return edist; //return Euclidian distance
}



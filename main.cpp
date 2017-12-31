// Lauren Sherman

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#include "IrisDLL.h"

// prototypes for functions declared after main()
void getMyData(string fname, IrisDLL* currentClusters[] );
void kmeans(IrisDLL* currentClusters[]);

int main() {

    // create two doubly-linked lists for 2Means
    IrisDLL* currentClusters[2] = {NULL, NULL};
    currentClusters[0] = new IrisDLL();
    currentClusters[1] = new IrisDLL();

    srand(time(NULL));  // intialize random number generation


    // get data from file and place randomly into the two arrays
    getMyData("/usr/local/djj/data/iris_data.txt", currentClusters);

    cout << currentClusters[0]->getSize() << "  " << currentClusters[0]->getAverage() << endl;
    cout << currentClusters[1]->getSize() << "  " << currentClusters[1]->getAverage() << endl;

    // call kmeans (2means)
    kmeans(currentClusters);

    cout << currentClusters[0]->getSize() << "  " << currentClusters[0]->getAverage() << endl;
    cout << currentClusters[1]->getSize() << "  " << currentClusters[1]->getAverage() << endl;

    cout << endl;

    return 0;
}

// ------------------------------------------------------------------------

// function that will read data from fname and distribute it into two DLLs
// in a random fashion
void getMyData(string fname, IrisDLL* currentClusters[]) {

    ifstream myInput; //create ifstream variable

    myInput.open(fname, ios::in); //Open a file to read input

    if (myInput.fail()) //if it fails to open file
    {
        cerr << "input failed" << endl; //print error message
        exit(0);
    }

    IrisNode XXX; //create IrisNode to read data into


    while (myInput >> XXX) //while data is being read in from the file
    {
        int a;
        a = rand(); //random int


        if (a%2 == 0) //if a is even
        {
            currentClusters[0]->insert(XXX); //put into currentClusters 0
        }

        else if (a%2 == 1) //if a is odd
        {
            currentClusters[1]->insert(XXX); //put into currentClusters 1
        }

    }

    myInput.close(); //close the file

}

// ------------------------------------------------------------------------------------

// function to compute kmeans (2means)
void kmeans(IrisDLL* currentClusters[])
{

    // create two DLL for each redistribution step, also XXX[] to hold the current averages
    IrisDLL* newClusters[2] = {NULL, NULL};
    IrisNode XXX[2];

    // as long as data from one list goes to the other, keep looping
    /*bool switchMade = true;
    while (switchMade) { //while there is movement from one list to another */

        cout << ".";

        /*switchMade = false;  // be pessimistic */

        // create newClusters where the current elements will be reassigned
        newClusters[0] = new IrisDLL();
        newClusters[1] = new IrisDLL();

        // remember the current averages for the currentClusters
        XXX[0] = currentClusters[0]->getAverage(); //average for currentClusters 0
        XXX[1] = currentClusters[1]->getAverage(); //average for currentClusters 1

        //move data from currentClusters[0]
        while (currentClusters[0]->getSize() > 0) //while there is still data in currentClusters 0
        {
            if (currentClusters[0]->front().twoNorm(XXX[0]) < currentClusters[0]->front().twoNorm(XXX[1])) //if data in first place in currentClusters 0 is closer to mean of list 0
            {
                newClusters[0]->insert(currentClusters[0]->front()); //insert that data from currentClusters 0 into newClusters 0

                currentClusters[0]->remove(); //delete the data from currentClusters 0
            }

            else if (currentClusters[0]->front().twoNorm(XXX[0]) > currentClusters[0]->front().twoNorm(XXX[1])) //if data in first place in currentClusters 0 is closer to mean of list 1
            {
                newClusters[1]->insert(currentClusters[0]->front()); //insert that data from currentClusters 0 into newClusters 1

                currentClusters[0]->remove(); //delete the data from currentClusters 0
            }
        }

        //move data from currentClusters[1]
        while (currentClusters[1]->getSize() > 0) //while there is still data in currentClusters 1
        {
            if (currentClusters[1]->front().twoNorm(XXX[0]) < currentClusters[1]->front().twoNorm(XXX[1])) //if data in first place in currentClusters 1 is closer to mean of list 0
            {
                newClusters[0]->insert(currentClusters[1]->front()); //insert that data from currentClusters 1 into newClusters 0

                currentClusters[1]->remove(); //delete the data from currentClusters 1
            }

            else if (currentClusters[1]->front().twoNorm(XXX[0]) > currentClusters[1]->front().twoNorm(XXX[1])) //if data in first place in currentClusters 1 is closer to mean of list 1
            {
                newClusters[1]->insert(currentClusters[1]->front()); //insert that data from currentClusters 1 into newClusters 1

                currentClusters[1]->remove(); //delete the data from currentClusters 1
            }
        }



    cout << endl;

    //Set current clusters to new clusters and empty new clusters
    currentClusters[0]= newClusters[0];
    currentClusters[1] = newClusters[1];
    newClusters[0] = {NULL};
    newClusters[1] = {NULL};


}

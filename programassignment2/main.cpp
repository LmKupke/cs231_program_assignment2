//
//  main.cpp
//  programassignment2
//
//  Created by lkupke on 3/4/18.
//  Copyright © 2018 lkupke. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T getInput(string output);

void getUsersNumbers(int amountVectorReserved, vector<float> &initializedVector);

float computeAverage(vector<float> &dataVector);

void showValues(vector<float> &dataVector);

int main(int argc, const char * argv[]) {
    vector<float> vs;
    int vectorAmount = getInput<int>("Hello! Please enter the amount of items you want to add: ");
    vs.reserve(vectorAmount);

    getUsersNumbers(vectorAmount, vs);
    
    
    
    
    float average = computeAverage(vs);
    cout << "The average is " << average << endl;
}


// Description:  A function to ask user for a value
// Return status: 0  a valid number is entered
//                1  a valid number is not entered
template <typename T>
T getInput(string output)
{
    T temp;
    
    std::cout << output;
    
    std::cin >> temp;
    
    return temp;
} // end of getInput()


void getUsersNumbers(int amountVectorReserved,vector<float> &initializedVector) {
    
    for (int n=0; n < amountVectorReserved; n++) {
        
            float data =  getInput<float>("Please enter the float that you want: ");
        
            initializedVector.push_back(data);
    }
}

float computeAverage(vector<float> &dataVector) {
    float sum = 0.0;
    
    for(int i:dataVector) {
        sum += i;
    }
    float average = sum/dataVector.size();
    cout << "The average is " << average << endl;

    return average;
}


void showValues(vector<float> &dataVector) {
    for (int i=0; i<dataVector.size(); i++)
        cout << "The value at " << i << " is: " << dataVector[i] << endl;

}

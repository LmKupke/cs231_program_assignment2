//
//  main.cpp
//  programassignment2
//
//  Created by lkupke on 3/4/18.
//  Copyright © 2018 lkupke. All rights reserved.
//

#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

template <typename T>
T getInput(string output);

void getUsersNumbers(int amountVectorReserved, vector<float> &initializedVector);

float computeAverage(vector<float> &dataVector);

void showValues(vector<float> &dataVector);

float standardDeviation(vector<float> &dataVector);

void reportStdAndMean(vector<float> &dataVector);

void startProgram();

void menuOptions();

void addMoreToVector(vector<float> &dataVector);



int main(int argc, const char * argv[]) {

    startProgram();

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
    
    for(float i:dataVector) {
        sum += i;
    }
    float average = (float) (sum/dataVector.size());

    return average;
}


void showValues(vector<float> &dataVector) {
    for (int i=0; i<dataVector.size(); i++)
        cout << "The value at " << i << " is: " << dataVector[i] << endl;

}

float standardDeviation(vector<float> &dataVector) {
    float mean = computeAverage(dataVector);
    
    float totalVariance = 0.0;
    float variance = 0.0;
    float standardDeviation = 0.0;
    
    for(int n=0; n < dataVector.size(); n++) {
      totalVariance +=  ((dataVector[n] - mean) * (dataVector[n] - mean));
    }
    variance = totalVariance/dataVector.size();
    
    standardDeviation = pow(variance,.5);
    
    return standardDeviation;
    
    
}


void reportStdAndMean(vector<float> &dataVector) {
    float mean = computeAverage(dataVector);
    
    float standardDev = standardDeviation(dataVector);
    
    cout << "The mean of the values entered is: " << mean << ". The standard deviation is: " << standardDev << "." << endl;
}


void startProgram() {
    cout << "Hello welcome to Lincoln Kupke's programming assignment 2!" << endl;
    cout << "Let's first get you adding to the array" << endl;
    
    vector<float> vs;
    int vectorAmount = getInput<int>("Hello! Please enter the amount of items you in the vector: ");
//    vs.reserve(vectorAmount);
    getUsersNumbers(vectorAmount, vs);
    
    cout << "Now follow the menu please" << endl;
    menuOptions();
    
    int userAction = getInput<int>("Please enter a menu option: ");

    while (userAction != 0) {
       
        switch (userAction) {
            case 0:
                break;
                
            case 1:
                addMoreToVector(vs);
                break;
            case 2:
                showValues(vs);
                break;
            case 3:
                cout << "The average is " << computeAverage(vs) << endl;
                break;
            case 4:
                cout << "The standard deviation is " << standardDeviation(vs) << endl;
                break;
            
            case 5:
                reportStdAndMean(vs);
                break;
                
            case 6:
                menuOptions();
                break;
                
            default:
                cout << "Seems like you picked an invalid option :(" << endl;
                break;
        }
        if(userAction != 0) {
            userAction = getInput<int>("Please enter an option from the menu. Enter 6 to get the menu agian:  ");
        }
        
    }
    
    
}


void menuOptions() {
    cout << "Please type the corresponding number to run the function." << endl;
    cout << "***MENU OPTIONS***" << endl;
    cout << "1 - Add more values to vector" << endl;
    cout << "2 - Show Values in vector" << endl;
    cout << "3 - Get mean of vector" << endl;
    cout << "4 - Get standard deviation of vector" << endl;
    cout << "5 - Get standard deviation and mean of vector" << endl;
    cout << "6 - Show Menu Options" << endl;
    cout << "0 - End program" << endl;
    
}


void addMoreToVector(vector<float> &dataVector) {
    int additionSpaces = getInput<int>("Please enter how many more items you want added to the vector: ");
    
    getUsersNumbers(additionSpaces, dataVector);
    
}

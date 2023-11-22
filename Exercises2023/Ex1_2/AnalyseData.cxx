// David Riley 15/11/2023 C++ labs
#include <iostream>
#include <vector>
#include <string>
#include "CustomFunctions.h"

int main(){

    std::string fileName = "test_data.txt";
 
    // read in our file using out readFileToVector function 
    std::vector<std::vector<float>> vectorOfPoints = readFileToVector(fileName);

    // store the number of points in an in to use later
    int numOfPoints = vectorOfPoints.size();

    // define a variable to check for different program states
    // 0 = Default (back to asking the user what they want to do)
    // 1 = print values in the opened file
    // 2 = calculate their magnitudes
    // 3 = fit to the data
    int programState; 

    print("Print (1), get mags (2) or fit (3)?");
    std::cout << "Choice : ";
    std::cin >> programState;
    
    // input for how many lines to print, for some reason the switch requires this outside of the case statements?
    std::string userInputStr;

    switch (programState){
        // print the values in the file
        case 1:
            
            int numOfLinesToPrint;

            // now read in a value from the user specifying how many data points the user wants to print and convert from string to int
            std::cout << "Enter how many values from the file you would like to print: ";
            std::cin >> userInputStr;
            numOfLinesToPrint = std::stoi(userInputStr);

            // run our function to print points contained in the data
            printOutData(numOfLinesToPrint,numOfPoints,vectorOfPoints);

            break;
        // get the magnitudes of the vectors to the points
        case 2:

            getMagnitudes(vectorOfPoints);

            break;
        // fit a line to the data
        case 3:

            fitStraightLine(vectorOfPoints);

            break;

        default:
            print("Invalid Choice Try again");
            break;

    }

    return 0;
}
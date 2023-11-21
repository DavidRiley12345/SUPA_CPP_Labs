// David Riley 15/11/2023 C++ labs
#include <iostream>
#include <vector>
#include <string>
#include "CustomFunctions.h"

int main(){

    std::string fileName = "input2D_float.txt";
     
    // read in our file using out readFileToVector function 
    std::vector<std::vector<float>> vectorOfPoints = readFileToVector(fileName);

    // store the number of points in an in to use later
    int numOfPoints = vectorOfPoints.size();

    std::string userInputStr;
    int numOfLinesToPrint;

    // now read in a value from the user specifying how many data points the user wants to print
    std::cout << "Enter how many values from the file you would like to print: ";
    std::cin >> userInputStr;

    numOfLinesToPrint = std::stoi(userInputStr);

    printOutData(numOfLinesToPrint,numOfPoints,vectorOfPoints);

    // now calculate the magnitude of each data point in the vector

    getMagnitudes(vectorOfPoints);

    // fit a line to the data

    fitStraightLine(vectorOfPoints);

    return 0;
}
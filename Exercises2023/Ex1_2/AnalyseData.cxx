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

    // define a state variable to switch between different program modes
    // 0 = Default (back to asking the user what they want to do)
    // 1 = print values in the opened file
    // 2 = calculate their magnitudes
    // 3 = fit to the data
    // 4 = get x to the power y
    int programState; 

    bool exitProgram = false;

    while (!exitProgram){

        print("Print (1), get mags (2) or fit (3) or powers (4)? (or exit (5))");
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

                programState = 0;
                break;
            // get the magnitudes of the vectors to the points
            case 2:

                getMagnitudes(vectorOfPoints);

                programState = 0;
                break;
            // fit a line to the data
            case 3:

                fitStraightLine(vectorOfPoints);

                programState = 0;
                break;

            case 4:

                calcXtotheY(vectorOfPoints);

                programState = 0;
                break;
            // exit program
            case 5:

                exitProgram = true;

                programState = 0;
                break;
            // error if value doesn't match any from the list
            default:
                print("Invalid Choice Try again");
                break;

        }
    }

    print("Program Closed");

    return 0;
}
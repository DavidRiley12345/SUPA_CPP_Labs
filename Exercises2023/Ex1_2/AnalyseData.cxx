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

        print(""); // empty line for readability
        print("Main Menu");
        print("What would you like to do? Enter a number from the list below:");
        print("1 - Print n lines of the data");
        print("2 - Calculate magnitudes of x,y pairs");
        print("3 - Fit a straight line to the data");
        print("4 - Calculate X to the power of Y (rounded)");
        print("5 - Exit");
        std::cout << "Selection : ";
        std::cin >> programState;
        
        // input for how many lines to print, for some reason the switch requires this outside of the case statements?
        std::string userInputStr;

        // initialise variables to store outputs of functions 
        std::vector<float> magnitudes;
        std::vector<float> fitResults;
        std::vector<float> powerResults;
        std::string saveChoice;
        std::string continueChoice;

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

                magnitudes = getMagnitudes(vectorOfPoints);

                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/Magnitudes.txt",magnitudes);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n";

                break;
            // fit a line to the data
            case 3:

                fitResults = fitStraightLine(vectorOfPoints);

                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/FitResults.txt",fitResults);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n";

                break;

            case 4:

                powerResults = calcXtotheY(vectorOfPoints);

                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/XtotheY.txt",powerResults);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n";

                break;
            
            // exit program
            case 5:

                exitProgram = true;

                break;
            // error if value doesn't match any from the list
            default:
                print("Invalid Choice Try again");
                break;

        }
        
        if(exitProgram == false){
            std::cout << "Would you like to perform another action (enter 1)? or exit (enter 2) : ";
            std::cin >> continueChoice; 

            if(continueChoice == "1"){
                programState = 0;
            } else if (continueChoice == "2"){
                exitProgram = true;
            } else {
                print("Input not recognised: returning to menu");
                programState = 0;
            }
        }
        
    }

    print("Program Closed");

    return 0;
}
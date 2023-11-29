// David Riley 15/11/2023 C++ labs
#include <iostream>
#include <vector>
#include <string>
#include "CustomFunctions.h"

int main(){ 

    // set the name of the input file here
    std::string fileName = "input2D_float.txt";
 
    // read in our file using out readFileToVector function 
    std::vector<std::vector<float>> vectorOfPoints = readFileToVector(fileName);

    // define a state variable to switch between different program modes
    // 0 = Default (back to asking the user what they want to do)
    // 1 = print values in the opened file
    // 2 = calculate their magnitudes treating x,y as if it is a vector with 0,0
    // 3 = fit a straight line to the data
    // 4 = get x to the power y (rounded to a whole number)
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
        std::cin >> programState; // get user input for the desired program state
        
        // initialise variables to store user inputs/function outputs for use inside the switch statement
        std::string userInputStr;
        std::string saveChoice;
        std::string continueChoice;
        std::vector<float> magnitudes;
        std::vector<float> fitResults;
        std::vector<float> powerResults;

        switch (programState){
            
            case 1: // print the values in the file
                
                int numOfLinesToPrint;

                // now read in a value from the user specifying how many data points the user wants to print and convert from string to int
                std::cout << "Enter how many values from the file you would like to print: ";
                std::cin >> userInputStr;
                numOfLinesToPrint = std::stoi(userInputStr);

                // call printOutData from CustomFunctions.cxx passing it the number of lines to be printed, and the total size of the array and the data
                printOutData(numOfLinesToPrint,vectorOfPoints);

                break;
            
            case 2: // get the magnitudes treating the points as vectors with 0,0

                // call our getMagnitudes funciton from CustomFunctions.cxx passing it our data
                magnitudes = getMagnitudes(vectorOfPoints);

                // ask the user if they would like to save the outputs to a file
                // could be moved into the defintion of output in CustomFunctions.cxx for neatness/repetition
                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/Magnitudes.txt",magnitudes);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n"; // reset the save choice back to a default of no

                break;
            
            case 3: // fit a straight line to the data

                // call our fitStraightLine funciton from CustomFunctions.cxx passing it our data
                fitResults = fitStraightLine(vectorOfPoints);

                // ask if the user would like to save the file
                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/FitResults.txt",fitResults);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n"; // reset the save choice back to a default of no

                break;

            case 4: // calculate the values of X to the power of Y rounded to a whole number

                // call our calcXtotheY funciton from CustomFunctions.cxx passing it our data
                powerResults = calcXtotheY(vectorOfPoints);

                // ask if the user wants to save the results to a file
                std::cout << "Save the values to a file? (y/n) : ";
                std::cin >> saveChoice;
                if(saveChoice == "y"){
                    output("Outputs/XtotheY.txt",powerResults);
                } else if (saveChoice == "n"){
                    print("File not saved.");
                } else {
                    print("Input not recognised: File not saved.");
                }
                
                saveChoice = "n"; // reset the save choice back to a default of no

                break;
            
            case 5: // exit program

                exitProgram = true;

                break;
            
            default: // error if user submitted value doesn't match any from the list
                print("Invalid Choice Try again");
                break;

        }
        
        // check the the exitProgram variable has already been flagged to avoid asking twice
        if(exitProgram == false){

            std::cout << "Would you like to perform another action (enter 1)? or exit (enter 2) : ";
            std::cin >> continueChoice; 

            // if the user wants to exit put the State back to zero, if not change exitProgram to true
            // if their input doesnt match one of the two options default to keeping the program open
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
// David Riley 15/11/2023 C++ labs
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include "CustomFunctions.h"


int print(std::vector<float> vectorIn){
    // print a pair of values comma separated
    std::cout << vectorIn[0] << " , " << vectorIn[1] << std::endl;
    return 0;
}

int print(float floatToPrint){
    // print a single float
    std::cout << floatToPrint << std::endl;
    return 0;
}

int print(std::string stringToPrint){
    // output a string to cout
    std::cout << stringToPrint << std::endl;
    return 0;
}

int printOutData(int numToRead, std::vector<std::vector<float>> vectorOfPoints){
    
    int numOfPoints = vectorOfPoints.size(); // store the size of the vector, used later to check if the user has chosen too many elements to display

    int i = 0;
    
    if (numToRead > numOfPoints){  // check if the user has selected too many points to be displayed and only display 5

        std::cout << "There are only " << numOfPoints << " datapoints, outputting the first 5 points:" << std::endl;

        while (i < 5){ // iterate over the first 5 values in the vector
            print(vectorOfPoints[i]);
            i++;
        }

    } else { // if the user has chosen a sensible value iterate over the vector printing each value until that corrent amount have been printed

        std::cout << "Outputting the first " << numToRead << " line of data:" << std::endl;

        while (i < numToRead){
            print(vectorOfPoints[i]);
            i++;
        }
    }
    return 0;
}

std::vector<float> getMagnitudes(std::vector<std::vector<float>> vectorOfPoints){

    print("Printing vector magnitudes: ");

    // initialise a variable to store the calculated value in, and a vector to collect all the values together
    float magnitude;
    std::vector<float> vectorOfMagnitudes;

    int i = 0;

    while (i < vectorOfPoints.size()){

        // use the vector magnitide formula, changing the index we use with each loop
        magnitude = sqrt(pow(vectorOfPoints[i][0],2) + pow(vectorOfPoints[i][1],2));
        
        // output each magnitude as it is calculated
        print(magnitude);

        // store the calculated magnitude in the vector
        vectorOfMagnitudes.push_back(magnitude);

        i++;
    }

    return vectorOfMagnitudes; //output the vector
}

std::vector<float> fitStraightLine(std::vector<std::vector<float>> vectorOfPoints){
    // fits a line y = px + q to a vector of datapoints

    float p; // gradient
    float q; // intercept
    int N = vectorOfPoints.size();

    int i = 0;

    // initialise intermediary values used to calculate the values of p and q 
    float sumOfX = 0;
    float sumOfY = 0;
    float sumOfXtimesY = 0;
    float sumOfXsquared = 0;

    while (i < N) {
        sumOfX += vectorOfPoints[i][0]; // sum over all the values of x
        sumOfY += vectorOfPoints[i][1]; // sum over all the values of y
        sumOfXtimesY += vectorOfPoints[i][0] * vectorOfPoints[i][1]; // sum of all the values of X*Y
        sumOfXsquared += vectorOfPoints[i][0]*vectorOfPoints[i][0]; // sum of all the values of X*X

        i++;
    }

    p = (N * sumOfXtimesY - (sumOfX * sumOfY))/(N * sumOfXsquared - (sumOfX * sumOfX)); // combine all our intermediary values into the equation for p
    q = ((sumOfXsquared * sumOfY)-(sumOfXtimesY * sumOfX))/((N * sumOfXsquared)-(sumOfX * sumOfX)); // combine all our intermediary values into the equation for q

    // add the calculated values to a vector of fit parameters
    std::vector<float> fitParams;
    fitParams.push_back(p);
    fitParams.push_back(q);

    // now calculate the X^2/NDF on the data.

    // read in the error values from the file using our readFileToVector
    std::vector<std::vector<float>> vectorOfErrors = readFileToVector("error2D_float.txt");

    float chisq;

    int j = 0;

    while (j < N){
        chisq += pow(vectorOfPoints[j][1] - (p * vectorOfPoints[j][0] + q),2)/pow((vectorOfErrors[j][1]),2); //chi squared formula implementation
        j++; 
    }

    float chisqPerNDF = chisq/(N-2); // calculate chi squared from the number of points minus the number of fit parameters, two in this case

    fitParams.push_back(chisqPerNDF); // add the chi squared to the fit parameters
    
    std::cout << "(p,q,chisq) = (" << fitParams[0] << ", " << fitParams[1] << ", " << fitParams[2] << ")" << std::endl; // print the vector of fit params

    // print(fitParams);

    return fitParams;

}

std::vector<std::vector<float>> readFileToVector(std::string fileName){

    // open a file stream with the name of the file
    std::ifstream inputFile(fileName);

    // check if the file actually opened
    if (!inputFile.is_open()) {
        print("Error opening file!");
    }
    
    // get the first line from the file, removing it from the file stream in the process
    // and print it to double check it acutally was a header
    std::string header;
    std::getline(inputFile,header);
    std::cout << "removed header: " << header << " , from file: " << fileName << std::endl;

    // create a variable to store each line from the file in
    std::string line;

    // create our vector of vectors of floats, to hold our points in
    std::vector<std::vector<float>> vectorOfPoints;

    // while there are still lines in the file iterate over them
    while(std::getline(inputFile,line)){
        float x,y;
        std::string value;

        // create from each line a stringstream, which allows us to then parse through each line and get the individual values from it
        std::stringstream stringStream(line);

        // from each string stream get the first value using "," as a delimiter (this increments through the string stream so the next time you getline it will be the second value)
        std::getline(stringStream,value,',');
        x = stof(value); // convert string to float
        
        // get the second line from the string stream
        std::getline(stringStream,value,',');
        y = stof(value);
        
        // display all the numbers, uncomment VVV to check you're reading in correctly
        // std::cout << x << "," << y << std::endl;

        // now define our structure to hold these two numbers, a vector of floats, and push the values x and y to it
        std::vector<float> pairedNums;
        pairedNums.push_back(x);
        pairedNums.push_back(y);

        // push those paired numbers to the vector of vectors
        vectorOfPoints.push_back(pairedNums);
    }

    return vectorOfPoints;
}

std::vector<float> calcXtotheY(std::vector<std::vector<float>> vectorOfPoints){

    // initialise a structure to store results and intermediary steps in
    std::vector<float> results;
    float result;
    float x;
    float y;

    int i = 0;

    while (i < vectorOfPoints.size()){
        x = vectorOfPoints[i][0]; // x is simply the value in the vector
        y = static_cast<int>(round(vectorOfPoints[i][1])); // y must be rounded and then cast to an integer to allow iteration over it in a loop inside the getPower function
        result = getPower(x,y);
        print(result);
        results.push_back(result); // store the result in our results vector
        i++;
    }

    return results;
}

// calculate a x to the y without using a loop. a power is x times itself y times so we can use recursion, repeatedly mutlitplying x by itself and changing the "power" y until we have the desired number of x's multiplied.
float getPower(float x, int y){

    float result = x; // initialise the result variable as the given value x

    if (y > 1){ // check if the power is still higher than 1, if yes keep recurring
        result = result * getPower(x, y-1); // times x by another call of getPower but this time with y decremented by 1
    }

    return result; 
}

int output(std::string outputName, std::vector<float> vectorOutput){
    
    std::ofstream outputFile; // open a file stream

    outputFile.open(outputName); // name it based on the input

    int i = 0;

    while(i < vectorOutput.size()){ // iterate the number of times for each entry in the file
        outputFile << vectorOutput[i] << std::endl; // read in the values with a newline character to the file
        i++;
    }

    outputFile.close(); // close the filestream

    std::cout << "Data output to file: " << outputName << std::endl;    

    return 0;
}


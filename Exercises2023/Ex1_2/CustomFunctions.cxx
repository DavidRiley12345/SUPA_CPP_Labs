#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include "CustomFunctions.h"


int print(std::vector<float> vectorIn){
    // print a pair of values
    std::cout << vectorIn[0] << " , " << vectorIn[1] << std::endl;
    return 0;
}

int print(float floatToPrint){
    std::cout << floatToPrint << std::endl;
    return 0;
}

int print(std::string stringToPrint){
    // output a string to cout
    std::cout << stringToPrint << std::endl;
    return 0;
}

int printOutData(int numToRead, int numOfPoints, std::vector<std::vector<float>> vectorOfPoints){
    
    int i = 0;
    
    if (numToRead > numOfPoints){

        std::cout << "There are only " << numOfPoints << " datapoints, outputting the first 5 points:" << std::endl;

        while (i < 5){
            print(vectorOfPoints[i]);
            i++;
        }
    } else {

        std::cout << "Outputting the first " << numToRead << " values:" << std::endl;

        while (i < numToRead){
            print(vectorOfPoints[i]);
            i++;
        }
    }
    return 0;
}

std::vector<float> getMagnitudes(std::vector<std::vector<float>> vectorOfPoints){

    print("Printing vector magnitudes: ");

    float magnitude;

    std::vector<float> vectorOfMagnitudes;

    int i = 0;

    while (i < vectorOfPoints.size()){

        magnitude = sqrt(pow(vectorOfPoints[i][0],2) + pow(vectorOfPoints[i][1],2));
        
        print(magnitude);

        vectorOfMagnitudes.push_back(magnitude);

        i++;
    }



    return vectorOfMagnitudes;
}

std::vector<float> fitStraightLine(std::vector<std::vector<float>> vectorOfPoints){
    // fits a line y = px + q to a vector of datapoints

    float p;
    float q;
    int N = vectorOfPoints.size();

    int i = 0;

    float sumOfX = 0;
    float sumOfY = 0;
    float sumOfXtimesY = 0;
    float sumOfXsquared = 0;

    while (i < N) {
        sumOfX += vectorOfPoints[i][0];
        sumOfY += vectorOfPoints[i][1];
        sumOfXtimesY += vectorOfPoints[i][0] * vectorOfPoints[i][1];
        sumOfXsquared += vectorOfPoints[i][0]*vectorOfPoints[i][0];

        i++;
    }

    p = (N * sumOfXtimesY - (sumOfX * sumOfY))/(N * sumOfXsquared - (sumOfX * sumOfX));
    q = ((sumOfXsquared * sumOfY)-(sumOfXtimesY * sumOfX))/((N * sumOfXsquared)-(sumOfX * sumOfX));

    std::vector<float> fitParams;

    fitParams.push_back(p);
    fitParams.push_back(q);

    // now calculate the X^2/NDF on the data.

    std::vector<std::vector<float>> vectorOfErrors = readFileToVector("test_error.txt");

    float chisq;

    int j = 0;

    while (j < N){
        chisq += pow(vectorOfPoints[j][1] - (p * vectorOfPoints[j][0] + q),2)/pow((vectorOfErrors[j][1]),2);
        j++; 
    }

    float chisqPerNDF = chisq/(N-2);

    fitParams.push_back(chisqPerNDF);

    // print the vector of fit params
    
    std::cout << "(p,q,chisq) = (" << fitParams[0] << ", " << fitParams[1] << ", " << fitParams[2] << ")" << std::endl;

    // doesnt work cause my overloaded print only accounts for printing pairs of vectors
    // print(fitParams);

    return fitParams;

}

std::vector<std::vector<float>> readFileToVector(std::string fileName){

    // open a file stream with the name of the file
    std::ifstream inputFile(fileName);
    
    // get the first line from the file, removing it from the file stream in the process
    // and print it to double check it acutally was a header
    std::string header;
    std::getline(inputFile,header);
    std::cout << "removed header: " << header << std::endl;

    // create a variable to store each line from the file in
    std::string line;

    // create our vector of vectors of floats, to hold our points in
    std::vector<std::vector<float>> vectorOfPoints;

    // variable to store how many data points there are in the list
    int numOfPoints = 0;

    // while there are still lines in the file iterate over them
    while(std::getline(inputFile,line)){
        float x,y;
        std::string value;

        // create from each line a stringstream, which allows us to
        std::stringstream stringStream(line);

        std::getline(stringStream,value,',');
        x = stof(value);
        
        std::getline(stringStream,value,',');
        y = stof(value);
        

        // display all the numbers, uncomment to check you're reading in correctly
        // std::cout << x << "," << y << std::endl;

        // now define our structure to hold these two numbers, a vector of floats
        std::vector<float> pairedNums;

        pairedNums.push_back(x);
        pairedNums.push_back(y);

        vectorOfPoints.push_back(pairedNums);

        numOfPoints++;
    }

    return vectorOfPoints;
}



// David Riley 15/11/2023 C++ labs

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

int printOutData(int numToRead, int numOfPoints, std::vector<std::vector<float>> vectorOfPoints){
    
    int i = 0;
    
    if (numToRead > numOfPoints){

        std::cout << "There are only " << numOfPoints << " datapoints, outputting the first 5 points:" << std::endl;

        while (i < 5){
            std::cout << vectorOfPoints[i][0] << "," << vectorOfPoints[i][1] << std::endl;
            i++;
        }
    } else {

        std::cout << "Outputting the first " << numToRead << " values:" << std::endl;

        while (i < numToRead){
            std::cout << vectorOfPoints[i][0] << "," << vectorOfPoints[i][1] << std::endl;
            i++;
        }
    }
    return 0;
}

std::vector<float> getMagnitudes(std::vector<std::vector<float>> vectorOfPoints){

    std::cout << "Printing vector magnitudes: " << std::endl;

    float magnitude;

    std::vector<float> vectorOfMagnitudes;

    int i = 0;

    while (i < vectorOfPoints.size()){

        magnitude = sqrt(pow(vectorOfPoints[i][0],2) + pow(vectorOfPoints[i][1],2));
        
        std::cout << magnitude << std::endl;

        vectorOfMagnitudes.push_back(magnitude);

        i++;
    }



    return vectorOfMagnitudes;
}

std::string fitStraightLine(std::vector<std::vector<float>> vectorOfPoints){
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

    std::cout << "q = " << p << ",q = " << q << std::endl;

    std::string pandq = std::to_string(p) + std::to_string(q);

    return pandq;

}

int main(){

    std::string fileName = "input2D_float.txt";
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
        

        // display all the numbers, uncomment to check youre reading in correctly
        // std::cout << x << "," << y << std::endl;

        // now define our structure to hold these two numbers, a vector of floats
        std::vector<float> pairedNums;

        pairedNums.push_back(x);
        pairedNums.push_back(y);

        vectorOfPoints.push_back(pairedNums);

        numOfPoints++;
    }
 
    std::string userInputStr;
    int numOfLines;

    // now read in a value from the user specifying how many data points the user wants to print
    std::cout << "Enter how many values from the file you would like to print: ";
    std::cin >> userInputStr;

    numOfLines = std::stoi(userInputStr);

    printOutData(numOfLines,numOfPoints,vectorOfPoints);

    // now calculate the magnitude of each data point in the vector

    getMagnitudes(vectorOfPoints);

    // fit a line to the data

    fitStraightLine(vectorOfPoints);

    return 0;
}
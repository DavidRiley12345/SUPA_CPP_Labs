#pragma once
#include <vector>
#include <string>

int print(std::vector<float> vectorIn);

int print(float floatToPrint);

int print(std::string stringToPrint);

int printOutData(int numToRead, int numOfPoints, std::vector<std::vector<float>> vectorOfPoints);

std::vector<float> getMagnitudes(std::vector<std::vector<float>> vectorOfPoints);

std::vector<float> fitStraightLine(std::vector<std::vector<float>> vectorOfPoints);

std::vector<std::vector<float>> readFileToVector(std::string fileName);


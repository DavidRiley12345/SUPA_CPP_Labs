#pragma once
#include <vector>
#include <string>

int printOutData(int numToRead, int numOfPoints, std::vector<std::vector<float>> vectorOfPoints);

std::vector<float> getMagnitudes(std::vector<std::vector<float>> vectorOfPoints);

std::string fitStraightLine(std::vector<std::vector<float>> vectorOfPoints);

std::vector<std::vector<float>> readFileToVector(std::string fileName);


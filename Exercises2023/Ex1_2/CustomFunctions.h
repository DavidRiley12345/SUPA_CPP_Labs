// David Riley 15/11/2023 C++ labs
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

std::vector<float> calcXtotheY(std::vector<std::vector<float>> vectorOfPoints);

float getPower(float x, int y);

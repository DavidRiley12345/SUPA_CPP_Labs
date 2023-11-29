// David 29/11 
#include "FiniteFunctions.h"


int main(){

std::string fileName = "Outputs/data/MysteryData01113.txt";

std::ifstream inputFile(fileName);

std::string line;

std::vector<double> data;

double x;

while(std::getline(inputFile,line)){
    x = stod(line);

    data.push_back(x);
}

FiniteFunction func(-5,5,"outfile");
func.printInfo();
func.plotFunction();
func.plotData(data, 100, true);

return 0;
}
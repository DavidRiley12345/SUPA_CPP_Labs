// David 29/11 
#include "FiniteFunctions.h"
#include "NewFuncs.h"

int main(){

std::string fileName = "Outputs/data/MysteryData01113.txt";

std::ifstream inputFile(fileName);

std::string line;

std::vector<double> data;

double x;
double sum = 0;

while(std::getline(inputFile,line)){
    x = stod(line);
    sum += x;
    data.push_back(x);
}


FiniteFunction func(-10,10,"outfile");
func.printInfo();
func.plotFunction();
func.plotData(data, 99, true);

// from the data calculate the parameters of the potential normal distribution

double mean = sum/data.size();
std::cout << "Mean: " << mean << std::endl;

// calculate the standard deviation

double sum2 = 0;
for(int i = 0; i < data.size(); i++){
    sum2 += pow(data[i]-mean,2);
}

double stdDeviation = sqrt(sum2/data.size());

double width = 5.0;
double numberOfSamples = 20000;

// normal distribution
normalDist func1(-width,width,stdDeviation,mean,"outfile");
func1.printInfo();
func1.plotFunction();
func1.plotData(data,99,true);

std::vector<double> sample1;
// generate a sample of the normal distribution
sample1 = func1.sampleFunction(numberOfSamples,0.0);

// plot the sample
func1.plotData(sample1,99,false);

//---------------------------------------------------------------------------------------------

// cauchy lorenz
cauchyLorenz func2(-width,width,stdDeviation+1,mean,"outfile");
func2.printInfo();
func2.plotFunction();
func2.plotData(data,99,true);

// generate a sample of the cauchy lorenz distribution
std::vector<double> sample2;
sample2 = func2.sampleFunction(numberOfSamples,0.0);

// plot the sample
func2.plotData(sample2,99,false);

//---------------------------------------------------------------------------------------------
// crystal ball
crystalBall func3(-width,width,1.2,3,mean+0.5,stdDeviation-0.7,"outfile");
func3.printInfo();
func3.plotFunction();
func3.plotData(data,99,true);

// generate a sample of the crystal ball distribution
std::vector<double> sample3;
sample3 = func3.sampleFunction(numberOfSamples,0.0);

// plot the sample
func3.plotData(sample3,99,false);


return 0;
}
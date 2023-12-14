#include <cmath>
#include <iostream>
#include <random>

int main(){

    std::vector<std::vector<double>> samples;

    int numberOfSamples = 1000000;

    std::random_device rd;
    std::mt19937 mtEngine(rd());
    std::uniform_real_distribution<double> dist(-1.0,1.0);

    for(int i=0; i<numberOfSamples; i++){
        double x = dist(mtEngine);
        double y = dist(mtEngine);
        std::vector<double> sample;
        sample.push_back(x);
        sample.push_back(y);
        samples.push_back(sample);
        
        //output the sample as a rough check that the nunbers are random
        //std::cout << "x: " << x << " y: " << y << std::endl;
    }

    int numberOfSamplesInside = 0;

    for(int i=0; i<numberOfSamples; i++){
        double x = samples[i][0];
        double y = samples[i][1];
        if(sqrt(x*x+y*y) < 1.0){
            numberOfSamplesInside++;
        }
    }   

    double pi = 4.0*numberOfSamplesInside/numberOfSamples;

    std::cout << "Pi: " << pi << std::endl;
}
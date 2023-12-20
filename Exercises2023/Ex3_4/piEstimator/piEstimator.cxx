#include <cmath>
#include <iostream>
#include <random>

int main(int argc, char *argv[]){

    float radius = 1.0;
    float numberOfSamples = 10000;

    if (argc == 3){
        radius = std::stof(argv[1]);
        numberOfSamples = std::stoi(argv[2]);
        std::printf("Using values: radius = %.2f, numberOfSamples = %.0f\n",radius,numberOfSamples);
    } else if (argc != 1 && argc != 3){
        std::cout << "Usage: ./piEstimator [radius] [numberOfSamples]" << std::endl;
        return 0;
    } else {
        std::printf("Using default values: radius = %.2f, numberOfSamples = %.0f\n",radius,numberOfSamples);
    }

    std::vector<std::vector<double>> samples;

    std::random_device rd;
    std::mt19937 mtEngine(rd());
    std::uniform_real_distribution<double> dist(-radius,radius);

    for(int i=0; i<numberOfSamples; i++){
        double x = dist(mtEngine);
        double y = dist(mtEngine);
        std::vector<double> sample;
        sample.push_back(x);
        sample.push_back(y);
        samples.push_back(sample);
        
        //output the sample as a rough check that the numbers are random-ish
        //std::cout << "x: " << x << " y: " << y << std::endl;
    }

    int numberOfSamplesInside = 0;

    for(int i=0; i<numberOfSamples; i++){
        double x = samples[i][0];
        double y = samples[i][1];
        if(sqrt(x*x+y*y) < radius){
            numberOfSamplesInside++;
        }
    }   

    double pi = 4.0*numberOfSamplesInside/numberOfSamples;

    std::printf("Pi: %.10f\n",pi);
}
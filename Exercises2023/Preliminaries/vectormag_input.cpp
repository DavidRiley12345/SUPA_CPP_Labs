#include <iostream>
#include <cmath>

int main(){
    // initialise x and y input variables
    float x;
    float y;
    std::string x_input;
    std::string y_input;

    // read in variables from cin streams
    std::cout << "Please input a value x: ";
    std::getline(std::cin,x_input);
    std::cout << "Please input a value y: ";
    std::getline(std::cin,y_input);

    // convert x_input and y_input to floats stored in x and y
    x = std::stof(x_input);
    y = std::stof(y_input);

    // double check the values read in correctly
    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;

    // compute the vector magnitude
    double vectormag = std::sqrt(x*x + y*y);
    std::cout << vectormag << std::endl;
}
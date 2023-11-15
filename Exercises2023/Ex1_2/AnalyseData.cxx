#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main(){

    std::string filename = "input2D_float.txt";
    std::ifstream input_file(filename);

    std::string line;

    while(std::getline(input_file,line)){
        float x,y;
        std::string value;

        std::stringstream stringst(line);
        std::getline(stringst,value,',');
        std::cout << value << std::endl;
        x = std::stof(value);
        
        std::getline(stringst,value,',');
        y = std::stof(value);
        std::cout << x << y << std::endl;
    }

    return 0;
}
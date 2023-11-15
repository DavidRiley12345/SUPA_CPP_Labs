#include <iostream>
#include <cmath>

int main(){
    float x = 2.3;
    float y = 4.5;

    float vec_mag = sqrt(pow(x,2) + pow(y,2));

    std::cout << vec_mag << std::endl;
    return 0;
}
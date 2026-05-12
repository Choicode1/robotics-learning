//cpp 배열 실습

#include <iostream>

int main() {
    double distances[5] = {1.2, 0.8, 2.5, 0.4, 1.0};

    std::cout << "Sensor 0 distance: " << distances[0] << " m" << std::endl;
    std::cout << "Sensor 1 distance: " << distances[1] << " m" << std::endl;
    std::cout << "Sensor 2 distance: " << distances[2] << " m" << std::endl;
    std::cout << "Sensor 3 distance: " << distances[3] << " m" << std::endl;
    std::cout << "Sensor 4 distance: " << distances[4] << " m" << std::endl;

    return 0;
}
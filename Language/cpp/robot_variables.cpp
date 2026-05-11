#include <iostream>
#include <string>

int main() {
    int battery = 85;
    double speed = 1.25;
    bool obstacle_detected = false;
    char robot_grade = 'A';
    std::string robot_name = "turtlebot3";

    std::cout << "Robot name: " << robot_name << std::endl;
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Speed: " << speed << " m/s" << std::endl;
    std::cout << "Obstacle detected: " << obstacle_detected << std::endl;
    std::cout << "Robot grade: " << robot_grade << std::endl;

    return 0;
}

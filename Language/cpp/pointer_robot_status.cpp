#include <iostream>

struct RobotStatus {
	int battery;
	double speed;
};

int main() {
	RobotStatus status;
	status.battery = 80;
	status.speed = 0.5;
	
	RobotStatus* status_ptr = &status;
	
	std::cout << "Battery: " << status_ptr -> battery << "%" << std::endl;
	std::cout << "Speed: " << status_ptr -> speed << " m/s" << std::endl;
	
	status_ptr -> battery = 50;
	status_ptr -> speed = 1.2;
	
	std::cout << "===== After update =====" << std::endl;
	std::cout << "Battery: " << status.battery << "%" << std::endl;
	std::cout << "Speed: " << status.speed << " m/s" << std::endl;
	
	return 0;
}
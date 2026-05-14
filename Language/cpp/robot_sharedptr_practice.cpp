//1. RobotStatus 구조체를 만든다.
//   - std::string name
//   - int battery
//   - double speed
//
//2. 구조체 안에 다음 별칭을 만든다.
//   using SharedPtr = std::shared_ptr<RobotStatus>;
//
//3. print_status 함수를 만든다.
//   - 매개변수: const RobotStatus::SharedPtr msg
//   - msg->name, msg->battery, msg->speed 출력
//
//4. main에서 std::make_shared<RobotStatus>()로 객체를 만든다.
//
//5. 값을 설정한다.
//   - name = "turtlebot3"
//   - battery = 90
//   - speed = 0.8
//
//6. print_status(msg)를 호출한다.

#include <iostream>
#include <memory>
#include <string>

struct RobotStatus{
	using SharedPtr = std::shared_ptr<RobotStatus>;
	
	std::string name;
	int battery;
	double speed;
};

void print_status(const RobotStatus::SharedPtr msg) {
	std::cout << "===== Robot Status =====" << std::endl;
	std::cout << "Name: " << msg -> name << std::endl;
	std::cout << "Battery: " << msg -> battery << "%" << std::endl;
	std::cout << "Speed: " << msg -> speed << " m/s" << std::endl;
}

int main(){
	RobotStatus::SharedPtr msg = std::make_shared<RobotStatus>();
	
	msg -> name = "turtlebot3";
	msg -> battery = 90;
	msg -> speed = 0.8;
	
	print_status(msg);
	
	return 0;
}
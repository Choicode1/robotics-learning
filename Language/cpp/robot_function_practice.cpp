//조건문 실습

#include <iostream>
#include <string>


//1. get_battery_status(int battery) 함수를 만든다.
//   - 70 이상이면 "Normal"
//   - 30 이상이면 "Warning"
//   - 그 외에는 "Low"
//
std::string get_battery_status(int battery){
	std::string ret = "-";
	bool cond1 = battery >= 70;
	bool cond2 = battery >= 30;
	if (cond1){
		ret = "Normal";
	} else if (cond2){
		ret = "Warning";   
	} else {
		ret = "Low";
	}
	return ret;
}
//2. is_obstacle_dangerous(double distance) 함수를 만든다.
//   - distance가 0.5 미만이면 true
//   - 아니면 false
//
bool is_obstacle_dangerous(double distance){
	bool ret = false;
	if(distance < 0.5){
		ret = true;
	}
	return ret;
}
//3. calculate_safe_speed(double target_speed, bool obstacle_dangerous) 함수를 만든다.
//   - obstacle_dangerous가 true이면 0.0 반환
//   - target_speed가 1.5보다 크면 1.5 반환
//   - 그 외에는 target_speed 반환
//
double calculate_safe_speed(double target_speed, bool obstacle_dangerous){
	double ret = 0.0;
	if(obstacle_dangerous){
		
	} else if(target_speed > 1.5){
		ret = 1.5;
	} else {
		ret = target_speed;
	}
	return ret;
}
//4. main에서 다음 값으로 테스트한다.
//   - battery = 25
//   - distance = 0.3
//   - target_speed = 1.2
//
int main(){
	int battery = 25;
	bool obstacle_dangerous = false;
	double distance = 0.3;
	double target_speed = 1.2;
	std::cout << "Battery status: [" << get_battery_status(battery) << "]" << std::endl;
	std::cout << std::boolalpha << "Obstacle dangerous: [" << is_obstacle_dangerous(distance) << "]" << std::endl;
	std::cout << "Safe speed: [" << calculate_safe_speed(target_speed, obstacle_dangerous) << "]" << std::endl;
	
	return 0;
}
//5. 출력 예:
//   Battery status: Low
//   Obstacle dangerous: true
//   Safe speed: 0

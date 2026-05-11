#include <iostream>
#include <string>

int main(){
	int battery = 10;
	double distance_to_obstacle = 0.4;
	bool emergency_stop = false;
	
	bool battery_low = battery < 20;
	bool obstacle_too_close = distance_to_obstacle < 0.5;
	bool unsafe = battery_low || obstacle_too_close || emergency_stop;
	
	if (battery_low){
		std::cout << "Battery low. Stop." << std::endl;
	}
	if (obstacle_too_close){
		std::cout << "Obstacle too close. Stop." << std::endl;
	}
	if (unsafe){
		std::cout << "Robot cannot move." << std::endl;
	} else {
		std::cout << "Robot can move." << std::endl;
	}
	
//4. 배터리가 20 미만이면 "Battery low. Stop." 출력
//5. 장애물 거리가 0.5m 미만이면 "Obstacle too close. Stop." 출력
//6. emergency_stop이 true이면 "Emergency stop pressed." 출력
//7. 위 조건 중 하나라도 해당하면 "Robot cannot move." 출력
//8. 모든 조건이 안전하면 "Robot can move." 출력	
	return 0;
}
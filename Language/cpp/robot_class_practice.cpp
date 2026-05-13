#include <iostream>
#include <string>
#include <vector>


//1. RobotMonitor 클래스를 만든다.
//
//2. private 멤버 변수:
//   - std::string robot_name_
//   - int battery_
//   - double distance_to_obstacle_
//   - bool emergency_stop_
//
//3. 생성자에서 다음 값을 초기화한다.
//   - robot_name_은 생성자 매개변수로 받는다.
//   - battery_ = 100
//   - distance_to_obstacle_ = 10.0
//   - emergency_stop_ = false
//
//4. public 멤버 함수:
//   - update_status(int battery, double distance, bool emergency_stop)
//   - bool is_safe()
//   - void print_report()
//
//5. is_safe() 조건:
//   - battery_가 20 이상
//   - distance_to_obstacle_이 0.5 이상
//   - emergency_stop_이 false
//
class RobotMonitor{
	public:
		RobotMonitor(const std::string& robot_name)
		: robot_name_(robot_name)
		, battery_(100)
		, distance_to_obstacle_(10.0)
		, emergency_stop_(false)
		{
		}
		
		void update_status(int battery, double distance, bool emergency_stop){
			
		}
		bool is_safe(){
			bool ret = false;
			bool cond_battery = (battery_ >= 20);
			bool cond_dist = (distance_to_obstacle_ >= 0.5);
			bool cond_emerg = ( !emergency_stop_ );
			ret = cond_battery && cond_dist && cond_emerg;
			return ret;
		}
				
		void print_report(){
			std::cout << std::boolalpha;
			std::cout << "===== Robot Monitor Report =====" << std::endl;
			std::cout << "Name: " << robot_name_ << std::endl;
			std::cout << "Battery: " << battery_ << "%" << std::endl;
			std::cout << "Distance to obstacle: " << distance_to_obstacle_ << " m" << std::endl;
			std::cout << "Emergency stop: " << emergency_stop_ << std::endl;
			std::cout << "Safe: " << is_safe() << std::endl;
		}
	private:
		std::string robot_name_;
		int battery_;
		double distance_to_obstacle_;
		bool emergency_stop_;
};
//6. main에서 RobotMonitor 객체를 만들고,
//   update_status(15, 1.0, false)를 호출한 뒤
//   print_report()를 실행한다.
int main(){
	std::string robot_name = "myj_robot";
	RobotMonitor monitor(robot_name);
	
	monitor.update_status(15, 1.0, false);
	monitor.print_report();

	return 0;
}
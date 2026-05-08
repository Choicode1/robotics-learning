#include <iostream>
#include <string>

int main(){
	int ret = 1;
	//0.문자열 변수 선언
	std::string robot_desc = "-";
	//1.타이틀 출력
	std::cout << "Enter Desc: ";
	//2.설명 입력
	//std::cin >> robot_desc; //2026/05/07 입력 파싱 에러 -> 라인 리드로 변경
	std::getline(std::cin, robot_desc);
	//3.입력한 설명 출력
	std::cout << robot_desc << std::endl;
	//4.반환값 변경
	ret = 0;
	return ret;
}
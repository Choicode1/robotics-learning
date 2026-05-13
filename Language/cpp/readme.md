struct는 명사 묶음
class는 명사+동사 묶음가능

struct는 public 원칙
class는 private 원칙 -> 그래서 class에서는 보통 public, private를 명시해준다.


class 클래스이름 {
public:
    외부에서 사용할 수 있는 함수 또는 변수

private:
    외부에서 직접 접근하지 못하게 보호할 변수 또는 함수
};

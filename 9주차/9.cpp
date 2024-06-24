#include <iostream>
using namespace std;

class Circle {
    int radius;

public:
    Circle(int radius = 0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " 인 원" << endl; }

    Circle operator++() {
        radius++;
        return *this;
    }

    Circle operator++(int x) {
        Circle tmp(radius);
        radius++;
        return tmp;
    }
    
    Circle operator= (const Circle& a) {
        radius = a.radius;
        return *this;
    } // 객체의 반지름을 복사

    friend Circle operator+ (int, Circle);
};

Circle operator+ (int n, Circle a) {
    a.radius += n;
    return a;
}
// 정수 + 객체 순서의 더하기 순서를 명시하기위해 외부함수로 작성,
// friend함수로 Circle객체의 반지름 값에 접근할 수 있음
// 1 + a를 할 때 a의 값을 바꿔서 리턴을 하는 것이 아니라 a의 값을 불러와 n만큼 반지름을 증가시키고 리턴
    

int main() {
    Circle a(5), b(4);
    b = 1 + a; // b의 반지름을 a의 반지름에 1을 더한 것으로 변경
    a.show();
    b.show();
}
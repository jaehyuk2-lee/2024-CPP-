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
    // 전위 연산자의 표현, 값을 먼저 증가한 뒤 그 값을 리턴한다.
    // return 타입이 Circle인 이유는 ++a 이후 다른 연산을 시행할 수 있기 때문에 자신의 값을 리턴한다.

    Circle operator++(int x) {
        Circle tmp(radius);
        radius++;
        return tmp;
    }
    // 후위 연산자의 표현, 값을 증가시키긴 하지만 증가시키기 전의 값을 리턴한다.
    // 반지름을 증가시키기 전의 값으로 객체를 생성한다. 자신의 반지름의 값을 증가시키고, 생성한 객체를 리턴한다.
};

int main() {
    Circle a(5), b(4);
    ++a;     // 반지름을 1 증가 시킨다.
    b = a++; // 반지름을 1 증가 시킨다.
    a.show();
    b.show();
}
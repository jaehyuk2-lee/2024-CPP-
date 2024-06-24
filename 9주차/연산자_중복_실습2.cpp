#include <iostream>
using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(int radius = 0) {
        this->radius = radius;
    }
    void show() {
        cout << "radius = " << radius << "인 원" << endl;
    }

    void operator *= (int x) {
        radius *= 2;
    }
    void operator -= (const Circle& a) { // 연산객체 보호
        radius -= a.radius;
    }
    Circle operator << (int x) {
        Circle tmp(radius);
        tmp.radius+=x;
        return tmp;
    }
    Circle operator = (const Circle& a) {
        radius = a.radius;
        return *this;
    }
};

int main() {
    Circle a(5), b(10);
    Circle c;
    a *= 2;
    b -= a;
    c = a << 2;
    a.show();
    b.show();
    c.show();
}
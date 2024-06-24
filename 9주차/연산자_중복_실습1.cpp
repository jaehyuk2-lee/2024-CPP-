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

    friend void operator *= (Circle&, int);
    friend void operator -= (Circle&, const Circle&); // 연산객체보호
    friend Circle& operator << (Circle, int);
    Circle operator = (const Circle& a) {
        radius = a.radius;
        return *this;
    }
};

void operator *= (Circle& a, int x) {
    a.radius *= 2;
}
void operator -= (Circle& a, const Circle& b) {
    a.radius -= b.radius;
}
Circle& operator << (Circle a, int x) {
    a.radius += x;
    return a;
}

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
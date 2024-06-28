#include <iostream>
using namespace std;

class Circle {
    int radius; // 객체를 교환하기 위해 선언하는 변수
public:
    Circle() {
        radius = 1;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    int getRadius() {
        return this->radius;
    }
};

void swap(Circle&, Circle&); // Circle객체의 레퍼런스가 매개변수로 들어오는 것을 의미

int main() {
    Circle c1, c2;
    c1.setRadius(10);
    c2.setRadius(20);
    cout << "c1.radius : " << c1.getRadius() << " c2.radius : " << c2.getRadius() << "\n";
    // 반지름의 값이 변경되기 전의 값을 출력

    swap(c1, c2); // 반지름의 값을 변경
    cout << "c1.radius : " << c1.getRadius() << " c2.radius : " << c2.getRadius() << "\n";
    // 변경된 반지름을 출력
}

void swap(Circle& a, Circle& b) {
    // 매개변수로 들어온 객체 reference는 새로운 객체를 만들어서 복사를 하는 것이 아니라
    // main()에서 전달된 객체 그 자체가 된다. 따라서 a의 반지름을 변경하면 먼저 전달된 c1의 반지름값이 변한다.
    int tmp;
    tmp = a.getRadius();
    a.setRadius(b.getRadius());
    b.setRadius(tmp);
}
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r) { radius = r; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

void increaseBy1(Circle a, Circle b) {
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
}
// 위 함수는 main()에서 넘겨받은 Circle객체를 a와 b라는 새로운 객체 치환한다.
// a와 b 객체는 함수가 종료될때 사라지며 실제 x객체의 값을 변화시킨 것은 아니다.

void increaseBy2(Circle& a, Circle& b) {
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
} // x객체의 반지름 값이 함수내부에서 변경되는 것을 원하기 때문에 x로 전달받는 매개변수는 레퍼런스 변수를 사용해 직접 값을 변경한다.
  // y객체는 증가하는 반지름의 크기의 정보이기 때문에 레퍼런스로 사용하지 않아도 된다. 레퍼런스 변수로 사용하면 메모리를 절약할 수 있다.

int main() {
    Circle x(10), y(5);
    increaseBy1(x, y);
    x.show();

    increaseBy2(x, y);
    x.show();
}
#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }

protected:
    void move(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // 상속받은 클래스에서만 접근가능
};

class ColorPoint : public Point {
    string color;
public:
    ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) {
        this->color = color;
    }
    // 좌표는 생성될 때만 초기화 할 수 있기 때문에 자식 클래스에서 부모클래스의 매개변수 생성자를 호출
    // 실행되는 순서는 부모클래스가 먼저 실행되지만 호출은 자식클래스가 먼저 호출되기 때문에 
    // 부모클래스의 매개변수 생성자를 호출가능

    // 기본생성자로 생성한 좌표는 BLACK색에 (0,0) 좌표, 따라서 디폴트 매개변수 설정

    void setPoint(int x, int y) {
        move(x, y);
    }
    // x, y를 전달받았을 때 부모클래스의 멤버함수를 통해 좌표값을 재설정
    // move()함수는 protected 접근지정자로 자식클래스에서만 접근할 수 있다.
    // 따라서 외부에서 객체.move()를 사용할 수 없고 ColorPoint객체.setPoint()로 move를 호출한다.

    void setColor(string color) {
        this->color = color;
    } // 전달받은 값으로 멤버변수 재설정

    void show() {
        cout << this->color << "색으로 " << "(" << getX() << ", " << getY() << ")에 위치한 점입니다.\n";
    }
    // x, y의 값은 private이기 때문에 자식클래스에서도 접근 불가능
    // 따라서 멤버함수를 통해서 값을 리턴
};

int main() {
    ColorPoint zeroPoint; // BLACK 색에 (0, 0) 위치의 점
    zeroPoint.show(); // zeroPoint를 출력한다.

    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show(); // cp를 출력한다.
}
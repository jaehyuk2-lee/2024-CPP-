#include <iostream>
using namespace std;

class Oval {
public:
    Oval() {
        width = 1;
        height = 1;
    } // 매개변수 없이 생성되면 넓이와 폭을 1로 설정
    Oval(int w, int h) {
        width = w;
        height = h;
    } // 매개변수를 포함하면 멤버 변수에 각각 입력
    void set(int w, int h) {
        width = w;
        height = h;
    } // 새롭게 설정할 넓이와 폭의 매개변수를 입력받고, 멤버 변수에 입력
    void show() {
        cout << "width = " << width << ", height = " << height << endl;
    }

    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    // 각각의 멤버를 리턴하는 메소드

    ~Oval() {
        cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
    } // 소멸자를 선언해 객체가 해제될 때 멤버 변수의 값들을 출력해주고 해제

private: // 폭과 높이를 저장할 멤버 변수
    int width, height;
};

int main() {
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << "," << b.getHeight() << endl;
}
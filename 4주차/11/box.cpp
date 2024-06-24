#include <iostream>
#include "box.h" // class 원형 포함하는 헤더파일
using namespace std;

void Box::setSize(int w, int h) {
    width = w;
    height = h;
} // 박스의 크기 설정 구현

void Box::setFill(char c) {
    fill = c;
} // 박스를 채울 문자 설정 구현

void Box::draw() {
    for (int n = 0; n < height; n++) {
        for (int m = 0; m < width; m++) {
            cout << fill;
        }
        cout << endl;
    }
} // width 만큼 가로줄 출력, height 만큼 반복, 총 width * height 크기의 상자출력

int main() {
    Box b(10, 2);
    b.draw(); // 박스를 그린다.
    cout << endl;
    b.setSize(7, 4); // 박스의 크기를 변경한다.
    b.setFill('^');  // 박스의 내부를 채울 문자를 '^'로 변경한다.
    b.draw();        // 박스를 그린다.
}
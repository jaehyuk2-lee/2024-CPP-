#include "실습과제11_Box.h" // class 원형 포함하는 헤더파일


Box::Box(int w, int h) {
    setSize(w, h);
    fill = '*'; // 기본적으로 * 출력
} // 객체가 생성될 때 받는 매개변수로 setSize함수 사용

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
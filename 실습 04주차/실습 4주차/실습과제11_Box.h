#ifndef BOX_H // 만약 정의 되지 않았다면 정의
#define BOX_H
#include <iostream>
using namespace std;

class Box {
public:
    Box(int, int); // 객체가 생성될 때 받는 매개변수로 setSize함수 사용
    void setSize(int, int); // 박스의 크기 설정하기
    void setFill(char); // 박스를 채울 문자 바꾸기
    void draw(); // 박스 그리기

private:
    int width, height;
    char fill; // 박스의 내부를 채우는 문자
};
#endif
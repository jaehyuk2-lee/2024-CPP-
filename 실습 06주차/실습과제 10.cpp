#include <iostream>
#include <string>
using namespace std;


class Buffer {
    string text;

public:
    Buffer(string text) { this->text = text; }
    void add(string next) { text += next; } // text에 next 문자열 덧붙이기
    void print() { cout << text << endl; }
};

Buffer& append(Buffer& buf, string str) {
    buf.add(str);
    return buf; // buf객체에 문자열을 추가한 뒤 레퍼런스를 반환한다 매개변수와 리턴받는 객체 모두 같은 객체이다.
} // 버퍼 참조를 반환하는 함수, 입력받은 객체에 문자열이 추가되야하기 때문에, 레퍼런스 변수로 매개변수를 받는다

int main() {
    Buffer buf("Hello");
    Buffer& temp = append(buf, "Guys"); // buf의 문자열에 "Guys" 덧붙임
    temp.print();                       // "HelloGuys" 출력
    buf.print();                        // "HelloGuys" 출력

    buf.add("123");                     // buf의 문자열에 123을 추가
    temp.print();                       // temp는 buf의 레퍼런스이기 때문에 buf에 문자열을 추가하면 temp로 출력해도 추가된 값이 출력된다.
    buf.print();
}
#include <iostream>
#include <string>
using namespace std;

class Integer {
public:
    Integer(int);
    // 객체가 생성될 때 정수형을 매개변수로 받을 경우 num에 저장한다.
    Integer(string);
    // 객체가 생성될 때 문자열을 매개변수로 받을 경우 int로 바꾼후 저장한다

    int get();
    // 객체내부의 num의 값을 반환한다.
    void set(int);
    // 매개변수로 입력받은 정수로 num의 값을 설정한다.
    void set(string s);
   // 매개변수로 입력받은 문자열을 num의 값으로 설정한다.
    int isEven();
    // num에 저장되어 있는 값이 짝수면 1 그렇지 않으면 0을 반환한다.
private:
    int num;
};

// 클래스 선언부에 구현된 함수는 컴파일러가 자동으로 인라인 처리를 해준다.
Integer::Integer(int n) {
    num = n;
}
Integer::Integer(string s) {
    num = stoi(s);
}
int Integer::get() {
    return num;
}
void Integer::set(int n) {
    num = n;
}
void Integer::set(string s) {
    num = stoi(s);
}
int Integer::isEven() {
    if (num % 2 == 0) {
        return 1;
    }
    else return 0;
}

int main() {
    Integer n(30);
    cout << n.get() << ' '; // 30 출력
    n.set(50);
    cout << n.get() << ' '; // 50 출력
    Integer m("300");
    cout << m.get() << ' '; // 300 출력
    n.set("500"); // 500으로 설정
    cout << m.get() << ' '; // 500 출력
    cout << m.isEven();     // true(정수로 1) 출력
}

#include <iostream>
#include <string>
using namespace std;

class Integer {
public:
    Integer(int n) {
        num = n;
    } // 객체가 생성될 때 정수형을 매개변수로 받을 경우 num에 저장한다.
    Integer(string s) {
        num = stoi(s);
    } // 객체가 생성될 때 문자열을 매개변수로 받을 경우 int로 바꾼후 저장한다

    int get() {
        return num;
    } // 객체내부의 num의 값을 반환한다.
    void set(int n) {
        num = n;
    } // 매개변수로 입력받은 정수로 num의 값을 설정한다.
    void set(string s) {
        num = stoi(s);
    } // 매개변수로 입력받은 문자열을 num의 값으로 설정한다.
    int isEven() {
        if(num%2 == 0) {
            return 1;
        }
        else return 0;
    } // num에 저장되어 있는 값이 짝수면 1 그렇지 않으면 0을 반환한다.
private:
    int num;
};

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

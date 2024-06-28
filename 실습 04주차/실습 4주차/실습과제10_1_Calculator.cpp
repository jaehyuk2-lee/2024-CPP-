#include <iostream>
using namespace std;

class Add {
public:
    void SetValue(int, int);
    void calculate();

private:
    int num1, num2;
};
class Sub {
public:
    void SetValue(int, int);
    void calculate();

private:
    int num1, num2;
};
class Mul {
public:
    void SetValue(int, int);
    void calculate();

private:
    int num1, num2;
};
class Div {
public:
    void SetValue(int, int);
    void calculate();

private:
    int num1, num2;
};
// 같은 종류의 멤버변수와 메소드를 가지고 있는 객체들을 생성

void Add::SetValue(int a, int b) {
    num1 = a;
    num2 = b;
}
void Sub::SetValue(int a, int b) {
    num1 = a;
    num2 = b;
}
void Mul::SetValue(int a, int b) {
    num1 = a;
    num2 = b;
}
void Div::SetValue(int a, int b) {
    num1 = a;
    num2 = b;
}
// 매개변수의 값을 멤버 변수에 복사해주는 메소드 선언

void Add::calculate() {
    cout << num1 + num2 << endl;
}
void Sub::calculate() {
    cout << num1 - num2 << endl;
}
void Mul::calculate() {
    cout << num1 * num2 << endl;
}
void Div::calculate() {
    if (num2 == 0) {
        cout << "divided 0 error" << endl;
    }
    else cout << num1 / num2 << endl;
}
// 각각 다른값을 리턴하는 calcurate 메소드 구현, 0으로 나눌때는 에러 출력 후 0 리턴

int main() {
    int num1, num2; // 입력받은 숫자가 저장될 변수
    char op; // 계산 식이 입력될 변수
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (1) { // 무한반복
        cout << "두 정수와 연산자를 입력하세요. >> ";
        cin >> num1 >> num2 >> op;

        switch (op) {
        case '+':
            a.SetValue(num1, num2);
            a.calculate();
            break;

        case '-':
            s.SetValue(num1, num2);
            s.calculate();
            break;

        case '*':
            m.SetValue(num1, num2);
            m.calculate();
            break;

        case '/':
            d.SetValue(num1, num2);
            d.calculate();
            break;

        default:
            break;
        }
    }
}
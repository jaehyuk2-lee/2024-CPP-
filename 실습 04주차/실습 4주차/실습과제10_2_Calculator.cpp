#include <iostream>
#include "�ǽ�����10_2_Calculator.h" // class�� ������ ����
using namespace std;

int main() {
    int num1, num2; // �Է¹��� ���ڰ� ����� ����
    char op; // ��� ���� �Էµ� ����
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (1) { // ���ѹݺ�
        cout << "�� ������ �����ڸ� �Է��ϼ���. >> ";
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

// ������Ͽ� ����� �޼ҵ���� ����
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
// �Ű������� ���� ��� ������ �������ִ� �޼ҵ� ����

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
// ���� �ٸ����� �����ϴ� calcurate �޼ҵ� ����, 0���� �������� ���� ��� �� 0 ����
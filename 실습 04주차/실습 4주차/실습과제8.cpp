#include <iostream>
#include <string>
using namespace std;

class Integer {
public:
    Integer(int);
    // ��ü�� ������ �� �������� �Ű������� ���� ��� num�� �����Ѵ�.
    Integer(string);
    // ��ü�� ������ �� ���ڿ��� �Ű������� ���� ��� int�� �ٲ��� �����Ѵ�

    int get();
    // ��ü������ num�� ���� ��ȯ�Ѵ�.
    void set(int);
    // �Ű������� �Է¹��� ������ num�� ���� �����Ѵ�.
    void set(string s);
   // �Ű������� �Է¹��� ���ڿ��� num�� ������ �����Ѵ�.
    int isEven();
    // num�� ����Ǿ� �ִ� ���� ¦���� 1 �׷��� ������ 0�� ��ȯ�Ѵ�.
private:
    int num;
};

// Ŭ���� ����ο� ������ �Լ��� �����Ϸ��� �ڵ����� �ζ��� ó���� ���ش�.
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
    cout << n.get() << ' '; // 30 ���
    n.set(50);
    cout << n.get() << ' '; // 50 ���
    Integer m("300");
    cout << m.get() << ' '; // 300 ���
    n.set("500"); // 500���� ����
    cout << m.get() << ' '; // 500 ���
    cout << m.isEven();     // true(������ 1) ���
}

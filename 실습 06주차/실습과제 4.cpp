#include <iostream>
using namespace std;

bool bigger(int, int, int&);

int main() {
    int num1, num2, big;
    cout << "���� 2�� �Է� : ";
    cin >> num1 >> num2;

    if (bigger(num1, num2, big)) { // �Լ��� true�� ��ȯ�ߴٸ� �� ���� ���� ������ ����
        cout << "�� ���� �����ϴ�.\n";
    }
    else cout << big << "�� �� ū ���Դϴ�.\n"; // false�̸� ū ���� big�� ���޵Ǿ��� ������ big�� ���

    return 0;
}

bool bigger(int a, int b, int& big) {
    // big�� ���� ū ���� �����ϸ� �Ǳ� ������ num1, num2�� ���۷��� ������ ������� �ʾƵ� �ȴ�.
    if (a == b) {
        return true;
    }
    else if (a > b) {
        big = a;
        return false;
    }
    else {
        big = b;
        return false;
    }
}
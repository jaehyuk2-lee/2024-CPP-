#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "�� ���� �Է��϶�>> ";
    cin >> num1 >> num2; // cin�� ���� �������� �ΰ��� ���� ������ �Է¹޴´�.

    if (num1 > num2) {
        cout << "ū�� = " << num1 << "\n";
    }
    else cout << "ū�� = " << num2 << "\n";
    // �μ��� ���� ū ���� ����Ѵ�.

    return 0;
}
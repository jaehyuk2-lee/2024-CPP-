#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "�Ʒ��� ������ �Է��� �ּ���. (exit�� �Է��ϸ� �����մϴ�.)\n";

    while (1) {
        cout << ">>";
        getline(cin, str); // ������ �����ؼ� ���ڿ� �Է�
        if (str == "exit") break; // exit�� �Է¹޾����� �ݺ�����

        for (int i = str.length() - 1; i >= 0; i--) {
            cout << str[i];
        }
        // stringŬ������ length()�Լ��� ���� ���ڿ��� ���̸� ��ȯ�޾�, ���ڿ��� ������ ��Һ��� ó������ ���
        cout << '\n';
    }
}
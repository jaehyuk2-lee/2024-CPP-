#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    while (strcmp("yes", str) != 0) {
        // strcmp�� �� ���ڿ��� ������ 0�� ��ȯ�ϱ� ������ yes�� �ƴѵ��� ��� �ݺ��Ѵ�.
        cout << "�����ϰ� ������ yes�� �Է��ϼ���. >>";
        cin.getline(str, 100); // ���鹮�ڸ� �����ؼ� �Է¹ޱ����� getline()�Լ��� ����Ѵ�.
    }
    cout << "�����մϴ�...\n";
    return 0;
}
#include <iostream>
#include <string> // ���ڿ��� �Է¹޴� getline()�Լ��� ����ϱ����� �����Ѵ�.
using namespace std;

int main()
{
    string name;
    string address;
    int age;

    cout << "�̸���?";
    getline(cin, name); // string�ڷ��� name�� �� ���� �Է¹޴´�, ���������� �����ϴ�.
    cout << "�ּҴ�?";
    getline(cin, address);
    cout << "���̴�?";
    cin >> age;

    cout << name << ", " << address << ", " << age << "��\n";

    return 0;
}
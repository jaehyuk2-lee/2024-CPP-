#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "���ڿ� �Է�>> ";
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) { // �Է� ���� ���ڿ��� ũ�� ��ŭ �ݺ��Ѵ�.
        for (int j = 0; j <= i; j++) { // i��° ��ŭ���� ���ڿ��� ����Ѵ�.
            cout << str[j];
        }
        cout << endl; // n��°�� n���� ���ڿ� ��� �� �� �ٲ�
    }

    return 0;
}
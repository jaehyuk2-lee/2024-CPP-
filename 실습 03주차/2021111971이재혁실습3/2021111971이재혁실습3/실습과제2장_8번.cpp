#include <iostream>
#include <cstring> // strlen() �Լ� ����� ���� �����Ѵ�.
using namespace std;

int main()
{
    char name[5][100]; // �ִ���̰� 99�� ���ڿ� 5���� �����Ѵ�.
    cout << "5���� �̸��� ; ���� �����Ͽ� �Է��ϼ���\n>>";

    for (int i = 0; i < 5; i++) {
        cin.getline(name[i], 100, ';');
    } // ';'�� �߰��� �ۼ����־� ';'�� �ԷµǾ��� �� �� ���������� �ڷḦ �Է��Ѵ�.

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " : " << name[i] << "\n";
    }
    int max = strlen(name[0]); // �ִ��� ó�� �Է¹��� ���ڿ��� ���̷� �����Ѵ�.
    int max_index = 0;
    for (int i = 1; i < 5; i++) {
        // name[0]�� ���̰� �ִ����� �����Ǿ� �����Ƿ� name[1]���� ���̸� ���Ѵ�.
        if (strlen(name[i]) > max) {
            max = strlen(name[i]); // �ִ���̸� �ֽ�ȭ ���ش�.
            max_index = i; // ���� �� �̸��� ����Ǿ��ִ� index�� �����Ѵ�.
        }
    }

    cout << "���� �� �̸��� " << name[max_index] << "\n";
    return 0;
}
//Mozart;Elvis Presley;Jim Carry;Schubert;Dominggo;
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char coffee[6]; // Ŀ���̸� �ִ���ڰ� 5�̹Ƿ� '\0'�ڸ����� 6ũ���� ���ڿ� ������ �����Ѵ�
	int cup = 0; // ���� �Է¹����� ������ ������ �����.
	int price = 0; // Ŀ���� ������ ������ ������ �����.
	int total = 0; // ���� ������ ������ ������ �����.

	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl;
	while (true) {
		cout << "�ֹ�>> ";
		cin >> coffee >> cup; // Ŀ���� ������ �ܼ��� �Է¹޴´�.

		if (strcmp(coffee, "����������") == 0) price = 2000;
		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) price = 2300;
		else if (strcmp(coffee, "īǪġ��") == 0) price = 2500;
		cout << price * cup << "���Դϴ�. ���ְ� �弼��" << endl;
		// ���ݰ� �Է¹��� �� ����ŭ ����� ������ ����Ѵ�.

		total += price * cup; // �������� ����
		if (total >= 20000) {
			cout << "���� " << total << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���Ϻ���~~~" << endl;
			exit(true);
			// ���������� 20000�� �̻��̶�� �ݺ��� ����
		}
	}
}
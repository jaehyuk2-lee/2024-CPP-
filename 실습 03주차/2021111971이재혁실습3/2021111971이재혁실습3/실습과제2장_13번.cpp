#include <iostream>
using namespace std;

int main() {
	int menu, people = 0; // �޴���, ����� �ڷḦ ������ ���� ����

	cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;

	while (true) {
		cout << "«��:1, ¥��:2, ������:3, ����:4>> ";
		cin >> menu;
		switch (menu) { // �޴� �Է¿� ���� �ٸ� ������
		case 1:
			cout << "���κ�?";
			cin >> people;
			cout << "«�� " << people << "�κ� ���Խ��ϴ�." << endl;
			break;
		case 2:
			cout << "���κ�?";
			cin >> people;
			cout << "¥�� " << people << "�κ� ���Խ��ϴ�." << endl;
			break;
		case 3:
			cout << "���κ�?";
			cin >> people;
			cout << "������ " << people << "�κ� ���Խ��ϴ�." << endl;
			break;
		// 1, 2, 3�� ���� ������� �Է¹޾�, «��, ¥��, ������ �� �κ��� ����Ѵ�
		case 4:
			cout << "���� ������ �������ϴ�.";
			exit(true);
		// 4�� �Է¹����� while���� �����Ѵ�.
		default:
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			break;
		// �̿��� ���� �ٽ� �ֹ��� �޴´�.
		}
	}
}
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
} // �Ű������� �̸���, ��ü����� �̸��� ���� ������ this�����ͷ� ����

int main() {
	Person list[3]; // PersonŬ������ ��ü�� 3�� �迭�� ����

	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;

	string tmp_n, tmp_t;
	// ������� �̸��� ��ȭ��ȣ�� �Է¹޾� set�Լ��� ���� ��ü����� �ٲ� ����
	for (int i = 0; i < 3; i++) {
		cout << "��� " << i + 1 << " >> ";
		cin >> tmp_n >> tmp_t; // �ӽ÷� �̸��� ��ȭ��ȣ�� �Է¹ް� 
		list[i].set(tmp_n, tmp_t); // ��ü ����� ����
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) {
		cout << list[i].getName() << " ";
	}
	cout << "\n";

	int is_exist; // �˻��� �̸��� �����ϴ��� Ȯ���� ����
	cout << "��ȭ��ȣ �˻��մϴ�. (exit�� �Է��ϸ� ����)\n";
	while (1) {
		is_exist = 0;
		cout << "�̸��� �Է��ϼ��� >> ";
		cin >> tmp_n;
		if (tmp_n == "exit") break;

		for (int i = 0; i < 3; i++) {
			if (list[i].getName() == tmp_n) {
				cout << "��ȭ ��ȣ�� " << list[i].getTel() << "\n";
				is_exist = 1;
			} // �̸��� ã�Ҵٸ� ��ȭ��ȣ�� ����ϰ� is_exist�� 1�� ������ ã���� ǥ��
		}

		if (is_exist == 0) {
			cout << "�������� �ʴ� �̸��Դϴ�.\n";
		} // list�� Ȯ���� ���� �̸��� ã�� ���ߴٸ� �������� �ʴ� �̸��̶�� ���
	}
}
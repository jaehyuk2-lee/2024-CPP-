#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	friend istream& operator >> (istream&, Circle&);
	friend ostream& operator << (ostream&, Circle&);
	// ��Ʈ������ ��ü�� ��� ������ �����ϱ� ������ friend�Լ��� �ۼ�
	// �Է°� ����� ���������� �ϱ�����, stream���� �������� cin >> a >> b >> c; ���Ŀ��� �������� �۵�
};

istream& operator >> (istream& is, Circle& c) {
	cout << "������ >> ";
	cin >> c.radius; // c, ��ü�� �������� �Է¹޾Ƽ� ����
	cin.ignore(); //c�� �������� �Է��� �� �����ִ� ���๮�ڸ� ��� ���� ���ڿ��� �Է�
	cout << "�̸� >> ";
	getline(cin, c.name); // ��ü�� �̸� �Է�
	return is; // �������� �Է��� ����, istream ��ȯ
}
ostream& operator << (ostream& os, Circle& c) {
	cout << "(��������" << c.radius << "�� " << c.name << ")" ;
	return os; // �������� ����� ����, istream ��ȯ
}


int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
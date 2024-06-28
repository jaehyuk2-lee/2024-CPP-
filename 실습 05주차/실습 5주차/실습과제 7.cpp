#include <iostream>
using namespace std;

class Circle {
	int radius; // ���� ������ ��
public:
	void setRadius(int radius); // �������� �����Ѵ�.
	double getArea(); // ������ �����Ѵ�.
};

void Circle::setRadius(int radius) {
	this->radius = radius;
	// ��ü�� ����� �Ű������� �̸��� ���� �� this �����͸� �̿��� ������ �� �ִ�.
} // �������� �����Ѵ�.


double Circle::getArea() {
	return this->radius * this->radius * 3.14;
	// getArea()�� Circle�ȿ� ���ԵǾ� �ֱ� ������ this�� ����� �� �ִ�.
} // ������ �����Ѵ�.

int main() {
	Circle list[3]; // ������ ����Ʈ, �迭�� ����
	int setR = 0; // ������ �������� ������ ����

	for (int i = 0; i < 3; i++) {
		cout << "�� " << i+1 << "�� ������ >> ";
		cin >> setR;
		list[i].setRadius(setR);
	}

	int cnt = 0; // ������ 100���� ū ���� ������ ������ ����
	for (int i = 0; i < 3; i++) {
		if (list[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�" << endl;
}
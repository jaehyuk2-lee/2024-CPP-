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
	int N; // ���� ������ ������ ����
	cout << "���� ���� >> ";
	cin >> N;
	
	Circle* list; // ������ ����Ʈ�� ����Ű�� ������, ���� �������� �ʾ���
	list = new Circle[N]; // Circle ��ü�� N�� �����Ҽ� �ִ� �޸𸮸� �����Ҵ�

	int setR = 0; // ������ �������� ������ ����
	for (int i = 0; i < N; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> setR;
		list[i].setRadius(setR);
	} // N���� ���� �ֱ� ������ N�� �Է¹޴´�.

	int cnt = 0; // ������ 100���� ū ���� ������ ������ ����
	for (int i = 0; i < N; i++) {
		if (list[i].getArea() > 100) {
			cnt++;
		}
	} // N���� ���� �ֱ� ������ N�� ���Ѵ�.
	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�" << endl;
}
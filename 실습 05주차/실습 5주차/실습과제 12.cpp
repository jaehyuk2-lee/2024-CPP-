#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; // ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius) {
		this->name = name;
		this->radius = radius;
		// �Ű������� ��ü������ �̸��� �����Ƿ� this�����͸� ���
	}
	// �̸��� ������ ����
	double getArea() {
		return (this->radius) * (this->radius) * 3.14;
	}
	string getName() {
		return name;
	}
};

class CircleManager {
	Circle* p; // Circle �迭�� ���� ������
	int size; // �迭�� ũ��

public:
	CircleManager(int size) {
		this->size = size;
		// �Ű������� ��ü������ �̸��� �����Ƿ� this�����͸� ���
		p = new Circle[size];
		// ����ڷκ��� �Է¹��� ũ�⸦ Circle�����Ϳ� �����Ҵ�

		string tmp_n;
		int tmp_r;
		// �ӽ÷� �Է¹޾Ƽ� ��ü�迭�� ������ ���� ���� 

		for (int i = 0; i < size; i++) {
			cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
			cin >> tmp_n >> tmp_r;
			p[i].setCircle(tmp_n, tmp_r);
		}
	}
	// size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	~CircleManager() {
		delete[] p;
		// ��ü�迭������ p�� �����Ҵ��� �޾ұ� ������ ��ü�� �Ҹ��� �� �޸𸮸� ����
	}
	void searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
	void showList(); // ���� ����Ǿ��ִ� ������ ���
};

void CircleManager::searchByName() {
	string name;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;

	for (int i = 0; i < size; i++) {
		if (p[i].getName() == name) { // �Է¹��� �̸��� ���� �̸��� ������ Circle��ü �� ������ �Ʒ��� ���
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << "\n";
		}
	}
}

void CircleManager::searchByArea() {
	int area;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> area;
	cout << area << "����ū ���� �˻��մϴ�.\n";

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > area) { // �Է¹��� ���̺��� ū ���̸� ������ ��ü�� ������ �Ʒ��� ���
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
		}
	}
}

void CircleManager::showList() {
	cout << "�Է¹��� ��" << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << " ";
	}
	cout << "\n";
}

int main() {
	int N; // ���� ������ �Է¹��� ����
	cout << "���� ���� >> ";
	cin >> N;

	CircleManager myManager(N);
	myManager.showList();
	myManager.searchByName();
	myManager.searchByArea();
}
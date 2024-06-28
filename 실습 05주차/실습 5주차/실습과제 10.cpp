#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() {}
	Person(string name) { this -> name = name; }
	// �Ű������� �����ҽ� �̸��� �����ϴ� ��ü�Լ�

	void setPerson(string name) {
		this->name = name;
	} // ����� �̸��� �����ϴ� ��ü �Լ�
	string getName() { return name; }
};

class Family {
	Person* p; // Person �迭 ������
	string name; // ������ �̸�
	int size; // Person �迭�� ũ��. ���� ������ ��
public:
	Family(string name, int size) {
		this->name = name; 
		this->size = size;
		p = new Person[this->size];
		// ��ü�迭�� �Ű������� �ִ� �����ڸ� ȣ���� �� ����.
		// ���� �⺻�����ڸ� ����� ������ ���� ��������� ���� �����ؾ� �Ѵ�.
	}// size ������ŭ Person �迭 ���� ����

	void setName(int num, string name) {
		p[num].setPerson(name);
		// num���� ����� �̸��� �����Ѵ�.
	}
	void show() {
		cout << name << "������ ������ ���� " << size << "�� �Դϴ�.\n";
		for (int i = 0; i < this->size; i++) {
			cout << p[i].getName() << "  ";
		}cout << endl;
	}
	// ��� ���� ������ ���

	~Family() {
		delete[] p;
		// FamilyŬ������ ��ü�� �Ҹ��� �� �����Ҵ� �޾���
		// PersonŬ���� ��ü �迭�� �޸𸮸� �����Ѵ�.
	}
};



int main() {
	Family* simpson = new Family("Simpson", 3); // 3������ ������ Simpson ����
	simpson -> setName(0, "Mr. Simpson");
	simpson -> setName(1, "Mrs. Simpson");
	simpson -> setName(2, "Bart Simpson");
	simpson -> show();
	delete simpson;
}

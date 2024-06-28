#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size]; // ���޹��� �迭�� ũ�⸸ŭ �Ҵ��Ѵ�.
	}

	/*Dept(const Dept& dept) {
		this->size = size;
		scores = new int[size];
		for (int i = 0; i < size; i++) {
			scores[i] = dept.scores[i];
		}
	}*/

	~Dept() {
		delete[] scores; // ��ü�� �Ҹ��� �� �����Ҵ� ���� �޸𸮸� �����Ѵ�.
	}

	int getSize() { return size; }
	void read() {
		cout << size << "�� ���� �Է� >> ";
		for (int i = 0; i < size; i++) {
			cin >> scores[i];
		} // size�� �ݺ��ϸ鼭 scores�� ���� �Է� �޴´�.
	}
	bool isOver60(int index) {
		if (scores[index] >= 60) { // index�� ������ 60�� �̻��̸� true�� ��ȯ (������ ������� 60�� �̻��ε� 60�� �������� �ʴ´�)
			return true;
		}
		else return false;
	}
};

int countPass(const Dept& dept) { // 3) ��������
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60�� �̻��� " << n << "��";
}


// 2) countPass�Լ����� dept��ü�� �Ѱܹ��� �� call by value ����̱� ������ dept��ü�� �⺻��������ڰ� ȣ��ȴ�, countPass�Լ��� �����ϰ� count�� return�Ҷ� dept��ü�� �Ҹ�Ǵµ�
//    dept��ü�� scores �����ʹ� ���޹��� ��ü�� scores�� �ּҸ� ����Ű�� �ִ� �װ��� ���� ��Ų��.
//    countPass�� ���� �����ߴ� ��ü�� dept�� �Ҹ��Ҷ� �ڽ��� scores �������� �޸𸮰� �����Ǿ��� ������, main�Լ� ����� ������ �޸𸮰� ���� ���� ������ �߻��Ѵ�.

// 3) 2���� ������ ��������� ���� ���������� �޸������� ���� ��������. ���� ��������ڿ��� ��������� �ۼ��ϴ� ����� ������
//    �Լ��� ���� call by refrence�� �����ϸ� ���ο� �޸𸮸� ������ �ʾƵ� �ȴ�. ���� countPass(Dept& dept)�� ���۷��� ������ �Լ��� �����Ѵ�.
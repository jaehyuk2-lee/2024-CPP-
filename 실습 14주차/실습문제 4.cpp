#include <iostream>
using namespace std;
int* copy(int* src, int size) {
	int* p = NULL;
	if (size < 0) { //too small
		throw -1;
	}
	else if (size > 100) { //too big
		throw -2;
	}
	p = new int[size]; //�޸� �Ҵ�
	if (p == NULL) { //memory short
		throw -3;
	}
	else if (src == NULL) { //NULL source
		delete[] p;
		throw -4;
	}
	// ���� �߻� �� ������ ��쿡 ���� �ٸ� ���� throw �Ѵ�.
	else { // ���������� �迭�� �����ϴ� �κ�
		for (int n = 0; n < size; n++) p[n] = src[n];
		return p;
	}
}

int main() {
	int x[] = { 1,2,3 };
	int* y = NULL;
	try {
		int* p = copy(y, 0);
		for (int i = 0; i < 3; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;

		delete[] p;
	}
	catch(int a) {
		cout << "�Լ� ���� ����, ���� �ڵ�  : " << a;
		cout << "\n -1 : too small\n -2 : too big\n -3 : memory short\n -4 : NULL source";
		// throw�� ���� ����� � ������ �߻��ߴ��� Ȯ���� �� �ִ�.
	}
}

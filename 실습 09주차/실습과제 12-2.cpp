// ��������ڸ� ��������� Ȱ���� �ڵ�
#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int* p;
	void sort() {
		int min_index = 0;
		for (int i = 0; i < size - 1; i++) {
			min_index = i;
			for (int j = i + 1; j < size; j++) {
				if (p[min_index] > p[j]) {
					min_index = j;
				}
			}
			int tmp = p[i];
			p[i] = p[min_index];
			p[min_index] = tmp;
			// �迭�� ���� ���ʺ��� �ϳ��� �����Ѵ�.
			// ���� �� �迭�� �����ʿ��� ���� ��ġ�� ������ ���� ��ġ�� ã�´�.
			// �������� ����Ž������ �� �ּڰ��� ��ġ�� ������ġ�� �����Ѵ�.
			// �迭�� ���ʺ��� ������ ������ ���ĵȴ�.
			// �迭�� ������ n�̶���� �� (n + (n-1) + (n-2) + ... + 1) �� �����Ѵ�.
			// �� O(n^2)�� �ð����� �迭�� ���ĵȴ� (��������)
		}
	}
public:
	SortedArray() {
		p = NULL;
		size = 0;
	}

	SortedArray(SortedArray& src) {
		size = src.size;
		p = src.p;
		// ���޹��� ��ü�� ���� ��������
		src.p = NULL; // �� ������ ������ �ڵ������ ���� �߻�

		sort();
	}
	// �Լ��� ��ü�� ������ �� ���� �ִ� �޸𸮴� ���� �����ȴ�,
	// �����ϴ� ���� ������ �ӽð�ü�� �����ȴ�.
	// �̶� ���� �����ڰ� �߻��ϹǷ� ���� ��������ڰ� �ʿ��� ��Ȳ�̴�.
	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
		// ���޹��� �Ű������鿡 ���� ��������

		sort(); // ���� �� �迭 ����
	}
	~SortedArray() {
		if (p) delete[] p;
		// p�� �����Ҵ���� �޸𸮰� ������� �� delete����
	}
	SortedArray operator+ (SortedArray& op2) {
		SortedArray c;
		c.size = size + op2.size;
		c.p = new int[c.size];
		for (int i = 0; i < size; i++) {
			c.p[i] = p[i];
		}
		for (int i = 0; i < op2.size; i++) {
			c.p[size + i] = op2.p[i];
		}
		c.sort(); // ���� �� �迭 ����
		return c;
	}

	SortedArray& operator = (const SortedArray& op2) {
		if (p) delete[] p; // ���� p�� ���� �����Ҵ� �Ǿ��ִٸ� �޸� ����
		size = op2.size;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = op2.p[i];
		} // ���޹��� ��ü�� ���� ��������

		sort();
		return *this;
	}

	void show() {
		cout << "�迭��� : ";
		for (int i = 0; i < size; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b; // +, = ������ �ۼ� �ʿ�
	// +�����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
	a.show();
	b.show();
	c.show();
}
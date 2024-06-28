// 복사생성자를 얕은복사로 활용한 코드
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
			// 배열의 제일 왼쪽부터 하나씩 선택한다.
			// 선택 후 배열의 오른쪽에서 현재 위치의 값보다 작은 위치를 찾는다.
			// 오른쪽을 전부탐색했을 때 최솟값의 위치와 왼쪽위치를 변경한다.
			// 배열이 왼쪽부터 오름차 순으로 정렬된다.
			// 배열의 개수가 n이라고할 때 (n + (n-1) + (n-2) + ... + 1) 번 수행한다.
			// 즉 O(n^2)의 시간으로 배열이 정렬된다 (선택정렬)
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
		// 전달받은 객체에 대한 얕은복사
		src.p = NULL; // 이 과정이 없으면 코드실행중 에러 발생

		sort();
	}
	// 함수가 객체를 리턴할 때 원래 있는 메모리는 전부 해제된다,
	// 리턴하는 값을 저장할 임시객체가 생성된다.
	// 이때 복사 생성자가 발생하므로 깊은 복사생성자가 필요한 상황이다.
	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
		// 전달받은 매개변수들에 대한 깊은복사

		sort(); // 생성 후 배열 정렬
	}
	~SortedArray() {
		if (p) delete[] p;
		// p에 동적할당받은 메모리가 있을경우 만 delete시행
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
		c.sort(); // 생성 후 배열 정렬
		return c;
	}

	SortedArray& operator = (const SortedArray& op2) {
		if (p) delete[] p; // 만약 p에 값이 동적할당 되어있다면 메모리 해제
		size = op2.size;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = op2.p[i];
		} // 전달받은 객체에 대한 깊은복사

		sort();
		return *this;
	}

	void show() {
		cout << "배열출력 : ";
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
	c = a + b; // +, = 연산자 작성 필요
	// +연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
	a.show();
	b.show();
	c.show();
}
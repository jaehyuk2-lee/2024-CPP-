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
	p = new int[size]; //메모리 할당
	if (p == NULL) { //memory short
		throw -3;
	}
	else if (src == NULL) { //NULL source
		delete[] p;
		throw -4;
	}
	// 오류 발생 시 각각의 경우에 따라 다른 값을 throw 한다.
	else { // 정상적으로 배열을 복사하는 부분
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
		cout << "함수 복사 실패, 오류 코드  : " << a;
		cout << "\n -1 : too small\n -2 : too big\n -3 : memory short\n -4 : NULL source";
		// throw한 값을 출력해 어떤 오류가 발생했는지 확인할 수 있다.
	}
}

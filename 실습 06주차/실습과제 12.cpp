#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size]; // 전달받은 배열의 크기만큼 할당한다.
	}

	/*Dept(const Dept& dept) {
		this->size = size;
		scores = new int[size];
		for (int i = 0; i < size; i++) {
			scores[i] = dept.scores[i];
		}
	}*/

	~Dept() {
		delete[] scores; // 객체가 소멸할 때 동적할당 받은 메모리를 해제한다.
	}

	int getSize() { return size; }
	void read() {
		cout << size << "개 점수 입력 >> ";
		for (int i = 0; i < size; i++) {
			cin >> scores[i];
		} // size번 반복하면서 scores에 값을 입력 받는다.
	}
	bool isOver60(int index) {
		if (scores[index] >= 60) { // index의 점수가 60점 이상이면 true를 반환 (문제의 결과에서 60점 이상인데 60을 포함하지 않는다)
			return true;
		}
		else return false;
	}
};

int countPass(const Dept& dept) { // 3) 수정내역
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
	cout << "60점 이상은 " << n << "명";
}


// 2) countPass함수에서 dept객체로 넘겨받을 때 call by value 방식이기 때문에 dept객체에 기본복사생성자가 호출된다, countPass함수를 실행하고 count를 return할때 dept객체가 소멸되는데
//    dept객체의 scores 포인터는 전달받은 객체의 scores의 주소를 가리키고 있다 그것을 해제 시킨다.
//    countPass에 값을 전달했던 객체는 dept가 소멸할때 자신의 scores 포인터의 메모리가 해제되었기 때문에, main함수 종료시 해제할 메모리가 없어 실행 오류가 발생한다.

// 3) 2번의 오류는 얕은복사로 인해 비정상적인 메모리해제로 인한 오류였다. 따라서 복사생성자에서 깊은복사로 작성하는 방법이 있지만
//    함수에 값을 call by refrence로 전달하면 새로운 메모리를 만들지 않아도 된다. 따라서 countPass(Dept& dept)로 레퍼런스 변수로 함수를 실행한다.
#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius) {
		this->name = name;
		this->radius = radius;
		// 매개변수와 객체변수의 이름이 같으므로 this포인터를 사용
	}
	// 이름과 반지름 설정
	double getArea() {
		return (this->radius) * (this->radius) * 3.14;
	}
	string getName() {
		return name;
	}
};

class CircleManager {
	Circle* p; // Circle 배열에 대한 포인터
	int size; // 배열의 크기

public:
	CircleManager(int size) {
		this->size = size;
		// 매개변수와 객체변수의 이름이 같으므로 this포인터를 사용
		p = new Circle[size];
		// 사용자로부터 입력받은 크기를 Circle포인터에 동적할당

		string tmp_n;
		int tmp_r;
		// 임시로 입력받아서 객체배열에 전달할 변수 설정 

		for (int i = 0; i < size; i++) {
			cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
			cin >> tmp_n >> tmp_r;
			p[i].setCircle(tmp_n, tmp_r);
		}
	}
	// size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
	~CircleManager() {
		delete[] p;
		// 객체배열포인터 p는 동적할당을 받았기 때문에 객체가 소멸할 때 메모리를 해제
	}
	void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
	void showList(); // 현재 저장되어있는 원들을 출력
};

void CircleManager::searchByName() {
	string name;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> name;

	for (int i = 0; i < size; i++) {
		if (p[i].getName() == name) { // 입력받은 이름과 같은 이름을 가지는 Circle객체 가 있으면 아래를 출력
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << "\n";
		}
	}
}

void CircleManager::searchByArea() {
	int area;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> area;
	cout << area << "보다큰 원을 검색합니다.\n";

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > area) { // 입력받은 넓이보다 큰 넓이를 가지는 객체가 있으면 아래를 출력
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
		}
	}
}

void CircleManager::showList() {
	cout << "입력받은 원" << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << " ";
	}
	cout << "\n";
}

int main() {
	int N; // 원의 개수를 입력받을 변수
	cout << "원의 개수 >> ";
	cin >> N;

	CircleManager myManager(N);
	myManager.showList();
	myManager.searchByName();
	myManager.searchByArea();
}
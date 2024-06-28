#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() {}
	Person(string name) { this -> name = name; }
	// 매개변수로 생성할시 이름을 설정하는 객체함수

	void setPerson(string name) {
		this->name = name;
	} // 사람의 이름을 설정하는 객체 함수
	string getName() { return name; }
};

class Family {
	Person* p; // Person 배열 포인터
	string name; // 가족의 이름
	int size; // Person 배열의 크기. 가족 구성원 수
public:
	Family(string name, int size) {
		this->name = name; 
		this->size = size;
		p = new Person[this->size];
		// 객체배열은 매개변수가 있는 생성자를 호출할 수 없다.
		// 따라서 기본생성자를 만들어 생성후 따로 멤버변수의 값을 설정해야 한다.
	}// size 개수만큼 Person 배열 동적 생성

	void setName(int num, string name) {
		p[num].setPerson(name);
		// num번의 사람의 이름을 설정한다.
	}
	void show() {
		cout << name << "가족은 다음과 같이 " << size << "명 입니다.\n";
		for (int i = 0; i < this->size; i++) {
			cout << p[i].getName() << "  ";
		}cout << endl;
	}
	// 모든 가족 구성원 출력

	~Family() {
		delete[] p;
		// Family클래스의 객체가 소멸할 때 동적할당 받었던
		// Person클래스 객체 배열의 메모리를 해제한다.
	}
};



int main() {
	Family* simpson = new Family("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson -> setName(0, "Mr. Simpson");
	simpson -> setName(1, "Mrs. Simpson");
	simpson -> setName(2, "Bart Simpson");
	simpson -> show();
	delete simpson;
}

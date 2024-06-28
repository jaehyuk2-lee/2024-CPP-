#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill(); // 최대량(10)으로 채우기
	void consume(); // 1 만큼 소모하기
	int getSize(); // 현재 크기 리턴
}; // CoffeeVendingMachine 객체가 Container의 객체를 배열로 갖고 있기 때문에 먼저 선언 되어야한다.

void Container::fill() { // Container객체의 fill() 함수
	this->size = 10; // 객체에 들어있는 재료를 10으로 채운다.
}
void Container::consume() { // 객체의 size의 멤버를 1개 줄인다.
	this->size--;
}
int Container::getSize() {
	return this->size;
} // 현재 객체가 가지고있는 size리턴


class CoffeeVendingMachine {
	Container tong[3]; // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통
	void fill(); // 3개의 통을 모두 10으로 채움
	void selectEspresso(); // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	void selectAmericano(); // 아메리카노를 선택한 경우, 커피 1, 물 2 소모
	void selectSugarcoffee(); // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
	void show(); // 현재 커피, 물, 설탕의 잔량 출력

public:
	void run(); // 다른 객체 함수들은 private 접근지정자이기 때문에 run()함수를 통해서 접근해야한다.
};

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	} // 통은 3개가 있기 때문에, 모든 tong객체들의 fill()함수를 실행한다.
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << "\n";
	// 채워진 원료의 개수를 보여준다.
}
void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
		// 에스프레소의 원료는 물 1, 커피 1이기 때문에
		// 잔량이 요구 원료보다 같거나 클때만 실행한다.
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << "\n";
	}
	else cout << "원료가 부족합니다.\n";
	// 원료가 부족할 경우 실행하지 않는다.
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
		// 아메리카노의 원료는 물 1, 커피 2이기 때문에
		// 잔량이 요구 원료보다 같거나 클때만 실행한다.
		tong[0].consume();
		tong[1].consume();
		tong[1].consume(); // 아메리카노의 물은 2개 소모
		cout << "아메리카노 드세요" << "\n";
	}
	else cout << "원료가 부족합니다.\n";
}
void CoffeeVendingMachine::selectSugarcoffee() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
		// 설탕커피의 원료는 물 1, 커피 2, 설탕 1이기 때문에
		// 잔량이 요구 원료보다 같거나 클때만 실행한다.
		tong[0].consume();
		tong[1].consume();
		tong[1].consume(); // 설탕커피는 물 2개 소모
		tong[2].consume();
		cout << "설탕커피 드세요" << "\n";
	}
	else cout << "원료가 부족합니다.\n";
}
void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << "\n";
} // 현재 통에 들어있는 재료의 크기들을 출력한다.

void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다 *****" << endl;

	int choice; // 사용자의 선택을 입력받을 변수
	while (1) {
		cout << "메뉴를 눌러주세요 (1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기, 0:종료)>> ";
		cin >> choice;
		switch (choice) { // 사용자의 입력에 따라 함수를 실행한다.
		case 1:
			this->selectEspresso();
			break;
		case 2:
			this->selectAmericano();
			break;
		case 3:
			this->selectSugarcoffee();
			break;
		case 4:
			this->show();
			break;
		case 5:
			this->fill();
			break;
		case 0:
			cout << "종료합니다.\n";
			exit(1); // 0을 입력받으면 반복을 종료한다.
			break;
		default:
			break;
		}
	}
}

int main() {
	CoffeeVendingMachine myMachine;
	myMachine.run();
}
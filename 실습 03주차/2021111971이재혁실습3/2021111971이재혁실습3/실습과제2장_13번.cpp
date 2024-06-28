#include <iostream>
using namespace std;

int main() {
	int menu, people = 0; // 메뉴와, 사람의 자료를 저장할 변수 선언

	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;

	while (true) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>> ";
		cin >> menu;
		switch (menu) { // 메뉴 입력에 따라 다른 실행결과
		case 1:
			cout << "몇인분?";
			cin >> people;
			cout << "짬뽕 " << people << "인분 나왔습니다." << endl;
			break;
		case 2:
			cout << "몇인분?";
			cin >> people;
			cout << "짜장 " << people << "인분 나왔습니다." << endl;
			break;
		case 3:
			cout << "몇인분?";
			cin >> people;
			cout << "군만두 " << people << "인분 나왔습니다." << endl;
			break;
		// 1, 2, 3은 각각 사람수를 입력받아, 짬뽕, 짜장, 군만두 몇 인분을 출력한다
		case 4:
			cout << "오늘 영업은 끝났습니다.";
			exit(true);
		// 4를 입력받으면 while문을 종료한다.
		default:
			cout << "다시 주문하세요!!" << endl;
			break;
		// 이외의 경우는 다시 주문을 받는다.
		}
	}
}
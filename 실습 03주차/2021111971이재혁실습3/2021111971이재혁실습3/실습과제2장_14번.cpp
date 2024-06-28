#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char coffee[6]; // 커피이름 최대글자가 5이므로 '\0'자리까지 6크기의 문자열 공간을 선언한다
	int cup = 0; // 몇잔 입력받을지 저장할 변수를 만든다.
	int price = 0; // 커피의 가격을 저장할 변수를 만든다.
	int total = 0; // 누적 가격을 저장할 변수를 만든다.

	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	while (true) {
		cout << "주문>> ";
		cin >> coffee >> cup; // 커피의 종류와 잔수를 입력받는다.

		if (strcmp(coffee, "에스프레소") == 0) price = 2000;
		else if (strcmp(coffee, "아메리카노") == 0) price = 2300;
		else if (strcmp(coffee, "카푸치노") == 0) price = 2500;
		cout << price * cup << "원입니다. 맛있게 드세요" << endl;
		// 가격과 입력받은 잔 수만큼 계산한 가격을 출력한다.

		total += price * cup; // 누적가격 저장
		if (total >= 20000) {
			cout << "오늘 " << total << "원을 판매하여 카페를 닫습니다. 내일봐요~~~" << endl;
			exit(true);
			// 누적가격이 20000원 이상이라면 반복문 종료
		}
	}
}
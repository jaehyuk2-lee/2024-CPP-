#include <iostream>
#include <string>
using namespace std;

int main() {
	string expression = "0"; // 식이 저장될 변수

	while (expression != "\0") { // 아무것도 입력하지 않으면 반복 종료
		string num1, num2; // 식의 정수부분이 저장 될 변수
		char cal = '\0'; // 식의 계산기호부분이 저장 될 변수
		cout << "? ";
		getline(cin, expression);
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ' ') { // 첫번째 공백이 나타났을 시
				for (int j = 0; j < i; j++) {
					num1 += expression[j]; // 0번째 부터 공백이전까지의 문자열을 저장
				}
				for (int k = i + 3; k < expression.size(); k++) {
					num2 += expression[k];
					// 첫번째 숫자, 공백, 계산기호, 공백, 두번째 숫자 순서이기 때문에
					// 첫번째 공백부터 3칸 뒤가 두번째 숫자의 시작, 문자열 끝까지가 두번째 숫자의 끝
				}
				cal = expression[i + 1]; // 첫번째 공백 다음은 계산기호
				break; // 첫번째 공백 까지만 반복
			}
		}
		int n1 = atoi(num1.c_str());
		int n2 = atoi(num2.c_str()); // 문자열로 저장된 숫자를 int형으로 전환

		switch (cal) { // cal문자의 경우에 따라 다르게 계산한다
		case '+':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 + n2 << endl;
			break;
		case '-':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 - n2 << endl;
			break;
		case '*':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 * n2 << endl;
			break;
		case '/':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 / n2 << endl;
			break;
		case '%':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 % n2 << endl;
			break;
		default:
			break;
		}
	}
}
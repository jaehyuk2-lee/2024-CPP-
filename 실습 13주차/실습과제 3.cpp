#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	friend istream& operator >> (istream&, Circle&);
	friend ostream& operator << (ostream&, Circle&);
	// 스트림으로 객체의 멤버 변수에 접근하기 때문에 friend함수로 작성
	// 입력과 출력을 연속적으로 하기위해, stream들을 리턴해줘 cin >> a >> b >> c; 형식에서 연속으로 작동
};

istream& operator >> (istream& is, Circle& c) {
	cout << "반지름 >> ";
	cin >> c.radius; // c, 객체에 반지름을 입력받아서 설정
	cin.ignore(); //c에 반지름을 입력한 뒤 남아있는 개행문자를 비워 다음 문자열을 입력
	cout << "이름 >> ";
	getline(cin, c.name); // 객체의 이름 입력
	return is; // 연속적인 입력을 위해, istream 반환
}
ostream& operator << (ostream& os, Circle& c) {
	cout << "(반지름이" << c.radius << "인 " << c.name << ")" ;
	return os; // 연속적인 출력을 위해, istream 반환
}


int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
} // 매개변수의 이름과, 객체멤버의 이름이 갖기 때문에 this포인터로 구분

int main() {
	Person list[3]; // Person클래스의 객체를 3개 배열로 선언

	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	string tmp_n, tmp_t;
	// 사용자의 이름과 전화번호를 입력받아 set함수를 통해 객체멤버를 바꿀 변수
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << " >> ";
		cin >> tmp_n >> tmp_t; // 임시로 이름과 전화번호를 입력받고 
		list[i].set(tmp_n, tmp_t); // 객체 멤버에 설정
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << list[i].getName() << " ";
	}
	cout << "\n";

	int is_exist; // 검색한 이름이 존재하는지 확인할 변수
	cout << "전화번호 검색합니다. (exit를 입력하면 종료)\n";
	while (1) {
		is_exist = 0;
		cout << "이름을 입력하세요 >> ";
		cin >> tmp_n;
		if (tmp_n == "exit") break;

		for (int i = 0; i < 3; i++) {
			if (list[i].getName() == tmp_n) {
				cout << "전화 번호는 " << list[i].getTel() << "\n";
				is_exist = 1;
			} // 이름을 찾았다면 전화번호를 출력하고 is_exist를 1로 변경해 찾음을 표시
		}

		if (is_exist == 0) {
			cout << "존재하지 않는 이름입니다.\n";
		} // list를 확인할 동안 이름을 찾지 못했다면 존재하지 않는 이름이라고 출력
	}
}
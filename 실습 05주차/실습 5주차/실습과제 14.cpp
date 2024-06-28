#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name; // 플레이어의 이름
	int num[3]; // 플레이어의 난수가 저장될 배열
public:
	void setName(string name) {
		this->name = name;
	} // 매개변수로 넘겨받은 문자열을 이름으로 설정하는 함수

	void setNumber() {
		for (int i = 0; i < 3; i++) {
			num[i] = rand() % 3; // 3개의 난수 0 1 2 중 하나가 발생되어 저장된다.
			cout << num[i] << "   ";
		}
	}

	int is_end() {
		int end = 1; // 3개의 값이 모두 같으면 1로 바꾼다. 1이면 끝 0이면 끝이 아님을 의미한다.
		for (int i = 0; i < 2; i++) {
			if (num[i] != num[i + 1]) {
				end = 0;
				break;
			} // 배열읠 확인해서 이전값과 다음값이 다르면 0으로 값을 바꾸고 뒤를 확인할 필요가 없으니 반복을 종료한다.
		}
		return end;
	} // 3개의 난수가 모두 같은지 확인하는 함수
	
	string getName() {
		return name;
	} // 플레이어의 이름을 반환하는 함수
};

class GamblingGame {
	Player player[2]; // 2명의 플레이어의 정보를 관리할 객체 배열이다.
public:
	void play() {
		string tmp_n; // 이름을 입력받아
		cout << "***** 갬블링 게임을 시작합니다. *****\n";
		cout << "첫번째 선수 이름 >> ";
		cin >> tmp_n;
		player[0].setName(tmp_n);
		fflush(stdin);

		cout << "두번째 선수 이름 >> ";
		cin >> tmp_n;
		player[1].setName(tmp_n);
		fflush(stdin);

		int turn = 0; // 플레이어들의 차례정보를 저장하는 변수
		while (1) {
			cout << player[turn].getName() << ": <Enter>\n";
			getchar(); // 버퍼에서 1글자를 넘겨받을 때까지 기다린다. <Enter>입력 전까지 기다리는 함수
			cout << "\t\t";
			player[turn].setNumber();
			if (player[turn].is_end()) { // is_end()가 1을 반환할 때 게임 종료
				cout << player[turn].getName() << "님 승리!!!";
				break;
			}
			else cout << "아쉽군요!\n";
			turn = (turn + 1) % 2; // turn은 나머지 연산으로 0 1 0 1 을 반복한다.
		}
	}
};

int main() {
	srand(time(NULL)); // 랜덤함수의 시드 값을 매번 다르게 설정
	GamblingGame game;
	game.play();
}
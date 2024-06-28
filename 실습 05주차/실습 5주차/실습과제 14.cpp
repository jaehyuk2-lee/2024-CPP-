#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name; // �÷��̾��� �̸�
	int num[3]; // �÷��̾��� ������ ����� �迭
public:
	void setName(string name) {
		this->name = name;
	} // �Ű������� �Ѱܹ��� ���ڿ��� �̸����� �����ϴ� �Լ�

	void setNumber() {
		for (int i = 0; i < 3; i++) {
			num[i] = rand() % 3; // 3���� ���� 0 1 2 �� �ϳ��� �߻��Ǿ� ����ȴ�.
			cout << num[i] << "   ";
		}
	}

	int is_end() {
		int end = 1; // 3���� ���� ��� ������ 1�� �ٲ۴�. 1�̸� �� 0�̸� ���� �ƴ��� �ǹ��Ѵ�.
		for (int i = 0; i < 2; i++) {
			if (num[i] != num[i + 1]) {
				end = 0;
				break;
			} // �迭�� Ȯ���ؼ� �������� �������� �ٸ��� 0���� ���� �ٲٰ� �ڸ� Ȯ���� �ʿ䰡 ������ �ݺ��� �����Ѵ�.
		}
		return end;
	} // 3���� ������ ��� ������ Ȯ���ϴ� �Լ�
	
	string getName() {
		return name;
	} // �÷��̾��� �̸��� ��ȯ�ϴ� �Լ�
};

class GamblingGame {
	Player player[2]; // 2���� �÷��̾��� ������ ������ ��ü �迭�̴�.
public:
	void play() {
		string tmp_n; // �̸��� �Է¹޾�
		cout << "***** ���� ������ �����մϴ�. *****\n";
		cout << "ù��° ���� �̸� >> ";
		cin >> tmp_n;
		player[0].setName(tmp_n);
		fflush(stdin);

		cout << "�ι�° ���� �̸� >> ";
		cin >> tmp_n;
		player[1].setName(tmp_n);
		fflush(stdin);

		int turn = 0; // �÷��̾���� ���������� �����ϴ� ����
		while (1) {
			cout << player[turn].getName() << ": <Enter>\n";
			getchar(); // ���ۿ��� 1���ڸ� �Ѱܹ��� ������ ��ٸ���. <Enter>�Է� ������ ��ٸ��� �Լ�
			cout << "\t\t";
			player[turn].setNumber();
			if (player[turn].is_end()) { // is_end()�� 1�� ��ȯ�� �� ���� ����
				cout << player[turn].getName() << "�� �¸�!!!";
				break;
			}
			else cout << "�ƽ�����!\n";
			turn = (turn + 1) % 2; // turn�� ������ �������� 0 1 0 1 �� �ݺ��Ѵ�.
		}
	}
};

int main() {
	srand(time(NULL)); // �����Լ��� �õ� ���� �Ź� �ٸ��� ����
	GamblingGame game;
	game.play();
}
#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string sentence;
public:
	Histogram(string sentence) {
		this->sentence = sentence;
	}
	void put(string); // ���ڿ��� �߰��� �Լ�
	void putc(char); // ���ڸ� ����� �Լ�
	void print(); // Histogram�� ����� ����� �Լ�
};

void Histogram::put(string add) {
	sentence += add;
}
// �߰��� ���ڿ��� stringŬ������ +�����ڸ� ���� ���ڿ��� �߰��Ѵ�.

void Histogram::putc(char add) {
	sentence += add;
}
// �߰��� ���ڸ� stringŬ������ +�����ڸ� ���� ���ڿ��� �߰��Ѵ�.

void Histogram::print() {
	cout << sentence << "\n"; // ����Ǿ��ִ� ���ڿ� ���
	int size = sentence.size();
	int alph[26] = { 0 }; // ���ĺ��� ������ ������ �迭 0�� ���� abcd..z�� ������ �����Ѵ�.

	for (int i = 0; i < size; i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			alph[sentence[i] - 65] ++;
			// �빮���� ��� 65�� �ƽ�Ű ���� �� ��ġ�� ���ĺ��� ��ġ�̴�.
			// 'A' = 65�̱� ������ 65�� ���� 0 �� a�� ������ �ö󰣴�.
		}
		else if (sentence[i] >= 97 && sentence[i] <= 122) {
			alph[sentence[i] - 97] ++;
			// �ҹ����� ��� 97�� �ƽ�Ű ���� �� ��ġ�� ���ĺ��� ��ġ�̴�.
			// 'a' = 97�̱� ������ 97�� ���� 0 �� a�� ������ �ö󰣴�.
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << char(i+97) << "(" << alph[i] << ") : "; // ���ĺ��� �ƽ�Ű�ڵ��� ���� ���� �� ���ĺ����� ���
		for (int j = 0; j < alph[i]; j++) {
			cout << "*";
		} // ����ִ� ���ĺ��� �� ��ŭ *���
		cout << "\n";
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
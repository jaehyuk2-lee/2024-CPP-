#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string sentence;
public:
	Histogram(string sentence) {
		this->sentence = sentence;
	}
	void put(string); // 문자열을 추가할 함수
	void putc(char); // 문자를 출력할 함수
	void print(); // Histogram의 결과를 출력할 함수
};

void Histogram::put(string add) {
	sentence += add;
}
// 추가할 문자열을 string클래스의 +연산자를 통해 문자열에 추가한다.

void Histogram::putc(char add) {
	sentence += add;
}
// 추가할 문자를 string클래스의 +연산자를 통해 문자열에 추가한다.

void Histogram::print() {
	cout << sentence << "\n"; // 저장되어있는 문자열 출력
	int size = sentence.size();
	int alph[26] = { 0 }; // 알파벳의 개수를 저장할 배열 0번 부터 abcd..z의 개수를 저장한다.

	for (int i = 0; i < size; i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			alph[sentence[i] - 65] ++;
			// 대문자일 경우 65의 아스키 값을 뺀 위치가 알파벳의 위치이다.
			// 'A' = 65이기 때문에 65를 빼면 0 즉 a의 개수가 올라간다.
		}
		else if (sentence[i] >= 97 && sentence[i] <= 122) {
			alph[sentence[i] - 97] ++;
			// 소문자일 경우 97의 아스키 값을 뺀 위치가 알파벳의 위치이다.
			// 'a' = 97이기 때문에 97를 빼면 0 즉 a의 개수가 올라간다.
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << char(i+97) << "(" << alph[i] << ") : "; // 알파벳의 아스키코드의 값을 문자 즉 알파벳으로 출력
		for (int j = 0; j < alph[i]; j++) {
			cout << "*";
		} // 들어있는 알파벳의 수 만큼 *출력
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
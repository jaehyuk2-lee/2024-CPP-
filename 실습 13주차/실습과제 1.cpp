#include <iostream>
using namespace std;

int main() {
	char ch;
	while ((ch = cin.get()) != EOF) { // ctrl z를 입력받았을 경우 cin.get()이 EOF를 리턴한다.
		if (ch == ';') { // 스트림을 입력받다가 ;를 만났을 경우
			cin.ignore(30, '\n'); // 개행문자를 만날 때 까지 버퍼에 남아있는 30개의 값을 지운다.
			cout.put('\n'); // 다음 입력을 위해 줄을 바꾼다.
		}
		else cout.put(ch); // ;이 아니라면 버퍼에 있는 문자를 출력한다.
	}
}
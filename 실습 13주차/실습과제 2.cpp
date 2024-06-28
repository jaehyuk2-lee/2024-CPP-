#include <iostream>
#include <iomanip> // 매개 변수를 가진 조작자 setw를 사용하기 위해 include
#include <cmath>
using namespace std;

int main() {
	cout.setf(ios::left); // 출력공간에 데이터를 출력할 시 왼쪽으로 정렬하여 출력
	
	cout << setw(15) << "Number"; // 다음출력이 되는 공간을 15로 설정
	cout << setw(15) << "Square";
	cout << setw(15) << "Square Root";
	cout << endl;

	streamsize prec;
	// 버퍼에서 보내지는 데이터의 크기를 저장하는 변수, 유효숫자 3자리를 제곱근에만 저장하기 위해
	// 초기 유효숫자를 저장해 두는 변수
	for (int i = 0; i <= 45; i += 5) {
		cout << setw(15) << setfill('_') << i; // 출력 공간에 남은 자리를 '-'로  채움
		cout << setw(15) << setfill('_') << pow(i, 2);

		prec = cout.precision(); // 유효 숫자를 변경하기 전 원래의 유효숫자 자리 저장
		cout.precision(3); // 제곱근에만 유효 숫자 지정
		cout << setw(15) << setfill('_') << (double)sqrt(i); // 제곱근은 실수, 따라서 double로 형변환

		cout.precision(prec); // 초기값으로 유효 숫자 복원
		cout << endl;
	}
}
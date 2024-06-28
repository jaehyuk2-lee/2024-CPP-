#include <iostream>
#include <fstream> // 파일 읽기 쓰기를 위한 클래스
using namespace std;

int main() {
	ifstream fin("C:\\Windows\\system.ini", ios::in|ios::binary);
	// 파일을 읽어 올 객체, 읽어올 파일의 경로를 설정, '\r'까지 읽기 위해 바이너리 모드로 설정
	ofstream fout("C:\\Temp\\system.txt", ios::in | ios::binary);
	// 읽은 파일을 복사해 다른 파일에 복사할 객체, 복사할 파일의 경로를 설정

	if (!fin || !fout) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}
	// fin, fout 객체가 모두 생성되어야 실행

	cout << "복사 시작..." << endl;
	int size = 0;
	fin.seekg(0, ios::end); // get포인터를 파일의 끝으로 이동시킨다.
	size = fin.tellg(); // 현재 get 포인터의 위치를 정수 값으로 저장한다.
	// 문자를 바이트 단위로 저장하기 때문에, 마지막 위치의 값이 실제 파일의 바이트 크기가 된다.

	fin.seekg(0, ios::beg); // get포인터를 다시 앞으로 이동시킨다.

	char* tmp = new char[size / 10]; // 10%씩 읽어 오기 위해, 10으로 나눈 size 만큼 임시 버퍼를 생성한다.

	for (int i = 1; i <= 10; i++) {
		fin.read(tmp, size / 10); // 10%만큼 읽어 tmp에 저장
		fout.write(tmp, fin.gcount()); // 방금 읽어온 문자 수만큼 다른 파일에 복사해 작성한다.
		cout << "." << fin.gcount() << "B " << i * 10 << "%" << endl;
	}
	cout << size << "B 복사 완료" << endl;

	fin.close();
	fout.close();
	delete[] tmp;
}
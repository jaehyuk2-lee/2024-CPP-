#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* file) {
	if (file == NULL) throw "NULL"; // file이 NULL 포인터이면 NULL을 throw

	ifstream fin(file, ios::in | ios::binary);
	if (!fin) throw -1; // 열기가 실패하면 -1을 throw

	fin.seekg(0, ios::end); // 파일의 마지막 위치에 get 포인터를 이동시키고
	int length = fin.tellg(); // 위치정보를 저장 (파일의 크기)
	return length;
} // 파일크기를 리턴하는 함수


int main() {
	try {
		int n = getFileSize("C:\\Windows\\system.ini");
		cout << "파일 크기 = " << n << endl; // 파일 크기 = 219가 출력됨

		int m = getFileSize(NULL);
		cout << "파일 크기 = " << m << endl; // 파일크기 = -1이 출력됨

	} // getFileSize 중간에 throw가 발생 가능 -> getFileSize함수를 사용하는 구간을 try 블록 처리

	catch (int a) { // 정수 자료가 throw 된다면, 파일열기 실패
		cout << "파일 열기 실패" << endl;
	}
	catch (const char* s) { // 문자열 자료가 throw 된다면, "NULL"이 throw됨 -> file이 NULL포인터
		cout << "예외 발생 : 파일명이 "<< s <<"입니다." << endl;
	}
}
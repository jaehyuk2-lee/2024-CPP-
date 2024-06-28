#include <iostream>
using namespace std;

class Sample {
public:
    Sample(int n) { // 생성자
        size = n;
        p = new int[n]; // n개 정수 배열의 동적 생성
    } 
    void read() {
        for (int i = 0; i < size; i++) {
            cin >> p[i];
        } // 반복문으로 공백을 구분해서 입력받기
    } // 동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력 받음

    void write() {
        for (int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    } // 정수 배열을 화면에 출력

    int big() {
        int max = p[0];
        for (int i = 1; i < size; i++) {
            if (p[i] > max) {
                max = p[i];
            }
        } // 모든 배열을 확인하면서 max값보다 큰값이 있는지 확인하고 있으면 max값을 최신화 해준다 (완전탐색 알고리즘)

        return max;
    } // 정수 배열에서 가장 큰 수 리턴

    ~Sample() {
        delete[] p;
    } // 소멸자, 객체가 소멸할 때 동적생성한 p객체 메모리 삭제

private:
    int* p;
    int size;
};

int main() {
    Sample s(10); // 10개 정수 배열을 가진 Sample 객체 생성
    s.read(); // 키보드에서 정수 배열 읽기
    s.write(); // 정수 배열 출력
    cout << "가장 큰 수는 " << s.big() << endl; // 가장 큰 수 출력
}
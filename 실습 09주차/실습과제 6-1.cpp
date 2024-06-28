#include <iostream>
using namespace std;

class Matrix {
    int arr[4];
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
    }

    void show() {
        cout << "Matrix = { " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " }\n";
    }

    Matrix operator+ (const Matrix& a) {
        Matrix b; // 새로운 객체 생성
        for (int i = 0; i < 4; i++) {
            b.arr[i] = arr[i] + a.arr[i];
        } // 피연산자 객체들의 값을 더해서 새로운 객체의 배열에 저장한다

        return b; // 값을 저장한 객체를 반환한다
    }

    Matrix operator= (const Matrix& a) {
        for (int i = 0; i < 4; i++) {
            arr[i] = a.arr[i];
        }
        return *this;
    }

    void operator+= (const Matrix& a) {
        for (int i = 0; i < 4; i++) {
            arr[i] += a.arr[i];
        } // 현재 객체의 배열에 피연산자 객체 배열의 값을 더한다.
    }

    bool operator== (const Matrix& a) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
            // 현재 객체의 배열과 피연산자 객체배열을 비교한다.
            // 하나라도 다른값이 있다면 false를 리턴한다.
        }
        return true; // 반복문이 끝났다면 모든 값이 같기 때문에 true를 리턴한다.
    }
};

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b; // 덧셈, 대입 연산자 구현 필요
    a += b; // 증가 연산자 구현 필요
    a.show();
    b.show();
    c.show();
    if (a == c) // 비교 연산자 구현 필요
        cout << "a and c are the same" << endl;
}
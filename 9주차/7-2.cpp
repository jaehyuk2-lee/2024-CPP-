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

    friend void operator >> (const Matrix&, int*);
    friend void operator << (Matrix&, int* x);
    // Matrix의 배열은 private접근 지정자로 외부에 선언한 함수는 접근할 수 없다.
    // friend를 클래스 내부에 선언해서 외부 함수에서 접근할 수 있게 공유한다.
};

void operator >> (const Matrix& a, int* x) {
    for(int i = 0; i < 4; i++) {
        x[i] = a.arr[i];
    }
} // >> 연산자는 피연산자의 원소에 객체의 배열원소를 대입한다.
void operator << (Matrix& a, int* x) {
    for(int i = 0; i < 4; i++) {
        a.arr[i] = x[i];
    }
} // << 연산자는 객체의 배열원소에 피연산자의 원소를 대입한다.

int main() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = {1, 2, 3, 4}; // 2차원 행렬의 4 개의 원소 값
    a >> x;                        // a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
    b << y;                        // 배열 y의 원소 값을 b의 각 원소에 설정
    for (int i = 0; i < 4; i++)
        cout << x[i] << ' '; // x[] 출력
    cout << endl;
    b.show();
}
#include <iostream>
using namespace std;

class Matrix {
    int arr[4];
public:
    Matrix(int a=0, int b=0, int c=0, int d=0) {
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
    }

    void show() {
        cout << "Matrix = { " << arr[0] <<  " " << arr[1] << " " << arr[2] << " " << arr[3] << " }\n";
    }

    friend Matrix operator+ (const Matrix&, const Matrix&);
    friend void operator+= (Matrix&, const Matrix&);
    friend bool operator== (const Matrix&, const Matrix&);
};

Matrix operator+ (const Matrix& a, const Matrix& b) {
        Matrix c; // 새로운 객체 생성
        for(int i = 0; i < 4; i++) {
            c.arr[i] = a.arr[i]+b.arr[i];
        } // 피연산자 객체들의 값을 더해서 새로운 객체의 배열에 저장한다

        return c; // 값을 저장한 객체를 반환한다
}

void operator+= (Matrix& a, const Matrix& b) {
    for(int i = 0; i < 4; i++) {
        a.arr[i] += b.arr[i];
    } // 1번 객체의 배열에 같은 index의 b객체 배열원소의 값을 더해 수정한다.
}
// 객체를 2개 전달받을 때 1번 객체는 값이 변경되어야 되기 때문에 레퍼런스로 전달받고
// 상수화는 시키지않는다.

bool operator== (const Matrix& a, const Matrix& b) {
    for(int i = 0; i < 4; i++) {
        if(a.arr[i] != b.arr[i]) {
            return false;
        }
        // 두 객체 배열을 비교한다. 비교 중 하나라도 다른값이 있다면 false를 리턴한다.
    }
    return true; // 반복문이 끝났다면 모든 값이 같기 때문에 true를 리턴한다.
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b; // 덧셈 연산자 구현 필요
    a += b; // 증가 연산자 구현 필요
    a.show();
    b.show();
    c.show();
    if (a == c) // 비교 연산자 구현 필요
        cout << "a and c are the same" << endl;
}
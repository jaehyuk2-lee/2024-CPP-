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

    friend Matrix operator+ (const Matrix&, const Matrix&);
    friend void operator+= (Matrix&, const Matrix&);
    friend bool operator== (const Matrix&, const Matrix&);

    Matrix operator= (const Matrix& a) {
        for (int i = 0; i < 4; i++) {
            arr[i] = a.arr[i];
        }
        return *this;
    }
    // ���Կ����� �ߺ��� Ŭ���� ���ο� ���� �����ϴ�
};

Matrix operator+ (const Matrix& a, const Matrix& b) {
    Matrix c; // ���ο� ��ü ����
    for (int i = 0; i < 4; i++) {
        c.arr[i] = a.arr[i] + b.arr[i];
    } // �ǿ����� ��ü���� ���� ���ؼ� ���ο� ��ü�� �迭�� �����Ѵ�

    return c; // ���� ������ ��ü�� ��ȯ�Ѵ�
}

void operator+= (Matrix& a, const Matrix& b) {
    for (int i = 0; i < 4; i++) {
        a.arr[i] += b.arr[i];
    } // 1�� ��ü�� �迭�� ���� index�� b��ü �迭������ ���� ���� �����Ѵ�.
}
// ��ü�� 2�� ���޹��� �� 1�� ��ü�� ���� ����Ǿ�� �Ǳ� ������ ���۷����� ���޹ް�
// ���ȭ�� ��Ű���ʴ´�.

bool operator== (const Matrix& a, const Matrix& b) {
    for (int i = 0; i < 4; i++) {
        if (a.arr[i] != b.arr[i]) {
            return false;
        }
        // �� ��ü �迭�� ���Ѵ�. �� �� �ϳ��� �ٸ����� �ִٸ� false�� �����Ѵ�.
    }
    return true; // �ݺ����� �����ٸ� ��� ���� ���� ������ true�� �����Ѵ�.
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b; // ���� ������ ���� �ʿ�
    a += b; // ���� ������ ���� �ʿ�
    a.show();
    b.show();
    c.show();
    if (a == c) // �� ������ ���� �ʿ�
        cout << "a and c are the same" << endl;
}
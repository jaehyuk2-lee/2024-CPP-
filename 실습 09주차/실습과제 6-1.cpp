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
        Matrix b; // ���ο� ��ü ����
        for (int i = 0; i < 4; i++) {
            b.arr[i] = arr[i] + a.arr[i];
        } // �ǿ����� ��ü���� ���� ���ؼ� ���ο� ��ü�� �迭�� �����Ѵ�

        return b; // ���� ������ ��ü�� ��ȯ�Ѵ�
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
        } // ���� ��ü�� �迭�� �ǿ����� ��ü �迭�� ���� ���Ѵ�.
    }

    bool operator== (const Matrix& a) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
            // ���� ��ü�� �迭�� �ǿ����� ��ü�迭�� ���Ѵ�.
            // �ϳ��� �ٸ����� �ִٸ� false�� �����Ѵ�.
        }
        return true; // �ݺ����� �����ٸ� ��� ���� ���� ������ true�� �����Ѵ�.
    }
};

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b; // ����, ���� ������ ���� �ʿ�
    a += b; // ���� ������ ���� �ʿ�
    a.show();
    b.show();
    c.show();
    if (a == c) // �� ������ ���� �ʿ�
        cout << "a and c are the same" << endl;
}
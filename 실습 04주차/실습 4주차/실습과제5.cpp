#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // ������ �ִ�
using namespace std;



class Random {
public:
    int next() {
        return rand() % MAX;
    }
    int nextInRange(int a, int b) {
        return rand() % (b - a + 1) + a; // a���� b���� -> b-a+1��, a���� ����
    }
};

int main() {
    Random r;
    srand((unsigned)time(0));
    cout << "\n----------- 0���� " << MAX << "������ ���� ���� 10 �� -----------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next(); // 0���� MAX(32767) ������ ������ ����
        cout << n << ' ';
    }
    cout << endl
        << endl
        << "-- 2���� " << "4 ������ ���� ���� 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
        cout << n << ' ';
    }
    cout << endl;
}
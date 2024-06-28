#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // ������ �ִ�
using namespace std;

class EvenRandom {
public:
    int next() {
        do {
            even = rand() % MAX;
        } while (even % 2 != 0); // ���� ������ �����ϰ� ¦���� �ƴϸ� �ٽ� �ݺ�
        return even;
    }
    int nextInRange(int a, int b) {
        do {
            even = rand() % (b - a + 1) + a;
        } while (even % 2 != 0);
        return even; // ���ڹ��� ������ ������ �����ϰ� ¦���� �ƴϸ� �ٽ� �ݺ�
    }

private: // ������ ¦������ �´��� �����ؼ� Ȯ���� ������� ����
    int even;
};

int main() {
    EvenRandom r;
    srand((unsigned)time(0));
    cout << "\n------------ 0���� " << MAX << "������ ���� ¦�� 10 �� ------------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl
        << endl
        << "-- 2���� " << "10 ������ ¦�� ���� 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 10); // 2���� 10 ������ ������ ¦��
        cout << n << ' ';
    }
    cout << endl;
}
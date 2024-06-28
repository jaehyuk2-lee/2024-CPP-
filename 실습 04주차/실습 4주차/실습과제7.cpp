#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // ������ �ִ�
using namespace std;



class SelectableRandom {
public:
    SelectableRandom() {
        cout << "¦�� : 0, Ȧ�� : 1 �Է�" << endl;
        cin >> select;
    } // SelectableRandom ��ü�� ������ �� 0 �Ǵ� 1�� �Է� �޾� select ��� ������ �����Ѵ�.
    int next() {
        if (select == 0) {
            do {
                random = rand() % MAX;
            } while (random % 2 != 0);
        }
        else if (select == 1) {
            do {
                random = rand() % MAX;
            } while (random % 2 == 0);

        }
        // select�� 0 �̸� ¦���� �� �� ���� ���� ����
        // select�� 1 �̸� Ȧ���� �� �� ���� ���� ����
        return random;
    }
    int nextInRange(int a, int b) {
        if (select == 0) {
            do {
                random = rand() % (b - a + 1) + a;
            } while (random % 2 != 0);
        }
        else if (select == 1) {
            do {
                random = rand() % (b - a + 1) + a;
            } while (random % 2 == 0);

        }
        // select�� 0 �̸� ���������� ¦���� �� �� ���� ���� ����
        // select�� 1 �̸� ���������� Ȧ���� �� �� ���� ���� ����
        return random;
    }

private:
    int random; // �������� ���� �� ����
    int select;
};

int main() {
    SelectableRandom r;
    srand((unsigned)time(0));
    cout << "\n----------- 0���� " << MAX << "������ ���� ���� 10 �� -----------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next(); // 0���� MAX(32767) ������ ������ ����
        cout << n << ' ';
    }
    cout << endl
        << endl
        << "-- 2���� 9 ������ ���� ���� 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 9); // 2���� 9 ������ ������ ����
        cout << n << ' ';
    }
    cout << endl;
}
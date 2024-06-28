#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // 난수의 최댓값
using namespace std;



class SelectableRandom {
public:
    SelectableRandom() {
        cout << "짝수 : 0, 홀수 : 1 입력" << endl;
        cin >> select;
    } // SelectableRandom 객체가 생성될 때 0 또는 1을 입력 받아 select 멤버 변수에 저장한다.
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
        // select가 0 이면 짝수가 될 때 까지 난수 생성
        // select가 1 이면 홀수가 될 때 까지 난수 생성
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
        // select가 0 이면 범위내에서 짝수가 될 때 까지 난수 생성
        // select가 1 이면 범위내에서 홀수가 될 때 까지 난수 생성
        return random;
    }

private:
    int random; // 난수값이 저장 될 변수
    int select;
};

int main() {
    SelectableRandom r;
    srand((unsigned)time(0));
    cout << "\n----------- 0에서 " << MAX << "까지의 랜덤 정수 10 개 -----------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next(); // 0에서 MAX(32767) 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl
        << endl
        << "-- 2에서 9 까지의 랜덤 정수 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 9); // 2에서 9 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl;
}
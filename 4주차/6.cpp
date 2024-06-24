#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // 난수의 최댓값
using namespace std;

class EvenRandom {
public:
    int next() {
        do {
            even = rand() % MAX;
        } while (even % 2 != 0); // 먼저 난수를 생성하고 짝수가 아니면 다시 반복
        return even;
    }
    int nextInRange(int a, int b) {
        do {
            even = rand() % (b - a + 1) + a;
        } while (even % 2 != 0);
        return even; // 숫자범위 내에서 난수를 생성하고 짝수가 아니면 다시 반복
    }

private: // 난수가 짝수값이 맞는지 저장해서 확인할 멤버변수 설정
    int even;
};

int main() {
    EvenRandom r;
    srand((unsigned)time(0));
    cout << "\n------------ 0에서 " << MAX << "까지의 랜덤 짝수 10 개 ------------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl
         << endl
         << "-- 2에서 " << "10 까지의 짝수 정수 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 10); // 2에서 10 사이의 랜덤한 짝수
        cout << n << ' ';
    }
    cout << endl;
}
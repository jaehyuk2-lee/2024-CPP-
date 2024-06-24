#include <iostream>
#include <cstdlib>
#include <ctype.h>
#define MAX 32768 // 난수의 최댓값
using namespace std;



class Random {
public:
    int next() {
        return rand()%MAX;
    }
    int nextInRange(int a, int b) {
        return rand()%(b-a+1)+a; // a부터 b까지 -> b-a+1개, a부터 시작
    }
};

int main() {
    Random r;
    srand((unsigned)time(0));
    cout << "\n----------- 0에서 " << MAX << "까지의 랜덤 정수 10 개 -----------" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next(); // 0에서 MAX(32767) 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl
         << endl
         << "-- 2에서 " << "4 까지의 랜덤 정수 10--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl;
}
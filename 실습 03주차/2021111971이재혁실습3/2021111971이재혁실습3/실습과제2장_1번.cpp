#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        cout << i;
        if (i % 10 == 0) cout << "\n";
        else cout << "\t";
    }
    /* 1부터 100까지 증가하면서 숫자를 출력하는데,
    10의 배수일 때마다 \t이 아닌 \n을 출력해 줄을 바꾼다.*/

    return 0;
}
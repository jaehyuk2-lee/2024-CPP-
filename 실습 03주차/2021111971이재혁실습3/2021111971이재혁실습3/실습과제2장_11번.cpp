#include <iostream>
using namespace std;

int main() {
    int k, n = 0;
    int sum = 0;
    cout << "끝 수를 입력하세요>>"; // printf대신 cout을 사용해 출력한다.
    cin >> n; // scanf대신 cin을 사용해 입력을 받는다.

    for (k = 1; k <= n; k++) {
        sum += k;
    }
    cout << "1에서 " << n << "까지의 합은 " << sum << "입니다." << endl;

    // return 0;을 생략할 수 있다.
}
#include <iostream>
using namespace std;

int big(int, int, int c = -2147483648);
// 값이 두개만 들어올 때 마지막 매개변수를 디폴트 매개변수로 설정한다.
// 디폴트 값은 정수가 표현할 수 있는 가장 작은 값이기 때문에, a와 b 중 큰 값 이하이다.

int main() {
    int x = big(3, 5);       // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60);    // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 60, 50); // 30과 60 중 큰 값 600이 최대값 50보다 크므로, 50 리턴
    cout << x << ' ' << y << ' ' << z << endl;
}

int big(int a, int b, int c) {
    int big = (a>b?a:b); // a와 b를 비교해서 a>b면 a, a<=b면 b를 저장
    return big>c?big:c; // a와 b를 비교해서 큰 값을 저장하고 그 값과 c를 비교해서 큰값을 리턴
}
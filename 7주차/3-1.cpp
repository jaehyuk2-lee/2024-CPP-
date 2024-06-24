#include <iostream>
using namespace std;

int big(int, int);
int big(int, int, int);
// 전달하는 매개변수의 개수는 2개인 경우와 3개인경우가 있으므로 함수 중복으로 2개의 같은이름의 함수를 작성한다.

int main() {
    int x = big(3, 5);       // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60);    // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 60, 50); // 30과 60 중 큰 값 600이 최대값 50보다 크므로, 50 리턴
    cout << x << ' ' << y << ' ' << z << endl;
}

int big(int a, int b) {
    return a>b?a:b; // a와 b를 비교해서 a>b면 a, a<=b면 b를 리턴
}

int big(int a, int b, int c) {
    int big = (a>b?a:b); // a와 b를 비교해서 a>b면 a, a<=b면 b를 저장
    return big>c?big:c; // a와 b를 비교해서 큰 값을 저장하고 그 값과 c를 비교해서 큰값을 리턴
}
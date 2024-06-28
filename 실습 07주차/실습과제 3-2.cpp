#include <iostream>
using namespace std;

int big(int, int, int c = 100);
// 값이 두개만 들어올 때 마지막 매개변수를 디폴트 매개변수로 설정한다.
// c가 입력받아지지 않았을 때는 100과 비교해서 큰 값이 100보다 큰 경우
// 100을 출력한다.

int main() {
    int x = big(3, 5);       // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60);    // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 600, 250); // 30과 60 중 큰 값 600이 최대값 250보다 크므로, 250 리턴
    cout << x << ' ' << y << ' ' << z << endl;
}

int big(int a, int b, int c) {
    int comp = (a > b ? a : b); // a와 b를 비교해서 a>b면 a, a<=b면 b를 저장
    return comp > c ? c : comp;
    // a와 b를 비교해서 큰 값을 저장하고 그 값이 c보다 크다면
    // c 아니면 저장한 값을 리턴
}
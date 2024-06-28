#include <iostream>
using namespace std;

void half(double&); // 전달된 값을 변경해야 되기 때문에 레퍼런스로 전달받아 값을 변경한다.

int main() {
    double n = 20;
    half(n); // n의 반값을 구해 n을 바꾼다. 
    cout << n; // 10이 출력된다.
}

void half(double& a) { // a라는 변수를 새로 만들어서 n값을 할당하는 것이 아니라, a를 전달받은 n 자체로 본다.
    a /= 2;
}
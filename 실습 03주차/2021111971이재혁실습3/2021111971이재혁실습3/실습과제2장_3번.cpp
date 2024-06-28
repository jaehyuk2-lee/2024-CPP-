#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "두 수를 입력하라>> ";
    cin >> num1 >> num2; // cin을 통해 공백으로 두개의 값을 변수에 입력받는다.

    if (num1 > num2) {
        cout << "큰수 = " << num1 << "\n";
    }
    else cout << "큰수 = " << num2 << "\n";
    // 두수를 비교해 큰 수를 출력한다.

    return 0;
}
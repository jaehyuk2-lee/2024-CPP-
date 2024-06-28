#include <iostream>
using namespace std;

bool bigger(int, int, int&);

int main() {
    int num1, num2, big;
    cout << "정수 2개 입력 : ";
    cin >> num1 >> num2;

    if (bigger(num1, num2, big)) { // 함수가 true를 반환했다면 두 수는 같기 때문에 같다
        cout << "두 수는 같습니다.\n";
    }
    else cout << big << "이 더 큰 수입니다.\n"; // false이면 큰 값이 big에 전달되었기 때문에 big을 출력

    return 0;
}

bool bigger(int a, int b, int& big) {
    // big의 값에 큰 값을 전달하면 되기 때문에 num1, num2는 레퍼런스 변수를 사용하지 않아도 된다.
    if (a == b) {
        return true;
    }
    else if (a > b) {
        big = a;
        return false;
    }
    else {
        big = b;
        return false;
    }
}
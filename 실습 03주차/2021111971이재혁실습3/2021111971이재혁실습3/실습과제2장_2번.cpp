#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << j << "X" << i << "=" << j * i << "\t";
        } // 오른쪽으로 갈수록 앞에서 곱해지는 숫자가 늘어나기 때문에 j*i를 출력해준다.
        cout << "\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        cout << i;
        if (i % 10 == 0) cout << "\n";
        else cout << "\t";
    }
    /* 1���� 100���� �����ϸ鼭 ���ڸ� ����ϴµ�,
    10�� ����� ������ \t�� �ƴ� \n�� ����� ���� �ٲ۴�.*/

    return 0;
}
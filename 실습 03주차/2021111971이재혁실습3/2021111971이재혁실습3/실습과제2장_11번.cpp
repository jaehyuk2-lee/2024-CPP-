#include <iostream>
using namespace std;

int main() {
    int k, n = 0;
    int sum = 0;
    cout << "�� ���� �Է��ϼ���>>"; // printf��� cout�� ����� ����Ѵ�.
    cin >> n; // scanf��� cin�� ����� �Է��� �޴´�.

    for (k = 1; k <= n; k++) {
        sum += k;
    }
    cout << "1���� " << n << "������ ���� " << sum << "�Դϴ�." << endl;

    // return 0;�� ������ �� �ִ�.
}
#include <iostream>
using namespace std;

int main()
{
    float arr[5]; // 5���� ������ ���� �� ����
    cout << "5���� �Ǽ��� �Է��ض�>>";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    /* cin�� ������������ �ڷḦ �Է��ϱ� ������
    �ݺ����� 5���� �Ǽ��� �������� �Է¹��� �� �ִ�.*/

    float max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "���� ū �� = " << max << "\n";
    return 0;
}
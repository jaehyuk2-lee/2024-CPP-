#include <iostream>
using namespace std;

int arr[5] = { 0 };
// 3��° �迭�� ����Ʈ �Ű������� ����ϱ� ���� ���� ũ�� 5�� ��Ұ� 0�� �迭 ����, ���� ���Ҷ� ������ ���� �ʱ�����
int add(int*, int, int* b = arr);
// b�迭�� �Է¹޾����� ���� ��쿡�� ũ�� 5 �� 0 �� ���� ���� �迭�� ����

int main() {
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8, 9, 10 };
    int c = add(a, 5);    // �迭 a�� ������ ��� ���� �� ����
    int d = add(a, 5, b); // �迭 a�� b�� ������ ��� ���� �� ����
    cout << c << endl;    // 15 ���
    cout << d << endl;    // 55 ���
}

int add(int* a, int size, int* b) {
    int ret = 0;
    for (int i = 0; i < size; i++) {
        ret = ret + a[i] + b[i];
    }
    return ret;
}
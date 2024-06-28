#include <iostream>
using namespace std;

int add(int*, int); // �迭 1���� �����ڷᰡ ���� �� ����� �Լ�
int add(int*, int, int*); // �迭, ����, �迭 �ڷᰡ ���� �� ����� �Լ�

int main() {
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8, 9, 10 };
    int c = add(a, 5);    // �迭 a�� ������ ��� ���� �� ����
    int d = add(a, 5, b); // �迭 a�� b�� ������ ��� ���� �� ����
    cout << c << endl;    // 15 ���
    cout << d << endl;    // 55 ���
}

int add(int* arr, int size) {
    int ret = 0; // �迭�� ���� ������ ����
    for (int i = 0; i < size; i++) {
        ret += arr[i];
    }
    return ret;
}
int add(int* arr1, int size, int* arr2) {
    int ret = 0;
    for (int i = 0; i < size; i++) {
        ret = ret + arr1[i] + arr2[i];
    }
    return ret;
} // �迭�� 2�� ������ �迭 2�� ��� ���Ѱ��� ������ �����Ѵ�
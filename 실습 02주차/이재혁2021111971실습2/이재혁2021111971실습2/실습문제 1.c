// 2024.03.14
// ��ȭ���α׷���02������
// �ǽ� 1��, double�� �迭���� �ִ��� �ּҸ� ��ȯ�ϴ� �Լ��� ������

#include <stdio.h>
double* get_max(double*, int);

int main() {
    double arr[10] = { 1.2, 2.3, 3.4, 4.1, 2.4, 8.2, 3.593, 0.123, 5.412, 7.26 };
    printf("�ִ���%.3f�̰�, �ش����� �ּҴ�%p�Դϴ�.\n", *(get_max(arr, 10)), get_max(arr, 10));
    // �Լ��� return �ϴ� ���� �״�� ���

    return 0;
}

double* get_max(double* A, int size) {
    int max = A[0];
    int max_index = 0; // �Ź� �ٲ�� �ִ��� ��ġ�� ����� ����
    for (int i = 1; i < size; i++) {
        if (A[i] > max) {
            max = A[i];
            max_index = i; // �ִ��� ���ŵǸ� index������ ����
        }
    }
    return &A[max_index]; // �迭���� �ִ��� ����� �ּҸ� ��ȯ
}
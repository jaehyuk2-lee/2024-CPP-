// 2024.03.08
// �ǽ����� 8��, �ڷ����� double�� 1���� �迭�� ������ ���� �ʱ�ȭ�ϰ�, ù ��° ������ �迭 source��
// �� ��° ������ �迭 target�� �����ϴ� �Լ��� ����� ����� �˾ƺ��� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>
#include <stdlib.h> // �����Ҵ��� ���ؼ� ����� malloc�Լ��� ���� ���Խ�ŵ�ϴ�.

void copyarray(double*, double*, int);


int main() {
    double ary[5] = { 3.12, 5.14, 7.25, 7.48, 5.91 };
    double* ary_copied;
    ary_copied = (double*)malloc(sizeof(double) * 5); // ������ ���Ҹ� ������ �޸𸮸� ���� �Ҵ��մϴ�.

    printf("�־��� �迭 : ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", ary[i]);
    }
    printf("\n");

    copyarray(ary, ary_copied, 5);

    free(ary_copied); // �����Ҵ��� �޸𸮸� �������ݴϴ�.
    return 0;
}

void copyarray(double* source, double* target, int size) {
    for (int i = 0; i < size; i++) {
        target[i] = source[i]; // ���� �Ҵ��� �ּҿ� ���� �Լ��� ���Ҹ� �����մϴ�.
    }

    printf("���� �� �迭 : ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", target[i]);
    }
    printf("\n");
}

// ó������ copyarray()�� �����Ҵ� �� �ּҸ� �����ؼ�, main���� ������ ������ ����Ϸ� �߽��ϴ�.
// ������ �׷��� ���� target �迭�� ���ڷ� ���� ������ ���ٰ� �����ؼ�,
// �Լ� ������ ���Ҹ� �����ϰ� ����ϰ� �����Ҵ��� �����ϴ� void�Լ��� �ۼ��߽��ϴ�.
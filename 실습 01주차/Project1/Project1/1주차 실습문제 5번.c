// 2024.03.07
// �ǽ����� 5��, ������ �ٲٴ� ���α׷��� void swap(int*, int*) �ۼ�, ����� �˾ƺ��� ���α׷� �ۼ�

#include <stdio.h>
void swap(int*, int*);

int main() {
    int num1, num2;
    printf("num1 : ");
    scanf_s("%d", &num1);
    printf("num2 : ");
    scanf_s("%d", &num2);

    printf("�ٲ�� �� num1 : %d, num2 : %d\n", num1, num2);
    swap(&num1, &num2);
    printf("�ٲ� ��   num1 : %d, num2 : %d\n", num1, num2);

    return 0;
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// ���� swap�Լ��� �� ���ڸ� int�� �޾Ҵٸ�, main�Լ��� �ִ� ������� ������ �ٸ� ���ο� �����Դϴ�.
// ���� ������ swap�Լ��� ���� �� �������� �����̱� ������, return���� ���� swap�Լ������� �ǹ̰� ���� �����Դϴ�.
// ���� int * �� �ּ� ���� ���ڷ� �Ѱܹ޾� �װ��� ����Ű�� �����͵��� ����� ����Ű�� ���� �ٲ� ����ϴ�.
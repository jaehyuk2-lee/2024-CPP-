// 2024.03.07
// �ǽ����� 3��, 1���� 100���� �����ϳ� �߻�, ����ڰ� ���ߴ� ���α׷�
// ���� : setNumber():���� ����, number�� ���⶧ ���� �ݺ�, ��Ʈ �ڼ���, min, max��� ���� �ܺκ���, �õ�Ƚ�� trycount�� �Ź����
// setNumber(),printHead(), printHigher( ), printLower( ), printAnswer()�� ����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number;
static int min = 1;
static int max = 100;
int trycount = 0; // ��� �Լ����� �õ�Ƚ���� �߰��ϰų�, ���� �����ؾ� �ϱ� ������ ���������� �����߽��ϴ�.
int is_end = 0; // ���α׷��� �������� ������ ���� �Դϴ�.

void setNumber(); // �Լ����� �ִ�, �ּ� ����̳�, ���� �������� �����̹Ƿ� ��ȯ���� ���� ������ void������ �����߽��ϴ�.
void printHead();
void printHigher(int);
void printLower(int);
void printAnswer();

int main() {
    int input; // ����ڰ� �Է� �� �����Դϴ�
    setNumber();
    while (is_end == 0) { // ������ ����� is_end�� �ʱⰪ�� 0�϶��� ��� �ݺ��մϴ�.
        printHead();
        scanf_s("%d", &input);
        if (input > max || input < min) {
            printf("���� ���� �� �Դϴ�.\n"); // �Է� ���� ���� �ִ�, �ּҰ��� ���� �ۿ� ���� ��� �Ʒ��� Ȯ���� �ʿ䰡 �����ϴ�.
            trycount++;
            continue;
        }
        trycount++; // �Է¸��� Ƚ���� �߰��մϴ�

        if (number > input) {
            printLower(input);
        }
        else if (number < input) {
            printHigher(input);
        }
        else printAnswer();
    }

    return 0;
}

void setNumber() {
    srand(time(NULL));
    number = rand() % 100 + 1; // 1 ~ 100 ������ ������ �����մϴ�.
    printf("���������Ϸ�\n");
}

void printHead() { // ���÷� ��ȭ�ϴ� ������ ������ �ݺ��� ���� �κи��� ������ݴϴ�.
    printf("������ ������ %d~%d �Դϴ�.\n", min, max);
    printf("���� �Է� : ");
}

void printLower(int m) {
    printf("�Է¹��� ���ڰ� �۽��ϴ�.\n");
    min = m + 1; // m�� �̹� �ƴ� ���� �˰� �����Ƿ� �� ���� ���� �ּ� ������ ����ݴϴ�.
}

void printHigher(int M) {
    printf("�Է¹��� ���ڰ� Ů�ϴ�.\n");
    max = M - 1; // M�� �̹� �ƴ� ���� �˰� �����Ƿ� �� ���� ���� �ִ� ������ ����ݴϴ�.
}

void printAnswer() { // ������ ����� ������ �õ� Ƚ���� ����ϰ� is_end�� ���� �ٲ��ݴϴ�.
    printf("�����Դϴ�. �õ�Ƚ�� : %d\n", trycount);
    is_end = 1;
}
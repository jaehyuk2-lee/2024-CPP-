// 2024.03.14
// �ǽ� 5��
// ����ü student�� �����ϰ�, �л� 10���� �����Ͽ� ������ ���� �Է��ϰ� ����Ͻÿ�. �̸�, �й�, �������, �а�, ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // ���ڿ� ���縦 ����  strcpy�Լ��� ����ϱ� ���� ���

typedef struct
{
    char name[20];
    char number[11];
    float average;
    char major[20];
    char career[20];
} student;// �̸�, �й�, �������, �а�, ������ �ڷḦ ���� student ����

int main()
{
    student arr[10]; // student �ڷ� 10���� ������ �迭 ����

    strcpy(arr[0].name, "A");
    strcpy(arr[0].number, "2021000001");
    arr[0].average = 4.3;
    strcpy(arr[0].major, "computer science");
    strcpy(arr[0].career, "AI");

    strcpy(arr[1].name, "B");
    strcpy(arr[1].number, "2021000002");
    arr[1].average = 4.0;
    strcpy(arr[1].major, "computer science");
    strcpy(arr[1].career, "engineer");

    strcpy(arr[2].name, "C");
    strcpy(arr[2].number, "2021000003");
    arr[2].average = 3.7;
    strcpy(arr[2].major, "multimedia");
    strcpy(arr[2].career, "engineer");

    strcpy(arr[3].name, "D");
    strcpy(arr[3].number, "2021000004");
    arr[3].average = 3.3;
    strcpy(arr[3].major, "computer science");
    strcpy(arr[3].career, "AI");

    strcpy(arr[4].name, "E");
    strcpy(arr[4].number, "2021000005");
    arr[4].average = 3.0;
    strcpy(arr[4].major, "computer science");
    strcpy(arr[4].career, "engineer");

    strcpy(arr[5].name, "F");
    strcpy(arr[5].number, "2021000006");
    arr[5].average = 2.7;
    strcpy(arr[5].major, "computer science");
    strcpy(arr[5].career, "backend");

    strcpy(arr[6].name, "G");
    strcpy(arr[6].number, "2021000007");
    arr[6].average = 2.3;
    strcpy(arr[6].major, "computer science");
    strcpy(arr[6].career, "AI");

    strcpy(arr[7].name, "H");
    strcpy(arr[7].number, "2021000008");
    arr[7].average = 2.0;
    strcpy(arr[7].major, "computer science");
    strcpy(arr[7].career, "engineer");

    strcpy(arr[8].name, "I");
    strcpy(arr[8].number, "2021000009");
    arr[8].average = 1.7;
    strcpy(arr[8].major, "computer science");
    strcpy(arr[8].career, "backend");

    strcpy(arr[9].name, "J");
    strcpy(arr[9].number, "2021000010");
    arr[9].average = 1.3;
    strcpy(arr[9].major, "computer science");
    strcpy(arr[9].career, "AI");
    

    for (int i = 0; i < 10; i++) {
        printf("�л� %d ���� : \n", i + 1);
        printf("�̸� : %s\n", arr[i].name);
        printf("�й� : %s\n", arr[i].number);
        printf("��� ���� : %.1f\n", arr[i].average);
        printf("�а� : %s\n", arr[i].major);
        printf("���� : %s\n", arr[i].career);
        printf("\n");
    }
    // �迭 ���� ���ҵ��� ��� ���� �ڷ����� ������ �����Ƿ� �ݺ����� i�� ����� �ݺ� ���

    return 0;
}
// 2024.03.14
// �ǽ� 05
// ����ü professor �� �����ϰ�, ���� 5 ���� �����Ͽ� ������ ���� �Է��ϰ� ����Ͻÿ�. ��������, ������(���� ��), �а�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char pNumber[12];
    char address[20];
    char subject[30];
    char major[25];
} professor; // ��������, ������(���� ��), �а� �ڷḦ �����ϴ� ����ü professor ����

int main()
{
    professor p[5]; // professor�� �ڷḦ 5�� ������ �ִ� �迭���� (professor 5�� ����)

    strcpy(p[0].name, "������ 1");
    strcpy(p[0].pNumber, "11111111");
    strcpy(p[0].address, "�������б�");
    strcpy(p[0].subject, "��ǻ�ͱ���");
    strcpy(p[0].major, "��ǻ�Ͱ���");

    strcpy(p[1].name, "������ 2");
    strcpy(p[1].pNumber, "22222222");
    strcpy(p[1].address, "�������б�");
    strcpy(p[1].subject, "�ڷᱸ��");
    strcpy(p[1].major, "��ǻ�Ͱ���");

    strcpy(p[2].name, "������ 3");
    strcpy(p[2].pNumber, "33333333");
    strcpy(p[2].address, "�������б�");
    strcpy(p[2].subject, "��ü�������α׷���");
    strcpy(p[2].major, "��ǻ�Ͱ���");

    strcpy(p[3].name, "������ 4");
    strcpy(p[3].pNumber, "44444444");
    strcpy(p[3].address, "�������б�");
    strcpy(p[3].subject, "�������α׷���");
    strcpy(p[3].major, "��ǻ�Ͱ���");

    strcpy(p[4].name, "������ 5");
    strcpy(p[4].pNumber, "55555555");
    strcpy(p[4].address, "�������б�");
    strcpy(p[4].subject, "���а���");
    strcpy(p[4].major, "����ý��۰���");
    // �⺻���� �Է�

    printf("����������� : \n\n");
    for (int i = 0; i < 5; i++) {
        printf("������ %d ����: \n", i + 1);
        printf("�̸�: %s\n", p[i].name);
        printf("��ȭ��ȣ: %s\n", p[i].pNumber);
        printf("�ּ�: %s\n", p[i].address);
        printf("������: %s\n", p[i].subject);
        printf("����: %s\n\n", p[i].major);
    }
    // �ݺ����� ���� �迭�� ���ҿ� �����Ͽ� ���

    return 0;
}
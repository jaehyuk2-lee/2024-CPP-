// 2024.03.14
// �ǽ�07
// ����ü student�� �����ϰ�, �л� 10���� �����Ͽ� ������ ���� �Է��ϰ� ���, ��������, �й�, �������, �а�, ����, ��������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char pNumber[12];
    char address[20];
} professor; // ���� ����ü ����

typedef struct
{
    char name[20];
    char number[11];
    float average;
    char major[20];
    char career[20];
    professor* p; // ��米���� �ڷᰡ ����� �ּҰ��� ������ ��米�� ������ ���ٰ���
} person; // ���(�л�)�� ����ü ����

int main() {
    professor p[5]; //���� ���� 5���� ������ �迭 ����

    strcpy(p[0].name, "������ 1");
    strcpy(p[0].pNumber, "11111111");
    strcpy(p[0].address, "�������б�");

    strcpy(p[1].name, "������ 2");
    strcpy(p[1].pNumber, "22222222");
    strcpy(p[1].address, "�������б�");

    strcpy(p[2].name, "������ 3");
    strcpy(p[2].pNumber, "33333333");
    strcpy(p[2].address, "�������б�");

    strcpy(p[3].name, "������ 4");
    strcpy(p[3].pNumber, "44444444");
    strcpy(p[3].address, "�������б�");

    strcpy(p[4].name, "������ 5");
    strcpy(p[4].pNumber, "55555555");
    strcpy(p[4].address, "�������б�");
    // �������� ���� �Է�

    person student[10]; // �л� ���� 10�� ������ �迭 ����, ������ 1~5�� 2�� �л��� ����Ѵ�.
    strcpy(student[0].name, "stu. A");
    strcpy(student[0].number, "2021000001");
    student[0].average = 4.3;
    strcpy(student[0].major, "computer science");
    strcpy(student[0].career, "AI");
    student[0].p = &p[0]; // ��米���� ������ ����� �ּҸ� �Է�

    strcpy(student[1].name, "stu. B");
    strcpy(student[1].number, "2021000002");
    student[1].average = 4.0;
    strcpy(student[1].major, "computer science");
    strcpy(student[1].career, "engineer");
    student[1].p = &p[0];

    strcpy(student[2].name, "stu. C");
    strcpy(student[2].number, "2021000003");
    student[2].average = 3.7;
    strcpy(student[2].major, "multimedia");
    strcpy(student[2].career, "engineer");
    student[2].p = &p[1];

    strcpy(student[3].name, "stu. D");
    strcpy(student[3].number, "2021000004");
    student[3].average = 3.3;
    strcpy(student[3].major, "computer science");
    strcpy(student[3].career, "AI");
    student[3].p = &p[1];

    strcpy(student[4].name, "stu. E");
    strcpy(student[4].number, "2021000005");
    student[4].average = 3.0;
    strcpy(student[4].major, "computer science");
    strcpy(student[4].career, "engineer");
    student[4].p = &p[2];

    strcpy(student[5].name, "stu. F");
    strcpy(student[5].number, "2021000006");
    student[5].average = 2.7;
    strcpy(student[5].major, "computer science");
    strcpy(student[5].career, "studentkend");
    student[5].p = &p[2];

    strcpy(student[6].name, "stu. G");
    strcpy(student[6].number, "2021000007");
    student[6].average = 2.3;
    strcpy(student[6].major, "computer science");
    strcpy(student[6].career, "AI");
    student[6].p = &p[3];

    strcpy(student[7].name, "stu. H");
    strcpy(student[7].number, "2021000008");
    student[7].average = 2.0;
    strcpy(student[7].major, "computer science");
    strcpy(student[7].career, "engineer");
    student[7].p = &p[3];

    strcpy(student[8].name, "stu. I");
    strcpy(student[8].number, "2021000009");
    student[8].average = 1.7;
    strcpy(student[8].major, "computer science");
    strcpy(student[8].career, "backend");
    student[8].p = &p[4];

    strcpy(student[9].name, "stu. J");
    strcpy(student[9].number, "2021000010");
    student[9].average = 1.3;
    strcpy(student[9].major, "computer science");
    strcpy(student[9].career, "AI");
    student[9].p = &p[4];

    printf("�л��������:\n");
    for (int i = 0; i < 10; i++) {
        printf("�л� %d ����: \n", i + 1);
        printf("�̸�: %s\n", student[i].name);
        printf("�й�: %s\n", student[i].number);
        printf("��� ����: %.1f\n", student[i].average);
        printf("�а�: %s\n", student[i].major);
        printf("����: %s\n", student[i].career);
        printf("���� ���� �̸�: %s\n", student[i].p->name);
        printf("���� ���� ��ȭ��ȣ: %s\n", student[i].p->pNumber);
        printf("���� ���� �ּ�: %s\n\n", student[i].p->address);
    } // �л������� ���, �л����� ��½� ��米���� ������ ������ �̹Ƿ� -> ���� �����ڸ� ����� �ڷῡ �����Ѵ�

    return 0;
}
// �Ұ�
// ����ü ���ο� �ٸ� ����ü�� ���� ������ ���� �� ���ο� ��� ������ ����� �� ����
// �����͸� ���� �ٸ� ����ü ��ü�� �ּҸ� �޾� �ڷῡ �����ϴ°� �޸� ��뿡 ȿ�����̶�� ������ ������ϴ�.
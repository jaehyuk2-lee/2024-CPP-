// 2024.03.14
// �ǽ� 4��
// ����ü person�� �����ϰ�, ��� 2���� �����Ͽ� ������ ���� �Է��ϰ� ����Ͻÿ�. �̸� ��ȭ��ȣ �ּ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // ���ڿ� ���縦 ����  strcpy�Լ��� ����ϱ� ���� ���

typedef struct
{
    char name[20];
    char pNumber[11]; // ��ȭ��ȣ -> 010******** 0���� �����ϱ� ������ ��ǻ�Ͱ� 8������ �ν� ���� ���ڿ��� ����
    char address[20];
} Person; // �̸�, ��ȭ��ȣ, �ּ��� ���� �ڷ�� ������ Person ����

int main() {
    Person p1, p2;
    strcpy(p1.name, "Kim Dongguk");
    strcpy(p1.pNumber, "01011111111");
    strcpy(p1.address, "Dongguk University");

    strcpy(p2.name, "Lee Younghee");
    strcpy(p2.pNumber, "01022222222");
    strcpy(p2.address, "Dongguk University");
    // ���ڿ� �ڷ���� ������ ����

    printf("ù��° ��� ���� :\n");
    printf("�̸� : %s\n", p1.name);
    printf("��ȭ��ȣ : %s\n", p1.pNumber);
    printf("�ּ� : %s\n", p1.address);
    printf("\n");

    printf("�ι�° ��� ���� :\n");
    printf("�̸� : %s\n", p2.name);
    printf("��ȭ��ȣ : %s\n", p2.pNumber);
    printf("�ּ� : %s\n", p2.address);
    
    return 0;
}

// �Ұ�
// ���ڰ� 0 ���� ������ ��� ��ǻ�Ͱ� 8������ �ν��ϴ� ������ �־����ϴ�.
// ���ڿ��� ������ �����ϴ� ����� �����߰�
// 8������ �Է��� �ް� ����� �� '0'�� ����� 8������ ����ϴ� ���� �޸𸮴� �� ȿ�������� ����Ѵٰ� �����մϴ�.
// �ٸ� ��¹��� �ܹ��� �����ϱ� ��ƴٰ� �����ؼ� ���ڿ��� �����ϴ� ����� �����߽��ϴ�.
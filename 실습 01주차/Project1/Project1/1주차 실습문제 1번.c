// 2024.03.07
// �ǽ����� 1��, ������������ �Ҽ� �ִ� ���α׷��� ������

#include <stdio.h>
#include <stdlib.h> //random�Լ��� ����ϱ� ���ؼ� ���Խ��� �ݴϴ�.
#include <time.h> //�Ź� �ٸ����� ������Ű�� ���ؼ� time�� ���� �Ź� �ٸ� �õ尪�� ���� �� �ݴϴ�.

int main()
{
    srand(time(NULL));
    int com, user; //��ǻ�Ϳ� ����ڰ� ���� ���� ������ ������ �����մϴ�.
    
    com = rand() % 3; //��ǻ�Ͱ� �������� 0, 1, 2 �� �ϳ��� ���� ������ �մϴ�.
    printf("���� = 0, ���� = 1, �� = 2\n�Է�: ");
    scanf_s("%d", &user); //������� �Է��� �޽��ϴ�.

    if (com == 0) { //������� �Է��� �޾��� �� ��ǻ�Ͱ� ���� ��쿡 ���� ����� ����մϴ�.
        printf("com: ����\n");
        if (user == 0) printf("�����ϴ�\n");
        else if (user == 1) printf("�̰���ϴ�\n");
        else if (user == 2) printf("�����ϴ�\n");
        else printf("�߸� �� �Է��Դϴ�."); //���� ���� ���ڸ� �Է������� ����� �� �� ���� ������ ���� �з� �մϴ�.
    }

    else if (com == 1) {
        printf("com: ����\n");
        if (user == 0) printf("�����ϴ�\n");
        else if (user == 1) printf("�����ϴ�\n");
        else if (user == 2) printf("�̰���ϴ�\n");
        else printf("�߸� �� �Է��Դϴ�.");
    }

    else {
        printf("com: ��\n");
        if (user == 0) printf("�̰���ϴ�\n");
        else if (user == 1) printf("�����ϴ�\n");
        else if (user == 2) printf("�����ϴ�\n");
        else printf("�߸� �� �Է��Դϴ�.");
    }

    return 0; // �����Լ��� ��ȯ���� int�̹Ƿ� ����ɶ� 0 �� ��ȯ�մϴ�.
}
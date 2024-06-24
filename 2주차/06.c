// 2024.03.14
// 실습 05
// 구조체 professor 를 정의하고, 교수 5 명을 선언하여 적당한 값을 입력하고 출력하시오. 개인정보, 담당과목(여러 개), 학과

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char pNumber[12];
    char address[20];
    char subject[30];
    char major[25];
} professor;

int main()
{
    professor p[5];

    strcpy(p[0].name, "교수님 1");
    strcpy(p[0].pNumber, "11111111");
    strcpy(p[0].address, "동국대학교");
    strcpy(p[0].subject, "컴퓨터구성");
    strcpy(p[0].major, "컴퓨터공학");

    strcpy(p[1].name, "교수님 2");
    strcpy(p[1].pNumber, "22222222");
    strcpy(p[1].address, "동국대학교");
    strcpy(p[1].subject, "자료구조");
    strcpy(p[1].major, "컴퓨터공학");

    strcpy(p[2].name, "교수님 3");
    strcpy(p[2].pNumber, "33333333");
    strcpy(p[2].address, "동국대학교");
    strcpy(p[2].subject, "객체지향프로그래밍");
    strcpy(p[2].major, "컴퓨터공학");

    strcpy(p[3].name, "교수님 4");
    strcpy(p[3].pNumber, "44444444");
    strcpy(p[3].address, "동국대학교");
    strcpy(p[3].subject, "기초프로그래밍");
    strcpy(p[3].major, "컴퓨터공학");

    strcpy(p[4].name, "교수님 5");
    strcpy(p[4].pNumber, "55555555");
    strcpy(p[4].address, "동국대학교");
    strcpy(p[4].subject, "공학경제");
    strcpy(p[4].major, "산업시스템공학");

    printf("교수정보출력 : \n");
    for(int i = 0; i < 5; i++) {
        printf("교수님 %d 정보: \n", i+1);
        printf("이름: %s\n", p[i].name);
        printf("전화번호: %s\n", p[i].pNumber);
        printf("주소: %s\n", p[i].address);
        printf("담당과목: %s\n", p[i].subject);
        printf("전공: %s\n\n", p[i].major);
    }

    return 0;
}
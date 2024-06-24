// 2024.03.14
// 실습 4번
// 구조체 person을 정의하고, 사람 2명을 선언하여 적당한 값을 입력하고 출력하시오. 이름 전화번호 주소

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char pNumber[12];
    char address[20];
} Person;

int main()
{
    Person p1, p2;
    strcpy(p1.name, "Kim Dongguk");
    strcpy(p1.pNumber, "01011111111");
    strcpy(p1.address, "Dongguk University");

    strcpy(p2.name, "Lee Younghee");
    strcpy(p2.pNumber, "01022222222");
    strcpy(p2.address, "Dongguk University");

    printf("첫번째 사람 정보 :\n");
    printf("이름 : %s\n", p1.name);
    printf("전화번호 : %s\n", p1.pNumber);
    printf("주소 : %s\n", p1.address);
    printf("\n");

    printf("두번째 사람 정보 :\n");
    printf("이름 : %s\n", p2.name);
    printf("전화번호 : %s\n", p2.pNumber);
    printf("주소 : %s\n", p2.address);
    return 0;
}

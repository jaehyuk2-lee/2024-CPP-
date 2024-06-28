// 2024.03.14
// 실습 4번
// 구조체 person을 정의하고, 사람 2명을 선언하여 적당한 값을 입력하고 출력하시오. 이름 전화번호 주소

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // 문자열 복사를 위한  strcpy함수를 사용하기 위해 사용

typedef struct
{
    char name[20];
    char pNumber[11]; // 전화번호 -> 010******** 0으로 시작하기 때문에 컴퓨터가 8진수로 인식 따라서 문자열로 저장
    char address[20];
} Person; // 이름, 전화번호, 주소의 값을 자료로 가지는 Person 선언

int main() {
    Person p1, p2;
    strcpy(p1.name, "Kim Dongguk");
    strcpy(p1.pNumber, "01011111111");
    strcpy(p1.address, "Dongguk University");

    strcpy(p2.name, "Lee Younghee");
    strcpy(p2.pNumber, "01022222222");
    strcpy(p2.address, "Dongguk University");
    // 문자열 자료들을 값으로 복사

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

// 소감
// 숫자가 0 으로 시작할 경우 컴퓨터가 8진수로 인식하는 문제가 있었습니다.
// 문자열로 정보를 저장하는 방법을 선택했고
// 8진수로 입력을 받고 출력할 때 '0'을 출력후 8진수로 출력하는 것이 메모리는 더 효율적으로 사용한다고 생각합니다.
// 다만 출력문을 단번에 이해하기 어렵다고 생각해서 문자열로 선언하는 방식을 선택했습니다.
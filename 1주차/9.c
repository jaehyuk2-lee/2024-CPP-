// 204.03.08
// 실습문제 9번, 다음과 같이 int 형 변수 i에 0x324F3A24을 정의하여 char * 변수 pc를 선언하여
// pc 변수를 이용하여 i 의 저장 값을 16 진수 324F3A24 로 출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h> // malloc 함수 사용을 위해 포함합니다.

int main() {
    int n = 0x324F3A24; // 0x -> 16진수를 위한 표현입니다 따라서 324F3A24만 문자열로 저장하면 됩니다
    char *pc;
    pc = (char*)malloc(sizeof(char)); // 문자열로 바꾼 값을 저장하기 위한 공간을 할당합니다.

    sprintf(pc, "%x", n); // pc에 %x를 통해 format된 문자열이 저장됩니다. 16진수가 할당됩니다.
    printf("%s\n", pc); // 문자열 pc를 출력합니다.

    return 0;
}
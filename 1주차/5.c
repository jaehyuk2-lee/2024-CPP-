// 2024.03.07
// 실습문제 5번, 정수를 바꾸는 프로그램인 void swap(int*, int*) 작성, 결과를 알아보는 프로그램 작성

#include <stdio.h>

void swap (int *, int *);

int main() {
    int num1, num2;
    printf("num1 : ");
    scanf("%d", &num1);
    printf("num2 : ");
    scanf("%d", &num2);

    printf("바뀌기 전 num1 : %d, num2 : %d\n", num1, num2);
    swap(&num1, &num2);
    printf("바뀐 후   num1 ; %d, num2 : %d\n", num1, num2);
    
    return 0;
}

void swap(int *a, int *b) {
    int *tmp;
    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

// 만약 swap함수에 두 숫자를 int로 받았다면, main함수에 있는 변수들과 완전히 다른 새로운 변수입니다.
// 또 한 어차피 swap함수가 끝날 때 없어지는 변수이기 때문에, return값이 없는 swap함수에서는 의미가 없는 변수입니다.
// 따라서 int * 즉 주소 값을 인자로 넘겨받아 그곳을 가르키는 포인터들을 만들고 가르키는 것을 바꿔 줬습니다.
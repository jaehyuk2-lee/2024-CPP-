// 2024.03.08
// 실습문제 8번, 자료유형 double형 1차원 배열을 다음과 같이 초기화하고, 첫 번째 인자인 배열 source을
// 두 번째 인자인 배열 target에 복사하는 함수를 만들어 결과를 알아보는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h> // 동적할당을 위해서 사용할 malloc함수를 위해 포함시킵니다.

void copyarray(double*, double*, int);


int main() {
    double ary[5] = { 3.12, 5.14, 7.25, 7.48, 5.91 };
    double* ary_copied;
    ary_copied = (double*)malloc(sizeof(double) * 5); // 복사한 원소를 저장할 메모리를 새로 할당합니다.

    printf("주어진 배열 : ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", ary[i]);
    }
    printf("\n");

    copyarray(ary, ary_copied, 5);

    free(ary_copied); // 동적할당한 메모리를 해제해줍니다.
    return 0;
}

void copyarray(double* source, double* target, int size) {
    for (int i = 0; i < size; i++) {
        target[i] = source[i]; // 새로 할당한 주소에 원래 함수의 원소를 대입합니다.
    }

    printf("복사 한 배열 : ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", target[i]);
    }
    printf("\n");
}

// 처음에는 copyarray()가 동적할당 한 주소를 리턴해서, main에서 복사한 내용을 출력하려 했습니다.
// 하지만 그러면 굳이 target 배열을 인자로 받을 이유가 없다고 생각해서,
// 함수 내에서 원소를 복사하고 출력하고 동적할당을 해제하는 void함수로 작성했습니다.
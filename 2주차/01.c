// 2024.03.14
// 심화프로그래밍02이재혁
// 실습 1번, double형 배열에서 최댓값의 주소를 반환하는 함수를 만들어라

#include <stdio.h>

double* get_max(double *, int);

int main() {
    double arr[10] = {1.2, 2.3, 3.4, 4.1, 2.4, 8.2, 3.593, 0.123, 5.412, 7.26};
    printf("최댓값은%.3f이고, 해당요소의 주소는%p입니다.\n", *(get_max(arr,10)), get_max(arr,10));

    return 0;
}

double* get_max(double* A, int size) {
    int max = A[0];
    int max_index = 0;
    for(int i = 1; i < size; i++) {
        if(A[i] > max) {
            max = A[i];
            max_index = i;
        }
    }
    return &A[max_index];
}
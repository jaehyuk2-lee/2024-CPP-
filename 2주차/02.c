// 2024.03.14
// 실습 02번
// 학점 4.3점이 만점이다. 배열 grades[]에 학생 10명의 학점이 저장되어 있다. 이것을 100점 만점으로 변환하여 scores[]에 저장
// 학점 * 23.25581

#include <stdio.h>

void compute(double*, double*);

int main() {
    double grades[10] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.8, 3.0, 3.7, 4.2, 4.3};
    double scores[10];

    compute(grades, scores);

    for(int i = 0; i < 10; i++) {
        printf("학생 %d: %.2f\n", i+1, scores[i]);
    }

    return 0;
}

void compute(double* arr1, double* arr2) {
    for(int i = 0; i < 10; i++) {
        if(arr1[i] == 4.3) {
            arr2[i] = 100.0;
        }
        else {
            arr2[i] = arr1[i]*23.25581;
        }
    }
}
// 2024.03.07
// 실습문제 6번, 두 이차원 배열의 합과 차를 구하는 함수를 만들고 주어진 배열의 계산결과를 알아보시오

#include <stdio.h>

void Sum(float [][3], float [][3]); // 2차원 배열 -> 길이가 3인 배열을 몇개 갖고 있는가 입니다.
void Distinct(float [][3], float [][3]); // 계산 수행 후 출력까지만 기능이기 때문에 return이 없어도 된다고 생각했습니다.

int main() {
    float arr1[2][3] = {{4.2, 4.3, 3.8}, {3.7, 1.5, 0.7}}; // 실수 형을 저장하는 배열 이므로 float으로 선언했습니다.
    float arr2[2][3] = {{5.2, 2.1, 1.8}, {3.2, 1.4, 2.9}}; // 길이가 3인 배열을 2개 갖고있는 형태입니다
    float *sum[3];
    float *distinct[3];
    
    Sum(arr1, arr2);
    Distinct(arr1, arr2);

    return 0;
}

void Sum(float a1[][3], float a2[][3]) { // a1, a2라는 2차원 배열이 다시 선언되는 과정이기 때문에, 형태를 지정해줍니다.
    float sum[2][3]; // 계산된 값을 저장할 배열입니다.

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = a1[i][j] + a2[i][j]; // 같은 위치에 있는 값 끼리 더한 후 저장합니다.
        }
    }

    printf("두 배열의 합\n");
    for (int i = 0; i < 2; i++) { // 배열의 내용을 출력해줍니다.
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", sum[i][j]);
        }
        printf("\n");
    }
}

void Distinct(float a1[][3], float a2[][3]) {
    float dis[2][3]; // 계산된 값을 저장할 배열입니다.

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            dis[i][j] = a1[i][j] - a2[i][j]; // 같은 위치에 있는 값 끼리 뺀 후 저장합니다.
        }
    }

    printf("두 배열의 차\n");
    for (int i = 0; i < 2; i++) { // 배열의 내용을 출력해줍니다.
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", dis[i][j]);
        }
        printf("\n");
    }

}
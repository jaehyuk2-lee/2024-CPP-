// 2024.03.07
// 실습문제 4번, 주어진 배열에서 모든 원소의 값을 n만큼 증가시키는 함수를 작성하시오

#include <stdio.h>

void increase(int *, int, int);
// 주어진 배열에서 크기를 키워주면 되기 때문에, void에 주솟값을 넘겨 받는 함수로 작성합니다.
// 포인터로 넘겨 받기 때문에 배열의 크기를 알 수 없기 떄문에, 배열의 크기도 인자로 넘겨줍니다.

int main() {
    int data[] = {3, 21, 35, 57, 24, 82, 8};
    int len = sizeof(data)/4; //int 배열은 4바이트를 원소로 갖기 때문에 원소의 크기로 나눠서 구했습니다.
    int n; // 증가시킬 값을 저장 시킬 변수

    printf("원래 배열 : ");
    for (int i = 0; i < sizeof(data)/4; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("증가시킬 값 : ");
    scanf("%d", &n);

    increase(data, len, n);

    printf("증가된 배열 : ");
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

void increase(int *arr, int len, int n) {
    for (int i = 0; i < len; i++) {
        arr[i] += n;
    }
}

// call by value로 주어진 배열의 값 들을 받아온 뒤 n씩 더해 새로운 배열을 만드는 방법도 있습니다.
// 그 경우에는 배열의 크기만큼 새로운 메모리를 차지하기 때문에 비효율적이라고 생각했습니다.
// 따라서 번거러워도 주소와 배열의 크기를 함께 넘겨줘 주어진 배열을 바꾸도록 작성했습니다.
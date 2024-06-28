// 2024.03.07
// 실습문제 2번, 함수 자신이 호출된 횟수를 반환하는 함수를 만들고 함수를 작성해 이를 검사하는 프로그램을 작성하시요

#include <stdio.h>

int function(); // 자신이 호출 된 횟수를 반환하는 함수입니다.

int main() {
    int call; // 호출 된 횟수가 저장 될 변수입니다.

    for (int i = 0; i < 3; i++) { // 처음 3번 호출했습니다.
        call = function();
    }
    printf("현재까지 %d번 호출 됐습니다\n", call); // 호출된 횟수를 출력합니다.

    for (int i = 0; i < 5; i++) { // 5번 추가 호출합니다.
        call = function();
    }
    printf("현재까지 %d번 호출 됐습니다\n", call); // 3번 이후 5번 더 출력 됐기 때문에 8번이 출력되는지 확인합니다.

    return 0;
}

int function() {
    static int repeat = 0; // 이 함수 내부에서만 변화시킬 수 있고, 프로그램이 종료 될 때 사라지는 정적변수 생성합니다.
    repeat++;
    return repeat; //함수가 반복한 횟수를 반환합니다.
}
// 전역 변수로 함수가 반복 될 때 마다 변수를 하나씩 증가시키는 방법을 사용할 수 있었습니다.
// 하지만 그 방법은 main함수에서도 반복횟수를 수정할 수 있고, 함수가 반환하는 방법이 아니기 때문에
// 프로그램이 종료되는 시점에 사라지는 정적변수를 함수 안에 배치해서 보다 정확하게, 호출될 때만 변수가 증가하게 작성했습니다.
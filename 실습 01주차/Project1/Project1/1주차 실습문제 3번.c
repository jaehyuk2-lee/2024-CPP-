// 2024.03.07
// 실습문제 3번, 1에서 100까지 난수하나 발생, 사용자가 맞추는 프로그램
// 조건 : setNumber():난수 설정, number를 맞출때 까지 반복, 힌트 자세히, min, max사용 정적 외부변수, 시도횟수 trycount로 매번출력
// setNumber(),printHead(), printHigher( ), printLower( ), printAnswer()로 구성

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number;
static int min = 1;
static int max = 100;
int trycount = 0; // 모든 함수에서 시도횟수를 추가하거나, 값을 참조해야 하기 때문에 전역변수로 지정했습니다.
int is_end = 0; // 프로그램을 종료할지 결정할 변수 입니다.

void setNumber(); // 함수들은 최대, 최소 출력이나, 변수 설정등의 역할이므로 반환값이 없기 때문에 void형으로 지정했습니다.
void printHead();
void printHigher(int);
void printLower(int);
void printAnswer();

int main() {
    int input; // 사용자가 입력 할 변수입니다
    setNumber();
    while (is_end == 0) { // 전역에 선언된 is_end가 초기값이 0일때는 계속 반복합니다.
        printHead();
        scanf_s("%d", &input);
        if (input > max || input < min) {
            printf("범위 밖의 수 입니다.\n"); // 입력 받은 수가 최대, 최소값의 범위 밖에 있을 경우 아래를 확인할 필요가 없습니다.
            trycount++;
            continue;
        }
        trycount++; // 입력마다 횟수를 추가합니다

        if (number > input) {
            printLower(input);
        }
        else if (number < input) {
            printHigher(input);
        }
        else printAnswer();
    }

    return 0;
}

void setNumber() {
    srand(time(NULL));
    number = rand() % 100 + 1; // 1 ~ 100 범위의 정수를 생성합니다.
    printf("난수설정완료\n");
}

void printHead() { // 수시로 변화하는 숫자의 범위를 반복의 시작 부분마다 출력해줍니다.
    printf("숫자의 범위는 %d~%d 입니다.\n", min, max);
    printf("숫자 입력 : ");
}

void printLower(int m) {
    printf("입력받은 숫자가 작습니다.\n");
    min = m + 1; // m은 이미 아닌 것을 알고 있으므로 그 다음 값을 최소 범위로 잡아줍니다.
}

void printHigher(int M) {
    printf("입력받은 숫자가 큽니다.\n");
    max = M - 1; // M은 이미 아닌 것을 알고 있으므로 그 이전 값을 최대 범위로 잡아줍니다.
}

void printAnswer() { // 정답을 맞췄기 때문에 시도 횟수를 출력하고 is_end의 값을 바꿔줍니다.
    printf("정답입니다. 시도횟수 : %d\n", trycount);
    is_end = 1;
}
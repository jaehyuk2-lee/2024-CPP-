// 2024.03.07
// 실습문제 1번, 가위바위보를 할수 있는 프로그램을 만들어라

#include <stdio.h>
#include <stdlib.h> //random함수를 사용하기 위해서 포함시켜 줍니다.
#include <time.h> //매번 다른값을 생성시키기 위해서 time을 통해 매번 다른 시드값을 전달 해 줍니다.

int main()
{
    srand(time(NULL));
    int com, user; //컴퓨터와 사용자가 가질 값을 저장할 변수를 선언합니다.
    
    com = rand() % 3; //컴퓨터가 무작위로 0, 1, 2 중 하나의 값을 가지게 합니다.
    printf("가위 = 0, 바위 = 1, 보 = 2\n입력: ");
    scanf_s("%d", &user); //사용자의 입력을 받습니다.

    if (com == 0) { //사용자의 입력을 받았을 때 컴퓨터가 가진 경우에 따라 결과를 출력합니다.
        printf("com: 가위\n");
        if (user == 0) printf("비겼습니다\n");
        else if (user == 1) printf("이겼습니다\n");
        else if (user == 2) printf("졌습니다\n");
        else printf("잘못 된 입력입니다."); //범위 밖의 숫자를 입력했을시 결과를 알 수 없기 떄문에 따로 분류 합니다.
    }

    else if (com == 1) {
        printf("com: 바위\n");
        if (user == 0) printf("졌습니다\n");
        else if (user == 1) printf("비겼습니다\n");
        else if (user == 2) printf("이겼습니다\n");
        else printf("잘못 된 입력입니다.");
    }

    else {
        printf("com: 보\n");
        if (user == 0) printf("이겼습니다\n");
        else if (user == 1) printf("졌습니다\n");
        else if (user == 2) printf("비겼습니다\n");
        else printf("잘못 된 입력입니다.");
    }

    return 0; // 메인함수의 반환형이 int이므로 종료될때 0 을 반환합니다.
}
// 2024.03.14
// 실습 5번
// 구조체 student를 정의하고, 학생 10명을 선언하여 적당한 값을 입력하고 출력하시오. 이름, 학번, 평균평점, 학과, 진로

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // 문자열 복사를 위한  strcpy함수를 사용하기 위해 사용

typedef struct
{
    char name[20];
    char number[11];
    float average;
    char major[20];
    char career[20];
} student;// 이름, 학번, 평균평점, 학과, 진로의 자료를 갖는 student 선언

int main()
{
    student arr[10]; // student 자료 10개를 저장할 배열 생성

    strcpy(arr[0].name, "A");
    strcpy(arr[0].number, "2021000001");
    arr[0].average = 4.3;
    strcpy(arr[0].major, "computer science");
    strcpy(arr[0].career, "AI");

    strcpy(arr[1].name, "B");
    strcpy(arr[1].number, "2021000002");
    arr[1].average = 4.0;
    strcpy(arr[1].major, "computer science");
    strcpy(arr[1].career, "engineer");

    strcpy(arr[2].name, "C");
    strcpy(arr[2].number, "2021000003");
    arr[2].average = 3.7;
    strcpy(arr[2].major, "multimedia");
    strcpy(arr[2].career, "engineer");

    strcpy(arr[3].name, "D");
    strcpy(arr[3].number, "2021000004");
    arr[3].average = 3.3;
    strcpy(arr[3].major, "computer science");
    strcpy(arr[3].career, "AI");

    strcpy(arr[4].name, "E");
    strcpy(arr[4].number, "2021000005");
    arr[4].average = 3.0;
    strcpy(arr[4].major, "computer science");
    strcpy(arr[4].career, "engineer");

    strcpy(arr[5].name, "F");
    strcpy(arr[5].number, "2021000006");
    arr[5].average = 2.7;
    strcpy(arr[5].major, "computer science");
    strcpy(arr[5].career, "backend");

    strcpy(arr[6].name, "G");
    strcpy(arr[6].number, "2021000007");
    arr[6].average = 2.3;
    strcpy(arr[6].major, "computer science");
    strcpy(arr[6].career, "AI");

    strcpy(arr[7].name, "H");
    strcpy(arr[7].number, "2021000008");
    arr[7].average = 2.0;
    strcpy(arr[7].major, "computer science");
    strcpy(arr[7].career, "engineer");

    strcpy(arr[8].name, "I");
    strcpy(arr[8].number, "2021000009");
    arr[8].average = 1.7;
    strcpy(arr[8].major, "computer science");
    strcpy(arr[8].career, "backend");

    strcpy(arr[9].name, "J");
    strcpy(arr[9].number, "2021000010");
    arr[9].average = 1.3;
    strcpy(arr[9].major, "computer science");
    strcpy(arr[9].career, "AI");
    

    for (int i = 0; i < 10; i++) {
        printf("학생 %d 정보 : \n", i + 1);
        printf("이름 : %s\n", arr[i].name);
        printf("학번 : %s\n", arr[i].number);
        printf("평균 평점 : %.1f\n", arr[i].average);
        printf("학과 : %s\n", arr[i].major);
        printf("진로 : %s\n", arr[i].career);
        printf("\n");
    }
    // 배열 내의 원소들이 모두 같은 자료형을 가지고 있으므로 반복문의 i를 사용해 반복 출력

    return 0;
}
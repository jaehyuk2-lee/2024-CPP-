// 2024.03.14
// 실습07
// 구조체 student를 정의하고, 학생 10명을 선언하여 적당한 값을 입력하고 출력, 개인정보, 학번, 평균평점, 학과, 진로, 지도교수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char pNumber[12];
    char address[20];
} professor; // 교수 구조체 선언

typedef struct
{
    char name[20];
    char number[11];
    float average;
    char major[20];
    char career[20];
    professor* p; // 담당교수의 자료가 저장된 주소값을 포함해 담당교수 정보에 접근가능
} person; // 사람(학생)의 구조체 선언

int main() {
    professor p[5]; //교수 정보 5개를 저장할 배열 선언

    strcpy(p[0].name, "교수님 1");
    strcpy(p[0].pNumber, "11111111");
    strcpy(p[0].address, "동국대학교");

    strcpy(p[1].name, "교수님 2");
    strcpy(p[1].pNumber, "22222222");
    strcpy(p[1].address, "동국대학교");

    strcpy(p[2].name, "교수님 3");
    strcpy(p[2].pNumber, "33333333");
    strcpy(p[2].address, "동국대학교");

    strcpy(p[3].name, "교수님 4");
    strcpy(p[3].pNumber, "44444444");
    strcpy(p[3].address, "동국대학교");

    strcpy(p[4].name, "교수님 5");
    strcpy(p[4].pNumber, "55555555");
    strcpy(p[4].address, "동국대학교");
    // 교수님의 정보 입력

    person student[10]; // 학생 정보 10개 저장할 배열 선언, 교수님 1~5가 2명씩 학생을 담당한다.
    strcpy(student[0].name, "stu. A");
    strcpy(student[0].number, "2021000001");
    student[0].average = 4.3;
    strcpy(student[0].major, "computer science");
    strcpy(student[0].career, "AI");
    student[0].p = &p[0]; // 담당교수의 정보가 저장된 주소를 입력

    strcpy(student[1].name, "stu. B");
    strcpy(student[1].number, "2021000002");
    student[1].average = 4.0;
    strcpy(student[1].major, "computer science");
    strcpy(student[1].career, "engineer");
    student[1].p = &p[0];

    strcpy(student[2].name, "stu. C");
    strcpy(student[2].number, "2021000003");
    student[2].average = 3.7;
    strcpy(student[2].major, "multimedia");
    strcpy(student[2].career, "engineer");
    student[2].p = &p[1];

    strcpy(student[3].name, "stu. D");
    strcpy(student[3].number, "2021000004");
    student[3].average = 3.3;
    strcpy(student[3].major, "computer science");
    strcpy(student[3].career, "AI");
    student[3].p = &p[1];

    strcpy(student[4].name, "stu. E");
    strcpy(student[4].number, "2021000005");
    student[4].average = 3.0;
    strcpy(student[4].major, "computer science");
    strcpy(student[4].career, "engineer");
    student[4].p = &p[2];

    strcpy(student[5].name, "stu. F");
    strcpy(student[5].number, "2021000006");
    student[5].average = 2.7;
    strcpy(student[5].major, "computer science");
    strcpy(student[5].career, "studentkend");
    student[5].p = &p[2];

    strcpy(student[6].name, "stu. G");
    strcpy(student[6].number, "2021000007");
    student[6].average = 2.3;
    strcpy(student[6].major, "computer science");
    strcpy(student[6].career, "AI");
    student[6].p = &p[3];

    strcpy(student[7].name, "stu. H");
    strcpy(student[7].number, "2021000008");
    student[7].average = 2.0;
    strcpy(student[7].major, "computer science");
    strcpy(student[7].career, "engineer");
    student[7].p = &p[3];

    strcpy(student[8].name, "stu. I");
    strcpy(student[8].number, "2021000009");
    student[8].average = 1.7;
    strcpy(student[8].major, "computer science");
    strcpy(student[8].career, "backend");
    student[8].p = &p[4];

    strcpy(student[9].name, "stu. J");
    strcpy(student[9].number, "2021000010");
    student[9].average = 1.3;
    strcpy(student[9].major, "computer science");
    strcpy(student[9].career, "AI");
    student[9].p = &p[4];

    printf("학생정보출력:\n");
    for (int i = 0; i < 10; i++) {
        printf("학생 %d 정보: \n", i + 1);
        printf("이름: %s\n", student[i].name);
        printf("학번: %s\n", student[i].number);
        printf("평균 평점: %.1f\n", student[i].average);
        printf("학과: %s\n", student[i].major);
        printf("진로: %s\n", student[i].career);
        printf("지도 교수 이름: %s\n", student[i].p->name);
        printf("지도 교수 전화번호: %s\n", student[i].p->pNumber);
        printf("지도 교수 주소: %s\n\n", student[i].p->address);
    } // 학생정보를 출력, 학생정보 출력시 담당교수의 정보는 포인터 이므로 -> 참조 연산자를 사용해 자료에 접근한다

    return 0;
}
// 소감
// 구조체 내부에 다른 구조체의 관한 정보가 있을 시 새로운 멤버 변수를 만드는 것 보다
// 포인터를 통해 다른 구조체 객체의 주소를 받아 자료에 접근하는게 메모리 사용에 효율적이라는 생각이 들었습니다.
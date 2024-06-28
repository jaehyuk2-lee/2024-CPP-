// 2024.03.14
// 실습 03번
// 구조체를 이용해 복소수의 덧셈 뺄셈 곱셈을 계산하는 프로그램 작성

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // 제곱근 계산을 사용하기 위해 선언

typedef struct {
    int real;
    int imag;
}Complex; // 실수부 허수부의 자료를 가지는 Complex 구조체 선언

void Sum(Complex, Complex);
void Dis(Complex, Complex);
void Mul(Complex, Complex);
void Abs(Complex* , Complex* );
// 각각의 계산을 해 출력해주는 함수 선언

int main() {
    Complex c1, c2;
    printf("c1, 정수부 허수부 입력: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("c2, 정수부 허수부 입력: ");
    scanf("%d %d", &c2.real, &c2.imag);

    // c1, c2가 생성될 때 실수부와 허수부의 정수 자료가 저장될 메모리가 생성, 그 주소에 값을 입력받아 대입

    Sum(c1, c2);
    Dis(c1, c2);
    Mul(c1, c2);
    Abs(&c1, &c2);
}

void Sum(Complex c1, Complex c2) {
    Complex s;
    s.real = c1.real + c2.real;
    s.imag = c1.imag + c2.imag;
    printf("덧셈: %d + %di\n", s.real, s.imag);
}

void Dis(Complex c1, Complex c2) {
    Complex d;
    d.real = c1.real - c2.real;
    d.imag = c1.imag - c2.imag;
    printf("뺄셈: %d + %di\n", d.real, d.imag);
}

void Mul(Complex c1, Complex c2) {
    Complex m;
    m.real = c1.real * c2.real - c1.imag * c2.imag;
    m.imag = c1.imag * c2.real + c2.imag * c1.real;
    printf("곱셈: %d + %di\n", m.real, m.imag);
    // 실수부는 실수부의 곱과 허수부의 곱의 차
    // 허수부는 실수부와 허수부의 곱 끼리의 합
}
// 덧셈 뺄셈 곱셈함수는 구조체들의 정보를 바탕으로 새로운 객체를 복사하여 생성후 그 값을 사용

void Abs(Complex* c1, Complex* c2) {
    double a1, a2;
    a1 = sqrt(c1->real * c1->real + c1->imag * c1->imag);
    a2 = sqrt(c2->real * c2->real + c2->imag * c2->imag);
    printf("절대값: %.2f\n        %.2f\n", a1, a2);
}
// 절댓값 함수는 구조체의 주소를 받아와 직접 값을 참조하여 절댓값을 계산

// 소감
// 함수를 작성하면서 구조체를 call by value로 자료를 받을 경우 구조체 내부에 여러 자료형이 있어,
// 일반 자료형을 받는 함수보다 더 큰 메모리를 사용하여 복사본을 생성한다고 생각했습니다.
// 따라서 절댓값함수는 call by reference로 구조체의 주소값을 넘겨 받아 직접값을 참조했습니다.
// 다만 원본 구조체의 값이 변경될 수도 있기 때문에, call by value방법도 필요하다고 생각했습니다. 
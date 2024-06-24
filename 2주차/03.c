// 2024.03.14
// 실습 03번
// 구조체를 이용해 복소수의 덧셈 뺄셈 곱셈을 계산하는 프로그램 작성

#include <stdio.h>
#include <math.h>

typedef int element;

typedef struct {
    int real;
    int imag;
} Complex;

void Sum(Complex, Complex);
void Dis(Complex, Complex);
void Mul(Complex, Complex);
void Abs(Complex, Complex);

int main() {
    Complex c1, c2;
    printf("c1, 정수부 허수부 입력: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("c2, 정수부 허수부 입력: ");
    scanf("%d %d", &c2.real, &c2.imag);

    Sum(c1, c2);
    Dis(c1, c2);
    Mul(c1, c2);
    Abs(c1, c2);
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
    m.real = c1.real*c2.real - c1.imag*c2.imag;
    m.imag = c1.imag*c2.real + c2.imag*c1.real;
    printf("곱셈: %d + %di\n", m.real, m.imag); 
}

void Abs(Complex c1, Complex c2) {
    double a1, a2;
    a1 = sqrt(c1.real*c1.real + c1.imag*c1.imag);
    a2 = sqrt(c2.real*c2.real + c2.imag*c2.imag);
    printf("절대값: %.2f\n        %.2f\n", a1, a2);
}
// 2024.03.14
// �ǽ� 03��
// ����ü�� �̿��� ���Ҽ��� ���� ���� ������ ����ϴ� ���α׷� �ۼ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // ������ ����� ����ϱ� ���� ����

typedef struct {
    int real;
    int imag;
}Complex; // �Ǽ��� ������� �ڷḦ ������ Complex ����ü ����

void Sum(Complex, Complex);
void Dis(Complex, Complex);
void Mul(Complex, Complex);
void Abs(Complex* , Complex* );
// ������ ����� �� ������ִ� �Լ� ����

int main() {
    Complex c1, c2;
    printf("c1, ������ ����� �Է�: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("c2, ������ ����� �Է�: ");
    scanf("%d %d", &c2.real, &c2.imag);

    // c1, c2�� ������ �� �Ǽ��ο� ������� ���� �ڷᰡ ����� �޸𸮰� ����, �� �ּҿ� ���� �Է¹޾� ����

    Sum(c1, c2);
    Dis(c1, c2);
    Mul(c1, c2);
    Abs(&c1, &c2);
}

void Sum(Complex c1, Complex c2) {
    Complex s;
    s.real = c1.real + c2.real;
    s.imag = c1.imag + c2.imag;
    printf("����: %d + %di\n", s.real, s.imag);
}

void Dis(Complex c1, Complex c2) {
    Complex d;
    d.real = c1.real - c2.real;
    d.imag = c1.imag - c2.imag;
    printf("����: %d + %di\n", d.real, d.imag);
}

void Mul(Complex c1, Complex c2) {
    Complex m;
    m.real = c1.real * c2.real - c1.imag * c2.imag;
    m.imag = c1.imag * c2.real + c2.imag * c1.real;
    printf("����: %d + %di\n", m.real, m.imag);
    // �Ǽ��δ� �Ǽ����� ���� ������� ���� ��
    // ����δ� �Ǽ��ο� ������� �� ������ ��
}
// ���� ���� �����Լ��� ����ü���� ������ �������� ���ο� ��ü�� �����Ͽ� ������ �� ���� ���

void Abs(Complex* c1, Complex* c2) {
    double a1, a2;
    a1 = sqrt(c1->real * c1->real + c1->imag * c1->imag);
    a2 = sqrt(c2->real * c2->real + c2->imag * c2->imag);
    printf("���밪: %.2f\n        %.2f\n", a1, a2);
}
// ���� �Լ��� ����ü�� �ּҸ� �޾ƿ� ���� ���� �����Ͽ� ������ ���

// �Ұ�
// �Լ��� �ۼ��ϸ鼭 ����ü�� call by value�� �ڷḦ ���� ��� ����ü ���ο� ���� �ڷ����� �־�,
// �Ϲ� �ڷ����� �޴� �Լ����� �� ū �޸𸮸� ����Ͽ� ���纻�� �����Ѵٰ� �����߽��ϴ�.
// ���� �����Լ��� call by reference�� ����ü�� �ּҰ��� �Ѱ� �޾� �������� �����߽��ϴ�.
// �ٸ� ���� ����ü�� ���� ����� ���� �ֱ� ������, call by value����� �ʿ��ϴٰ� �����߽��ϴ�. 
#include <iostream>
using namespace std;

class Circle {
    int radius;

public:
    Circle(int radius = 0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " �� ��" << endl; }

    Circle operator++() {
        radius++;
        return *this;
    }
    // ���� �������� ǥ��, ���� ���� ������ �� �� ���� �����Ѵ�.
    // return Ÿ���� Circle�� ������ ++a ���� �ٸ� ������ ������ �� �ֱ� ������ �ڽ��� ���� �����Ѵ�.

    Circle operator++(int x) {
        Circle tmp(radius);
        radius++;
        return tmp;
    }
    // ���� �������� ǥ��, ���� ������Ű�� ������ ������Ű�� ���� ���� �����Ѵ�.
    // �������� ������Ű�� ���� ������ ��ü�� �����Ѵ�. �ڽ��� �������� ���� ������Ű��, ������ ��ü�� �����Ѵ�.
};

int main() {
    Circle a(5), b(4);
    ++a;     // �������� 1 ���� ��Ų��.
    b = a++; // �������� 1 ���� ��Ų��.
    a.show();
    b.show();
}
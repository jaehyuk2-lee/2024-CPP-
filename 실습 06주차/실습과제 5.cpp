#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r) { radius = r; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    void show() { cout << "�������� " << radius << "�� ��" << endl; }
};

void increaseBy1(Circle a, Circle b) {
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
}
// �� �Լ��� main()���� �Ѱܹ��� Circle��ü�� a�� b��� ���ο� ��ü ġȯ�Ѵ�.
// a�� b ��ü�� �Լ��� ����ɶ� ������� ���� x��ü�� ���� ��ȭ��Ų ���� �ƴϴ�.

void increaseBy2(Circle& a, Circle& b) {
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
} // x��ü�� ������ ���� �Լ����ο��� ����Ǵ� ���� ���ϱ� ������ x�� ���޹޴� �Ű������� ���۷��� ������ ����� ���� ���� �����Ѵ�.
  // y��ü�� �����ϴ� �������� ũ���� �����̱� ������ ���۷����� ������� �ʾƵ� �ȴ�. ���۷��� ������ ����ϸ� �޸𸮸� ������ �� �ִ�.

int main() {
    Circle x(10), y(5);
    increaseBy1(x, y);
    x.show();

    increaseBy2(x, y);
    x.show();
}
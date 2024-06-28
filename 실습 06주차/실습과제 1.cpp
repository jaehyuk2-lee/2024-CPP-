#include <iostream>
using namespace std;

class Circle {
    int radius; // ��ü�� ��ȯ�ϱ� ���� �����ϴ� ����
public:
    Circle() {
        radius = 1;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    int getRadius() {
        return this->radius;
    }
};

void swap(Circle&, Circle&); // Circle��ü�� ���۷����� �Ű������� ������ ���� �ǹ�

int main() {
    Circle c1, c2;
    c1.setRadius(10);
    c2.setRadius(20);
    cout << "c1.radius : " << c1.getRadius() << " c2.radius : " << c2.getRadius() << "\n";
    // �������� ���� ����Ǳ� ���� ���� ���

    swap(c1, c2); // �������� ���� ����
    cout << "c1.radius : " << c1.getRadius() << " c2.radius : " << c2.getRadius() << "\n";
    // ����� �������� ���
}

void swap(Circle& a, Circle& b) {
    // �Ű������� ���� ��ü reference�� ���ο� ��ü�� ���� ���縦 �ϴ� ���� �ƴ϶�
    // main()���� ���޵� ��ü �� ��ü�� �ȴ�. ���� a�� �������� �����ϸ� ���� ���޵� c1�� ���������� ���Ѵ�.
    int tmp;
    tmp = a.getRadius();
    a.setRadius(b.getRadius());
    b.setRadius(tmp);
}
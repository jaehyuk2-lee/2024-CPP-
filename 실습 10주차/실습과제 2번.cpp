#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }

protected:
    void move(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // ��ӹ��� Ŭ���������� ���ٰ���
};

class ColorPoint : public Point {
    string color;
public:
    ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) {
        this->color = color;
    }
    // ��ǥ�� ������ ���� �ʱ�ȭ �� �� �ֱ� ������ �ڽ� Ŭ�������� �θ�Ŭ������ �Ű����� �����ڸ� ȣ��
    // ����Ǵ� ������ �θ�Ŭ������ ���� ��������� ȣ���� �ڽ�Ŭ������ ���� ȣ��Ǳ� ������ 
    // �θ�Ŭ������ �Ű����� �����ڸ� ȣ�Ⱑ��

    // �⺻�����ڷ� ������ ��ǥ�� BLACK���� (0,0) ��ǥ, ���� ����Ʈ �Ű����� ����

    void setPoint(int x, int y) {
        move(x, y);
    }
    // x, y�� ���޹޾��� �� �θ�Ŭ������ ����Լ��� ���� ��ǥ���� �缳��
    // move()�Լ��� protected ���������ڷ� �ڽ�Ŭ���������� ������ �� �ִ�.
    // ���� �ܺο��� ��ü.move()�� ����� �� ���� ColorPoint��ü.setPoint()�� move�� ȣ���Ѵ�.

    void setColor(string color) {
        this->color = color;
    } // ���޹��� ������ ������� �缳��

    void show() {
        cout << this->color << "������ " << "(" << getX() << ", " << getY() << ")�� ��ġ�� ���Դϴ�.\n";
    }
    // x, y�� ���� private�̱� ������ �ڽ�Ŭ���������� ���� �Ұ���
    // ���� ����Լ��� ���ؼ� ���� ����
};

int main() {
    ColorPoint zeroPoint; // BLACK ���� (0, 0) ��ġ�� ��
    zeroPoint.show(); // zeroPoint�� ����Ѵ�.

    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show(); // cp�� ����Ѵ�.
}
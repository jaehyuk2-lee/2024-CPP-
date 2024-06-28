// 2024.03.28
#include <iostream>
using namespace std;

class Tower {
public:
    Tower() { // �Ű������� ���� ���� �⺻ 1�� ����
        height = 1;
    }
    Tower(int h) { // int�� �Ű������� ���� �� �� ������ ����
        height = h;
    }
    int getHeight(); // height ������ class�ܺο��� ������ �� ���� ������, method�� ���� return;
private:
    int height;
}; // ���� ���� ������ Tower class

int Tower::getHeight() {
    return height;
}

int main() {
    Tower myTower;
    Tower seoulTower(100);
    cout << "���̴� " << myTower.getHeight() << "����" << endl;
    cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}
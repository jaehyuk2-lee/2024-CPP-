#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(string name = "") {
        this->name = name;
    }
    // �迭 ����� �⺻ �Ű������� ���� ���·� �迭�� ����
    // ����Ʈ �Ű����� �����ڸ� ������ �Ű������� ���� �� �̸� ����
    // NamedCircle�� ������ �� �θ� Ŭ���� Circle�� �����ڰ� ���� ����
    // �̶� �����ϴ� ���� ���� ������ 0���� �������� ����
    // CircleŬ������ ��ӹ޾ұ� ������ setRadius() ����Լ��� �������� ���� ����

    void setName(string name) { this->name = name; }
    // ���޹��� �̸��� ������ ����Լ�
    string getName() { return name; }
    // �����ϰ� �ִ� �̸� ��ȯ
};

int main() {
    NamedCircle pizza[5]; // ������ 0, �̸��� ���� NamedCircle 5�� �迭�� ����
    cout << "5���� �������� ���� �̸��� �Է��ϼ���" << endl;

    int radius;
    string name;
    // �Է¹��� �������� �̸��� ������ ����
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ">> ";
        cin >> radius >> name; // �������� �̸��� ���������� �Է�
        pizza[i].setRadius(radius);
        // ��ӹ��� �θ�Ŭ����(Circle)�� ����Լ��� ������ ����
        pizza[i].setName(name);
        // �ڽ�Ŭ����(NamedCircle)�� ����Լ��� �̸� ����
    }

    int max_index = 0; // ���̰� ���� ū ������ �ε���, 0���� �����ؼ� ��
    for (int i = 1; i < 5; i++) {
        if (pizza[max_index].getArea() < pizza[i].getArea()) {
            max_index = i;
        } // �θ�Ŭ����(Circle)�� ����Լ��� ���� ��
    }
    // ���̰� ���� ū �ε��� ����

    cout << "������ ���� ū ���ڴ� " << pizza[max_index].getName() << "�Դϴ�.\n";
    // ���� ū ������ name������ ��ȯ�޾� ���
}
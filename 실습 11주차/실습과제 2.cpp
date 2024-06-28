#include <iostream>
#include <string>
using namespace std;

class LoopAdder {   // �߻� Ŭ����
    string name;   // ������ �̸�
    int x, y, sum; // x���� y������ ���� sum
    void read();   // x, y ���� �о� ���̴� �Լ�
    void write();  // sum�� ����ϴ� �Լ�
protected:
    LoopAdder(string name = "") { // ������ �̸��� �޴´�. �ʱ갪�� ""
        this->name = name;
    }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0; // ���� ���� �Լ�. ������ ���� ���� ���ϴ� �Լ�
public:
    void run(); // ������ �����ϴ� �Լ�
};

void LoopAdder::read() { // x, y �Է�
    cout << name << ": " << endl;
    cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
    cin >> x >> y;
}
void LoopAdder::write() { // ��� sum ���
    cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�." << endl;
}
void LoopAdder::run() {
    read();            // x, y�� �д´�.
    sum = calculate(); // ������ ���鼭 ����Ѵ�.
    write();           // ��� sum�� ����Ѵ�.
}

class WhileLoopAdder : public LoopAdder {
public:
    WhileLoopAdder(string name) : LoopAdder(name) {};
    // while���� Adder�� �̸��� �Է¹޾� Adder�� �̸����� ����

    int calculate() override {
        int sum = 0;
        int x = getX();
        int y = getY();
        // calculate �Լ������� ����� ���� ����

        while (x <= y) {
            sum += x;
            x++;
        } // while�� ���
        // x�� y���� �۰ų� �������� x�� 1�� ������Ű�� sum�� �ջ�
        // �� x���� y���� ��� ���� sum�� �ջ�
        // x�� y�� ���� ���� ���ǿ� �����ؼ� �ݺ��ϰ�, y+1�� �Ǿ� �ݺ����� ������ �ʴ´�

        return sum; // �ջ��� �� ��ȯ
    }
};


class DoWhileLoopAdder : public LoopAdder {
public:
    DoWhileLoopAdder(string name) : LoopAdder(name) {};
    // while���� Adder�� �̸��� �Է¹޾� Adder�� �̸����� ����

    int calculate() override {
        int sum = 0;
        int x = getX();
        int y = getY();
        // calculate �Լ������� ����� ���� ����

        do {
            sum += x;
            x++;
        } while (x <= y);
        // do while
        // x�� y���� �۰ų� �������� x�� 1�� ������Ű�� sum�� �ջ�
        // x�� y�� ���� ���� �� ���� sum�� �ջ�,
        // sum�� ���� �� 1�� ������ y+1�� ���� �Ǿ� �ݺ�����

        return sum; // �ջ��� �� ��ȯ
    }
};

int main() {
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");

    whileLoop.run();
    doWhileLoop.run();
    // LoopAdderŬ������ run()�Լ��� �������̵��� calculate()�Լ��� ����
}
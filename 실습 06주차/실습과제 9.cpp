#include <iostream>
using namespace std;

class Accumulator {
    int value;

public:
    Accumulator(int value);  // �Ű� ���� value�� ��� value�� �ʱ�ȭ�Ѵ�.
    Accumulator& add(int n); // value�� n�� ���� ���� �����Ѵ�.
    int get();               // ������ �� value�� �����Ѵ�.
};

Accumulator::Accumulator(int value) {
    this->value = value;
}

Accumulator& Accumulator::add(int n) {
    Accumulator& self = *this;
    // this�� �ڱ��ڽ��� ��ü�� �ּҸ� ����Ű�� �������̴�
    // ���� *this�� ��ü�ڱ��ڽ��̹Ƿ� self��� ���۷��� ������ ������ �ڱ��ڽ����� ����Ѵ�
    self.value += n;
    cout << self.value << endl; // ������ ���� Ȯ���ϱ����� ���
    return self; // �ڱ��ڽ��� ���۷����� ��ȯ�Ѵ�.
}

int Accumulator::get() {
    return this->value;
}

int main() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
    // [[acc.add(5)].add(6)].add(7) ������ ������ ���ȣ�� �ϳ��� ��ü ���۷����̴�.
    cout << acc.get();        // 28 ���
}
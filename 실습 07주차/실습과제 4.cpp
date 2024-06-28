#include <iostream>
using namespace std;

class MyVector {
    int* mem;
    int size;

public:
    MyVector(int n = 100, int val = 0) {
        this->size = n;
        this->mem = new int[size];
        for (int i = 0; i < size; i++) {
            this->mem[i] = val;
        }
    }
    // MyVector�����ڴ� �Ű������� ������ �⺻���� size = 100�� �迭�� �����ϰ�, 0�� ���� �Ҵ��Ѵ�,
    // �Ű������� �ԷµǸ�, �Է¹��� ũ�⸸ŭ �����Ҵ� ��, �Է¹��� ������ �迭�� ��ҵ��� �ʱ��Ѵ�.

    void checkVector() {
        cout << "�迭�� ũ�� : " << this->size << "\t �迭�� ����� �� : " << this->mem[0] << "\n";
    }
    // �迭�� ũ���, �ȿ� ����Ǿ� �ִ� ���� Ȯ���ϴ� �Լ�,
    // �迭�� �ʱ�ȭ �� �� ��� ���� ���� ������ �ʱ�ȭ �Ǳ� ������, 0��° ���� ����Ѵ�.
    ~MyVector() { delete[] mem; }
};

int main() {
    MyVector arr0; // �Ű������� ���� ������ size 100 ��� ���� 0���� �ʱ�ȭ �� �迭�̴�.
    arr0.checkVector();

    MyVector arr1(10);
    // �Ű������� �Ѱ��� �־��� ������ size 10�� ��簪�� 0�� �ʱ�ȭ �� �迭�̴�.
    // ����Ʈ �Ű������� ���� �����ʿ� �ۼ��ž��ϱ� ������, �Ű������� ������ ���� ���� ����ȴ�. 
    arr1.checkVector();

    MyVector arr2(10, 2); // ũ���� �Ű�����, ���� �Ű������� ��� �־��� ������ size 10�� ��� ���� 2�� �ʱ�ȭ �� �迭�̴�.
    arr2.checkVector();

    return 0;
}
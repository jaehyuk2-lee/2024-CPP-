#include <iostream>
using namespace std;

class AbstractStack {
public:
    virtual bool push(int n) = 0; // ���ÿ� n�� Ǫ���Ѵ�. ������ full�̸� false ����
    virtual bool pop(int& n) = 0; // ���ÿ��� ���� ������ n�� �����ϰ� ������ empty�̸� false ����
    virtual int size() = 0;       // ���� ���ÿ� ����� ������ ���� ����
};
// ������ ����� �����

class IntStack : public AbstractStack {
    int* arr;
    int top;
    int capacity;
public:
    IntStack(int size = 100) {
        cout << "���� ���� [Size : " << size << "]\n";
        arr = new int[size];
        // �Ű������� ����� ���޹޾� �迭�� �Ҵ� (������ ũ��)
        top = -1;
        capacity = size;
        // �Ҵ���� �迭�� ũ��, �� ���뷮�� ����
    }
    ~IntStack() {
        delete[] arr;
        // �������� ������ �迭 �޸� ��ȯ
    }

    bool push(int n) override {
        if (is_full()) {
            cout << "Stack is full.\n";
            return false;
        } // stack�� full�̸� false ����

        else {
            arr[++top] = n;
            return true;
        }
        // top�� �������� �Է¹��� ���� index�̰� ������ index�̹Ƿ�,
        // ���ο� ���� ������ 1ĭ �������� ���� �� ���� �����Ѵ�.
    }

    bool pop(int& n) override {
        if (is_empty()) {
            cout << "Stack is empty.\n";
            return false;
        } // ������ ����ִٸ� ���� ���� �� ����
        else {
            n = arr[top--];
            return true;
        }
        // ���޹��� ���۷����� ������ index�� ���� �����ϰ�,
        // ������ index (top)�� 1ĭ ������ ����, �迭�� ���� ������ �� ������ �������� ���ٺҰ�
    }

    int size() override {
        return top + 1;
        // top�� �� ���� ���� �� ���� index�̱� ������, ����� ���� -1�� ���� ������.
        // ���� top+1�� ���� ����� ���� �����̴�.
    }

    bool is_empty() {
        if (top == -1) return true;
        else return false;
    } // stack�� ����ִ��� Ȯ���ϴ� �Լ�

    bool is_full() {
        if (size() == capacity) return true;
        else return false;
    } // stack�� ���� �� �ִ��� Ȯ���ϴ� �Լ�, ���� �����ϰ��ִ� ���� ������, ���뷮�̸� �ִ�� ���� ��
};

int main() {
    IntStack s(5);
    int x; // stack�� push�� ���� ������ ����

    if (!s.is_full()) { // ���� stack�� ������ ������ �ִٸ� 
        do {
            cout << "push>> ";
            cin >> x;
        } while (s.push(x));
        // �Է¹��� x�� ���� ������ �� �������� ��� �ݺ�,
        // ���뷮�� 10�� ���ÿ��� 11���� �Է��� �ϸ� 11��°�� stack�� full�� ���� Ȯ���� �� �ִ�.
    }
    

    int out; // stack���� pop�� ���� ������ ����
    while (s.pop(out)) {
        cout << out << " ";
    }
    // pop�� ������ ���� (stack�� ������� �ʴ� ����) pop�� �ݺ�,
    // ���뷮�� 10�� ������ 10���� pop�ϰ� ������ ��� �ǹǷ� Stack is empty ���� Ȯ���� �� �ִ�.
}
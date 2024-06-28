#include <iostream>
using namespace std;

class BaseArray {
private:
    int capacity;        // �迭�� ũ��
    int* mem; // ���� �迭�� ����� ���� �޸��� ������
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    // �����ڰ� protected�̸� �ڽ�Ŭ�������� �ۿ� �����Ұ���
    // BaseArray���� ��ü ���� �Ұ�
    ~BaseArray() { delete[] mem; }
    // �ڽ�Ŭ������ �Ҹ��� ���� ����
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
    int top; // stack�� ���� ���� ��ġ�� ����
public:
    MyStack(int capacity = 100) : BaseArray(capacity) {
        top = -1;
    }

    int is_full() {
        if (top == getCapacity() - 1) {
            return 1;
        }
        else return 0;
    } // ���� �����ִ� ���Ұ� ũ��-1(������ index) �̸� stack�� full

    int length() {
        return top + 1;
    }
    // top�� �� �� ������ index�̱� ������ +1 �� ���� stack�� ����
    // ex) top == -1 �̸� ������ ����ֱ� ������ ���̰� +1�� 0���� �� �� �ִ�.

    void push(int val) {
        if (!is_full()) {
            put(++top, val);
        }
    }
    // �Է��� ������ �� ���ÿ� ������� ���� ��� ��ӹ��� ����Լ��� �迭�� ���� �����Ѵ�.

    int pop() {
        return get(top--);
    }
    // pop���Ŀ��� ���� ���ٰ� ���
    // ���� ���� ���Ϲް� �ְ�index�� 1�� ���߾� �迭�� ���� ���������� �������� ���ٺҰ�

    int capacity() {
        return getCapacity();
    } // �ܺ��Լ��� ���뷮�� �����մϴ�.
};

int main() {
    MyStack mStack(100);
    int size;
    cout << "���ÿ� �Է��� ���� >> ";
    cin >> size;
    int n;
    cout << "���ÿ� ������ " << size << "���� ������ �Է��϶� >> ";
    for (int i = 0; i < size; i++) {
        cin >> n;
        mStack.push(n); // ���ÿ� Ǫ��
    }
    cout << "���ÿ뷮 : " << mStack.capacity() << ", ����ũ��: " << mStack.length() << endl;
    cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << " "; // ���ÿ��� ��
    }
    cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}
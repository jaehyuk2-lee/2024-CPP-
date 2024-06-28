#include <iostream>
using namespace std;

class MyIntStack {
    int p[10]; // �ִ� 10���� ���� ����
    int tos;   // ������ ����⸦ ����Ű�� �ε���
public:
    MyIntStack() {
        tos = -1; // ����ִ� stack�� �ƹ����� ���� ������ -1���� ����
    }
    bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
    bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
};

bool MyIntStack::push(int n) {
    if (tos == 9) {
        // �ִ� 10���� �ڷḦ �����ϱ� ������ �ε����� 0~9
        // ���� stack�� �� �������� ���� ���� ���� 9���� ��ġ�Ѵ�
        return false;
    }
    else {
        p[++tos] = n;
        // ���� ���� ��ġ�� �̵��� ���� �����Ѵ�.
        return true;
    }
}

bool MyIntStack::pop(int& n) {
    if (tos == -1) { // ������� ���� �������� �ʴ´�. �� stack�� ���� ����Ǿ����� �ʴ�.
        return false;
    }
    else {
        n = p[tos--]; // ���� �������� �ִ� ���� ���� n�� ������ ��ĭ �����´�.
        return true;
    }
}

int main() {
    MyIntStack a;
    for (int i = 0; i < 11; i++) { // 11���� Ǫ���ϸ�, ���������� stack full�� �ȴ�.
        if (a.push(i))
            cout << i << ' '; // Ǫ�õ� �� ����
        else
            cout << endl
            << i + 1 << " �� ° stack full" << endl;
    }
    int n;
    for (int i = 0; i < 11; i++) { // 11���� ���ϸ�, ���������� stack �� �ȴ�.
        if (a.pop(n)) {
            cout << n << ' '; // �� �� �� ���
        }
        else cout << endl << i + 1 << " �� ° stack empty";
    }
    cout << endl;
}

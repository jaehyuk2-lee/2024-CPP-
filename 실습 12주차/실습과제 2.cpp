#include <iostream>
using namespace std;

template<class T>
bool search(T, T[], int);
// ���׸��Լ��� ���� ���� �� �����Լ� �ڿ��� ����

int main() {

    int x[] = { 1, 10, 100, 5, 4 };
    if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ִ�\n";
    else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�\n";

    double y[] = { 1.1, 1.2, 1.3, 3.14, 1.5 };
    if (search(3.14, y, 5)) cout << "3.14�� �迭 x�� ���ԵǾ� �ִ�\n";
    else cout << "3.14 �� �迭 x�� ���ԵǾ� ���� �ʴ�\n";
    // double�� ��üȭ�� �Լ� �۵�
}

template<class T> // �����ο����� template<class T>�� �ۼ��ؾ� ����ο� ��Ī����
bool search(T n, T x[], int size) {
    for (int i = 0; i < size; i++) {
        if (x[i] == n) return true;
    }
    return false;
}
// �迭�� ����� ���� ã�� ���̶� ��, �ݺ��� ���� ã�Ҵٸ� true�� �����ϸ� ����
// �迭�� ����Ȯ���ߴٸ� ã�� ���� �����ٴ� �ǹ��̹Ƿ�, false�� �����ϸ� ����
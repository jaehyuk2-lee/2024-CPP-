#include <iostream>
using namespace std;

template<class T> // T�� �Ϲ�ȭ�� �Լ��� �����ۼ�, �Ű������� ���޹޴� �迭�� Ÿ������ ��üȭ
bool equalArrays(T x[], T y[], int size) {
    for (int i = 0; i < size; i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}
// �迭�� ũ�⸦ ���޹޾�, �迭�� ��� ������ ��
// ���� ��ġ�� ���� �ٸ��ٸ� false�� �����ϸ� �Լ��� ����
// �ݺ������� �迭�� ���� ���ߴٸ�, ���� ��ġ�� ������ ���� ���ұ� ������ true����

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    int y[] = { 1, 10, 100, 5, 4 };
    cout << "int �迭 �� ���\n";
    cout << "x: ";
    for (int i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }
    cout << "\ny: ";
    for (int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }
    cout << endl;
    // ��� Ȯ���� ���� ���� �迭�� ���

    if (equalArrays(x, y, 5)) cout << "����\n"; // �迭 x, y�� �����Ƿ� "����" ���
    else cout << "�ٸ���\n";

    double z[] = { 1.2, 10.3, 100.4, 5.5, 4.6 };
    double w[] = { 1.2, 10.3, 100.3, 5.4, 4.5 };
    cout << "double �迭 �� ���\n";
    cout << "w: ";
    for (int i = 0; i < 5; i++) {
        cout << w[i] << " ";
    }
    cout << "\nz: ";
    for (int i = 0; i < 5; i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    // �ٸ� �ڷ������� �Լ��� �۵��ϴ��� Ȯ���ϱ� ���� double �迭 ����

    if (equalArrays(w, z, 5)) cout << "����\n";
    else cout << "�ٸ���\n";
}
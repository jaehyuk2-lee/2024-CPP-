#include <iostream>
using namespace std;

int main() {
    int* arr;
    arr = new int[5]; // arr�� ������ 5�� �迭 �����Ҵ�
    cout << "���� 5�� �Է� >> ";

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    } // arr�� ���� �� �Է�

    double average = 0; // ��հ��� ������ ���� ����
    for (int i = 0; i < 5; i++) {
        average += arr[i]; // arr�� i��°�� ���� ��� ���ϱ�
    }
    average /= 5; // �ٴ����� ���� ���� ������ ���� ��հ��� ����

    cout << fixed; // ��½� �Ҽ��� �ڸ����� �����ϱ�
    cout.precision(1); // ��½� �Ҽ��ڸ��� ������ 1�ڸ��� ����

    cout << "��� " << average << endl;
    delete[] arr; // ����� �޸� ����, �迭�� �����Ҵ� �޾ұ� ������ delete[]�� ����
}
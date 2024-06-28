#include <iostream>
using namespace std;

int big(int, int);
int big(int, int, int);
// �����ϴ� �Ű������� ������ 2���� ���� 3���ΰ�찡 �����Ƿ� �Լ� �ߺ����� 2���� �����̸��� �Լ��� �ۼ��Ѵ�.

int main() {
    int x = big(3, 5);       // 3�� 5�� ū �� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
    int y = big(300, 60);    // 300�� 60 �� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
    int z = big(30, 60, 50); // 30�� 60 �� ū �� 600�� �ִ밪 50���� ũ�Ƿ�, 50 ����
    cout << x << ' ' << y << ' ' << z << endl;
}

int big(int a, int b) {
    int comp = a > b ? a : b; // a�� b�� ���ؼ� a>b�� a, a<=b�� b�� ����
    return comp > 100 ? 100 : comp; 
    // a�� b�� ���ؼ� ū ���� comp�� �����ϰ� �� ���� c�� ���ؼ�
    // comp�� 100�� �Ѿ��ٸ� 100�� ��� �ƴ϶�� comp�� ���
}

int big(int a, int b, int c) {
    int comp = (a > b ? a : b); // a�� b�� ���ؼ� a>b�� a, a<=b�� b�� ����
    return comp > c ? c : comp;
    // a�� b�� ���ؼ� ū ���� comp�� �����ϰ� �� ���� c�� ���ؼ�
    // comp�� c�� �Ѿ��ٸ� c�� ��� �ƴ϶�� comp�� ���
}
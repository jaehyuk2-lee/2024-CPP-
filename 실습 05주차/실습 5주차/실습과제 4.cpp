#include <iostream>
using namespace std;

class Sample {
public:
    Sample(int n) { // ������
        size = n;
        p = new int[n]; // n�� ���� �迭�� ���� ����
    } 
    void read() {
        for (int i = 0; i < size; i++) {
            cin >> p[i];
        } // �ݺ������� ������ �����ؼ� �Է¹ޱ�
    } // ���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է� ����

    void write() {
        for (int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    } // ���� �迭�� ȭ�鿡 ���

    int big() {
        int max = p[0];
        for (int i = 1; i < size; i++) {
            if (p[i] > max) {
                max = p[i];
            }
        } // ��� �迭�� Ȯ���ϸ鼭 max������ ū���� �ִ��� Ȯ���ϰ� ������ max���� �ֽ�ȭ ���ش� (����Ž�� �˰���)

        return max;
    } // ���� �迭���� ���� ū �� ����

    ~Sample() {
        delete[] p;
    } // �Ҹ���, ��ü�� �Ҹ��� �� ���������� p��ü �޸� ����

private:
    int* p;
    int size;
};

int main() {
    Sample s(10); // 10�� ���� �迭�� ���� Sample ��ü ����
    s.read(); // Ű���忡�� ���� �迭 �б�
    s.write(); // ���� �迭 ���
    cout << "���� ū ���� " << s.big() << endl; // ���� ū �� ���
}
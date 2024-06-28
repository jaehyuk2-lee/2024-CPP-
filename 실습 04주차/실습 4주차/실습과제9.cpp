#include <iostream>
using namespace std;

class Oval {
public:
    Oval() {
        width = 1;
        height = 1;
    } // �Ű����� ���� �����Ǹ� ���̿� ���� 1�� ����
    Oval(int w, int h) {
        width = w;
        height = h;
    } // �Ű������� �����ϸ� ��� ������ ���� �Է�
    void set(int w, int h) {
        width = w;
        height = h;
    } // ���Ӱ� ������ ���̿� ���� �Ű������� �Է¹ް�, ��� ������ �Է�
    void show() {
        cout << "width = " << width << ", height = " << height << endl;
    }

    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    // ������ ����� �����ϴ� �޼ҵ�

    ~Oval() {
        cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl;
    } // �Ҹ��ڸ� ������ ��ü�� ������ �� ��� ������ ������ ������ְ� ����

private: // ���� ���̸� ������ ��� ����
    int width, height;
};

int main() {
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << "," << b.getHeight() << endl;
}
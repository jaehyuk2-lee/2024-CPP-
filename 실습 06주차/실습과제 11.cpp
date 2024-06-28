#include <iostream>
using namespace std;

class Book {
    char* title; // ���� ���ڿ�
    int price;   // ����
public:
    Book(const char* title, int price) {
        int size = strlen(title) + 1; // ���ڿ��� ������ ���ؼ� �ΰ��� �����ؾ� �Ǳ� ������ �Է¹��� ���ڿ����� 1ū ũ�⸦ �Ҵ��Ѵ�
        this->title = new char[size];
        for (int i = 0; i < size; i++) {
            this->title[i] = title[i];
        }
        this->price = price;
    } // �Է¹��� ���ڿ��� ũ�Ⱑ ���� ���ο� ���ڿ��� �����ϰ� �� �ȿ�, ���ڿ��� ���� �ϳ��� ����ִ´�.

    Book(const Book& b) {
        int size = strlen(b.title) + 1;
        this->title = new char[size];
        for (int i = 0; i<size; i++) {
            this->title[i] = b.title[i];
        }
        this->price = b.price;
    } // �������縦 �����ϱ�����, ��������ڸ� ����

    ~Book() {
        delete[] this->title;
    }

    void set(const char* title, int price) {
        // �ּҿ� ���� ������ ���޹ޱ� ������ �������� ������ �ʰ� �ϱ����� const�� ���ȭ
        if (this->title != NULL) { // ���繮�ڿ��� �ԷµǾ��ִٸ�, �����Ҵ� ���� �޸� ����
            delete[] this->title;
        }
        int size = strlen(title) + 1;
        this->title = new char[size];
        for (int i = 0; i<size; i++) {
            this->title[i] = title[i];
        }
        this->price = price;
    }
    void show() { cout << this->title << ' ' << price << "��" << endl; }
};

int main() {
    Book cpp("��ǰC++", 10000);
    Book java = cpp; // ���� ������ ȣ���
    java.set("��ǰ�ڹ�", 12000);
    cpp.show();
    java.show();
}

// 2) ����Ʈ ���������
// Book(const Book& b) {
//     this->title = b.title;
//     this->price = b.price;
// }
// ���⼭ ��ü�� �����Ͱ� ���޹��� ��ü�� ���ڿ��� �����ϰ� �ֱ� ������ ��� ������ ���� delete�� �Ǹ�
// �ٸ� ������ ������ �޸𸮰� ��� ������ �߻��Ѵ�.
// ��������� ���� ������ ��������� ��������ڸ� �ٽ� �ۼ��ؾ��Ѵ�.
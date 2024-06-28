#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // ���� ���ڿ�
    int price;   // ����
public:
    Book(string title, int price) {
        this->title = title;
        this->price = price;
    } // stringŬ���� ��ü�� ���Կ����ڷ� �����ϰ� ������ �� �ִ�

    void set(string title, int price) {
        this->title = title;
        this->price = price;
    }
    void show() { cout << title << ' ' << price << "��" << endl; }
}; // �޸𸮸� �Ҵ���� ������ delete�� ������� �ʾƵ� �ȴ�. ���� �Ҹ��ڸ� �����ص� ������

int main() {
    Book cpp("��ǰC++", 10000);
    Book java = cpp;
    // ���� ������ ȣ��, ���⼭ ����Ʈ��������ڸ� ����ص� ���� �޸𸮸� ���������ʰ� ���� �����ؼ� �ٿ��ֱ� ������
    // ���� ���翡���� ������ �߻����� �ʴ´�.
    java.set("��ǰ�ڹ�", 12000);
    cpp.show();
    java.show();
}
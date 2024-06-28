#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price, pages;

public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }
    void show() {
        cout << title << ' ' << price << "�� " << pages << "������" << endl;
    }
    string getTitle() { return title; }

    bool operator==(int price) {
        if (this->price == price) return true;
        else return false;
    } // ������ ���Ѱ�� ���ݰ� ��
    bool operator==(string title) {
        if (this->title == title) return true;
        else return false;
    } // ���ڿ��� ���� ��� �̸��� ��
    bool operator==(const Book& b) {
        if (this->title == b.title && this->pages && b.pages && this->price == b.price) return true;
        else return false;
    }
    // ��ü�� ���� ��� ��� ��������� ���� ���� �������� ��
};

int main() {
    Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
    if (a == 30000) cout << "���� 30000��" << endl; // 1. price ��
    if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // 2. å title ��
    if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; // 3. title, price, pages ��� ��

    Book c("��ǰ C++", 30000, 500);
    if (a == c) cout << "�� å�� ���� å�Դϴ�." << endl;
    // a�� �Ȱ��� ��ü�� �ϳ� �� ������ ������ ��
}
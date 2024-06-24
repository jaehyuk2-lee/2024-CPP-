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
        cout << title << ' ' << price << "원 " << pages << "페이지" << endl;
    }
    string getTitle() { return title; }

    void operator += (int num) {
        price += num;
    }
    void operator -= (int num) {
        price -= num;
    }
    // 멤버변수의 값을 변경하는 연산자이기 때문에 리턴 값이 필요 X
};

int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500; // 책 a의 가격 500원 증가
    b -= 500; // 책 b의 가격 500원 감소
    a.show();
    b.show();
}
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
    friend void operator +=(Book&, int);
    friend void operator -=(Book&, int);
    // a += 500의 경우, a의 가격이 +500으로 바뀌어야 하기 때문에 객체 레퍼런스를 사용
};

void operator += (Book& a, int num) {
    a.price += num;
}
void operator -= (Book& a, int num) {
    a.price -= num;
}
// friend를 사용했기때문에 객체의 private에 접근가능

int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500; // 책 a의 가격 500원 증가
    b -= 500; // 책 b의 가격 500원 감소
    a.show();
    b.show();
}
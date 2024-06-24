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
    friend bool operator==(const Book& , int);
    friend bool operator==(const Book& , string);
    friend bool operator==(const Book& , const Book&);
    // 외부함수를 friend로 선언해 객체 내부의 값 접근가능
};

bool operator==(const Book& a, int price) {
        if(a.price == price) return true;
        else return false;
} // 정수로 비교한경우 가격과 비교
bool operator==(const Book& a, string title) {
        if(a.title == title) return true;
        else return false;
} // 문자열로 비교한 경우 이름과 비교
bool operator==(const Book& a, const Book& b) {
        if(a.title == b.title && a.pages && b.pages && a.price == b.price) return true;
        else return false;
} // 객체로 비교한 경우 모든 멤버변수가 같은 값을 가지는지 비교

int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++" , 30000, 500);
    if(a == 30000) cout << "정가 30000원"<< endl; // 1. price 비교
    if(a =="명품 C++") cout << "명품 C++ 입니다." << endl; // 2. 책 title 비교
    if(a == b) cout << "두 책이 같은 책입니다." << endl; // 3. title, price, pages 모두 비교

    Book c("명품 C++" , 30000, 500);
    if(a == c) cout << "두 책이 같은 책입니다." << endl;
    // a와 똑같은 객체를 하나 더 생성해 같은지 비교
}
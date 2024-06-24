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

    friend bool operator < (string, const Book&);
    // 문자열과 객체의 이름을 비교해야 되기 떄문에, friend 함수로 객체의 멤버에 접근 허용
};

bool operator < (string name, const Book& a) {
        if(name < a.title) return true;
        else return false;
} // 객체가 뒤에서 비교되기 때문에, 매개변수에 객체가 존재하는 외부 변수로 사용 

int main() {
    Book a("청춘", 20000, 300);
    string b;
    cout << "책 이름을 입력하세요>> ";
    getline(cin, b); // 키보드로부터 문자열로 책 이름을 입력 받음
    if(b < a)
        cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}
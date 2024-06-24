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

    bool operator!() {
        if(price) return false;
        else return true;
    }
    // 책의 가격이 존재하면 공짜가 아니기 때문에,
    // main() 함수의 조건이 만족하기 위해 가격이 0일 때 true를 반환  
};

int main() {
    Book book("벼룩시장", 0, 50); // 가격은 0
    if(!book) cout << "공짜다" << endl;
}
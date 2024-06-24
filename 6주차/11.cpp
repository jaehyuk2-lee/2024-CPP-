#include <iostream>
using namespace std;

class Book {
    char *title; // 제목 문자열
    int price;   // 가격
public:
    Book(const char *title, int price) {
        this->title = new char[strlen(title)];
        for(int i = 0; title[i]; i++) {
            this->title[i] = title[i];
        }
        this->price = price;
    } // 입력받은 문자열과 크기가 같은 새로운 문자열을 생성하고 그 안에, 문자열의 값을 하나씩 집어넣는다.

    Book(const Book& b) {
        this->title = new char[strlen(b.title)];
        for(int i = 0; b.title[i]; i++) {
            this->title[i] = b.title[i];
        }
        this->price = b.price;
    } // 깊은복사를 구현하기위해, 복사생성자를 선언

    ~Book() {
        delete[] this->title;
    }

    void set(const char *title, int price) {
        // 주소에 의한 참조로 전달받기 때문에 원래값이 변하지 않게 하기위해 const로 상수화
        if(this->title != NULL) { // 현재문자열이 입력되어있다면, 동적할당 받은 메모리 해제
            delete[] this->title;
        }
        this->title = new char[strlen(title)];
        for(int i = 0; title[i]; i++) {
            this->title[i] = title[i];
        }
        this->price = price;
    }
    void show() { cout << title << ' ' << price << "원" << endl; }
};

int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp; // 복사 생성자 호출됨
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}

// 2) 디폴트 복사생성자
// Book(const Book& b) {
//     this->title = b.title;
//     this->price = b.price;
// }
// 여기서 객체의 포인터가 전달받은 객체의 문자열을 지정하고 있기 때문에 어느 한쪽이 먼저 delete가 되면
// 다른 한쪽이 해제할 메모리가 없어서 오류가 발생한다.
// 얕은복사로 인한 오류로 깊은복사로 복사생성자를 다시 작성해야한다.
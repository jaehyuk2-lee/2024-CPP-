#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // 제목 문자열
    int price;   // 가격
public:
    Book(string title, int price) {
        this->title = title;
        this->price = price;
    } // string클래스 객체는 대입연사자로 간단하게 대입할 수 있다

    void set(string title, int price) {
        this->title = title;
        this->price = price;
    }
    void show() { cout << title << ' ' << price << "원" << endl; }
}; // 메모리를 할당받지 않으니 delete를 사용하지 않아도 된다. 따라서 소멸자를 생략해도 괜찮다

int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    // 복사 생성자 호출, 여기서 디폴트복사생성자를 사용해도 같은 메모리를 공유하지않고 값을 복사해서 붙여넣기 때문에
    // 얕은 복사에대한 오류가 발생하지 않는다.
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}
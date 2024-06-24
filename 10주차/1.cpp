#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(int radius = 0, string name = "") {
        setRadius(radius);
        this->name = name;
    }
    // 배열 선언시 기본 매개변수가 없는 상태로 배열이 생성
    // 디폴트 매개변수 생성자를 선언해 기본값을 반지름 0, 이름은 선언 X
    // NameCircle클래스가 생성자가 실행될 때 이미 부모클래스의 생성자는 실행된 이후이다.
    // 따라서 Circle클래스를 상속받았기 때문에 setRadius() 멤버함수로 반지름의 값을 설정한다.

    void setName(string name) { this->name = name; }
    // 전달받은 이름을 저장할 멤버함수
    string getName() {return name;}
    // 저장하고 있는 이름 반환
};

int main() {
    NamedCircle pizza[5]; // 반지름 0, 이름이 없는 NamedCircle 5개 배열로 생성
    cout << "5개의 반지름과 원의 이름을 입력하세요" << endl;

    int radius;
    string name;
    // 입력받은 반지름과 이름을 저장할 변수
    for(int i = 0; i < 5; i++) {
        cout << i+1 << ">> ";
        cin >> radius >> name; // 반지름과 이름을 순차적으로 입력
        pizza[i].setRadius(radius);
        // 상속받은 부모클래스(Circle)의 멤버함수로 반지름 설정
        pizza[i].setName(name);
        // 자식클래스(NamedCircle)의 멤버함수로 이름 설정
    }

    int max_index = 0; // 넓이가 가장 큰 피자의 인덱스, 0부터 시작해서 비교
    for(int i = 1; i < 5; i++) {
        if(pizza[max_index].getArea() < pizza[i].getArea()) {
            max_index = i;
        } // 부모클래스(Circle)의 멤버함수로 넓이 비교
    }
    // 넓이가 가장 큰 인덱스 저장

    cout << "면적이 가장 큰 피자는 " << pizza[max_index].getName() << "입니다.\n";
    // 가장 큰 피자의 name정보를 반환받아 출력
}

// 5 크림피자
// 8 치즈피자
// 25 대왕피자
// 30 블랙홀피자
// 15 마늘피자
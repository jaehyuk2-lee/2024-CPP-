#include <iostream>
#include <string>
using namespace std;

class Person {
    int id;
    double weight;
    string name;

public:
    Person(int id = 1, string name = "Grace", double weight = 20.5) {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    // 아무것도 입력하지 않은 생성자(기본생성자)의 역할은 id = 1, name = "Grace", weight = 20.5 로 멤버변수를 설정한다.
    // weight가 생략된 생성자들은 모두 weight가 20.5로 설정되있는것을 확인할 수 있었다.
    // 따라서 int id = 1, string name = "Grace", double weight = 20.5 로 디폴트 매개변수를 설정해
    // 매개변수가 전달될 때만 멤버변수를 설정하게 작성한다. 

    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main() {
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}
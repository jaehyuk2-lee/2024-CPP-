#include <iostream>
#include <string>
using namespace std;

class Person {
    int id;
    double weight;
    string name;

public:
    Person() {
        this->id = 1;
        this->name = "Grace";
        this->weight = 20.5;
    }
    Person(int id, string name) {
        this->id = id;
        this->name = name;
        this->weight = 20.5;
    }
    Person(int id, string name, double weight) {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    // 문제의 결과를 확인했을 때 기본생성자는 id = 1, name = "Grace", weight = 20.5로 설정되는 것을 확인할 수 있다.
    // id와 이름을 매개변수로 받으면 그 매개변수로 멤버변수가 설정되는 것을 확인할 수 있다. weight는 20.5로 설정된다.
    // id와 이름, weight를 매개변수로 받으면 각각 멤버변수로 설정되는 것을 확인할 수 있다.
    // 위 3가지 경우에 대해 각각 생성자를 작성한다.

    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main() {
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}
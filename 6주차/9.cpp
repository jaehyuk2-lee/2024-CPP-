#include <iostream>
using namespace std;

class Accumulator{
    int value;

public:
    Accumulator(int value);  // 매개 변수 value로 멤버 value를 초기화한다.
    Accumulator &add(int n); // value에 n을 더해 값을 누적한다.
    int get();               // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value) {
    this->value = value;
}

Accumulator& Accumulator::add(int n) {
    Accumulator& self = *this;
    // this는 자기자신의 객체의 주소를 가르키는 포인터이다
    // 따라서 *this는 객체자기자신이므로 self라는 레퍼런스 변수를 설정해 자기자신으로 사용한다
    self.value += n;
    cout << self.value << endl;
    return self; // 자기자신을 레퍼런스로 반환한다.
}

int Accumulator::get() {
    return this->value;
}

int main(){
    Accumulator acc(10);
    acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
    // [[acc.add(5)].add(6)].add(7) 순서로 각각의 대괄호가 하나의 객체 레퍼런스이다.
    cout << acc.get();        // 28 출력
}
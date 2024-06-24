#include <iostream>
#include <string>
using namespace std;

class LoopAdder {   // 추상 클래스
    string name;   // 루프의 이름
    int x, y, sum; // x에서 y까지의 합은 sum
    void read();   // x, y 값을 읽어 들이는 함수
    void write();  // sum을 출력하는 함수
protected:
    LoopAdder(string name = "") { // 루프의 이름을 받는다. 초깃값은 ""
        this->name = name;
    }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌며 합을 구하는 함수
public:
    void run(); // 연산을 진행하는 함수
};
void LoopAdder::read() { // x, y 입력
    cout << name << ": " << endl;
    cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
    cin >> x >> y;
}
void LoopAdder::write() { // 결과 sum 출력
    cout << x << "에서 "<< y << "까지의 합 = " << sum << " 입니다." << endl;
}
void LoopAdder::run() {
    read();            // x, y를 읽는다.
    sum = calculate(); // 루프를 돌면서 계산한다.
    write();           // 결과 sum을 출력한다.
}

class WhileLoopAdder : public LoopAdder {
public:
    WhileLoopAdder(string name) : LoopAdder(name) {};
    // while루프 Adder의 이름을 입력받아 Adder의 이름으로 설정

    int calculate() override {
        int sum = 0;
        int x = getX();
        int y = getY();
        // calculate 함수에서만 사용할 변수 설정

        while(x <= y) {
            sum += x;
            x++;
        } // while문 사용
        // x가 y보다 작거나 같은동안 x를 1씩 증가시키며 sum에 합산
        // 즉 x부터 y까지 모든 값을 sum에 합산
        // x가 y가 됐을 때도 조건에 만족해서 반복하고, y+1이 되어 반복문에 들어오지 않는다

        return sum; // 합산한 값 반환
    }
};


class DoWhileLoopAdder : public LoopAdder {
public:
    DoWhileLoopAdder(string name) : LoopAdder(name) {};
    // while루프 Adder의 이름을 입력받아 Adder의 이름으로 설정

    int calculate() override {
        int sum = 0;
        int x = getX();
        int y = getY();
        // calculate 함수에서만 사용할 변수 설정

        do {
            sum += x;
            x++;
        } while(x <= y);
        // do while
        // x가 y보다 작거나 같은동안 x를 1씩 증가시키며 sum에 합산
        // x가 y의 값이 됐을 때 까지 sum에 합산,
        // sum에 더한 후 1이 증가돼 y+1의 값이 되어 반복종료
        
        return sum; // 합산한 값 반환
    }
};

int main() {
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");

    whileLoop.run();
    doWhileLoop.run();
}
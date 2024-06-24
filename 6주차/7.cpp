#include <iostream>
using namespace std;

class MyIntStack {
    int p[10]; // 최대 10개의 정수 저장
    int tos;   // 스택의 꼭대기를 가리키는 인덱스
public:
    MyIntStack() {
        tos = -1; // 비어있는 stack은 아무값도 없기 때문에 -1부터 시작
    }
    bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
    bool pop(int &n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};

bool MyIntStack::push(int n) {
    if(tos == 9) {
        // 최대 10개의 자료를 저장하기 때문에 인덱스는 0~9
        // 따라서 stack이 꽉 차있으면 가장 높은 값은 9번에 위치한다
        return false;
    }
    else {
        p[++tos] = n;
        // 가장 높은 위치로 이동후 값을 저장한다.
        return true;
    }
}
bool MyIntStack::pop(int &n) {
    if(tos == -1) { // 가장높은 값이 존재하지 않는다. 즉 stack에 값이 저장되어있지 않다.
        return false;
    }
    else {
        n = p[tos--]; // 제일 높은곳에 있는 값을 꺼내 n에 저장후 한칸 내려온다.
        return true;
    }
}

int main() {
    MyIntStack a;
    for (int i = 0; i < 11; i++) { // 11개를 푸시하면, 마지막에는 stack full이 된다.
        if (a.push(i))
            cout << i << ' '; // 푸시된 값 에코
        else
            cout << endl
                 << i + 1 << " 번 째 stack full" << endl;
    }
    int n;
    for (int i = 0; i < 11; i++) { // 11개를 팝하면, 마지막에는 stack 가 된다.
        if (a.pop(n)) {
            cout << n << ' '; // 팝 한 값 출력
        }
        else cout << endl << i + 1 << " 번 째 stack empty";
    }
    cout << endl;
}

#include <iostream>
using namespace std;

class MyIntStack {
    int* p; // 스택 메모리로 사용할 포인터
    int size; // 스택의 최대 크기, stack이 full인지 아닌지 구분하기위해 필요
    int tos; // 스택의 탑을 가리키는 인덱스, stack이 full인지 아닌지 구분하기위해 필요
public:
    MyIntStack() {
        size = 0; // 스택의 최대크기가 결정되지 않았기 때문에 0으로 초기화
        p = new int[size]; // 스택의 크기만큼 배열생성
    }
    MyIntStack(int size) {
        this->size = size; // 매개변수로 전달받은 정수를 stack의 최대크기로 지정
        p = new int[size]; // 스택의 크기만큼 배열생성
    }
    MyIntStack(const MyIntStack& s) {
        size = s.size;
        p = new int[size];
        tos = s.tos;

        for (int i = 0; i < size; i++) {
            p[i] = s.p[i];
        }
        // 단순히 p = s.p를 해버린다면 p가 가리키는 주소와 s.p가 가르키는 주소가 같아진다.
        // 이때 p든 s.p든 어느한쪽이 메모리를 delete한다면 나머지 한쪽에서 delete를 할 공간이 없어져 오류가 발생한다.
        // 이때 p = s.p의 복사방식을 얕은복사의 방식이라고 한다.
    }
    // 복사 생성자, s를 일반 매개변수로 전달받을시 메모리에 MyIntStack클래스가 가지는 자료형만큼 메모리가 새로 할당된다.
    // class가 포함하는 자료형이 많을수록 사용해야하는 메모리가 커지기 때문에 레퍼런스 변수를 사용하는 것이 효율적이다.
    // 레퍼런스변수를 사용하기 때문에 원래자료형이 변할수 있다. 따라서 const를 통해 상수화를 시켜 값의 변화를 예방한다.
    // 입력받은 객체의 정보를 복사해 저장한다.
    ~MyIntStack() {
        delete[] p;
        // 스택을 최대크기만큼 동적할당 받았기 때문에 메모리를 해제해준다.
    }

    bool push(int n); // 정수 n을 스택에 푸시한다.
    // 스택이 꽉 차 있으면 false를, 아니면 true 리턴
    bool pop(int& n); // 스택의 탑에 있는 값을 n에 팝한다.
    // 만일 스택이 비어 있으면 false를, 아니면 true 리턴
};

bool MyIntStack::push(int n) {
    if (tos == size - 1) {
        // 최대 size개의 자료를 저장하기 때문에 인덱스는 0~size-1
        // 따라서 stack이 꽉 차있으면 가장 높은 값은 size-1번에 위치한다
        return false;
    }
    else {
        p[++tos] = n;
        // 가장 높은 위치로 이동후 값을 저장한다.
        return true;
    }
}
bool MyIntStack::pop(int& n) {
    if (tos == -1) { // 가장높은 값이 존재하지 않는다. 즉 stack에 값이 저장되어있지 않다.
        return false;
    }
    else {
        n = p[tos--]; // 제일 높은곳에 있는 값을 꺼내 n에 저장후 한칸 내려온다.
        return true;
    }
}

int main() {
    MyIntStack a(10);
    a.push(10);
    a.push(20);
    MyIntStack b = a; // 복사 생성
    b.push(30);

    // 현재상태
    // a : 10 20
    // b : 10 20 30
    // 두개의 스택이 존재

    int n;
    a.pop(n); // 스택 a 팝
    cout << "스택 a에서 팝한 값 " << n << endl;
    b.pop(n); // 스택 b 팝
    cout << "스택 b에서 팝한 값 " << n << endl;
}

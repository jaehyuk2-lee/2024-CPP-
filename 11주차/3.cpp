#include <iostream>
using namespace std;

class AbstractStack {
public:
    virtual bool push(int n) = 0; // 스택에 n을 푸시한다. 스택이 full이면 false 리턴
    virtual bool pop(int &n) = 0; // 스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴
    virtual int size() = 0;       // 현재 스택에 저장된 정수의 개수 리턴
};
// 스택의 기능의 선언부

class Stack : public AbstractStack {
    int* arr;
    int top;
    int capacity;
public: 
    Stack(int size = 100) {
        cout << "스택 생성 [Size : " << size << "]\n";
        arr = new int[size];
        // 매개변수로 사이즈를 전달받아 배열에 할당 (스택의 크기)
        top = -1;
        capacity = size;
        // 할당받은 배열의 크기, 즉 수용량을 저장
    }
    ~Stack() {
        delete[] arr;
        // 동적으로 생성한 배열 메모리 반환
    }

    bool push(int n) override {
        if(is_full()) {
            cout << "Stack is full.\n";
            return false;
        } // stack이 full이면 false 리턴

        else {
            arr[++top] = n;
            return true;
        }
        // top은 마지막에 입력받은 값의 index이고 마지막 index이므로,
        // 새로운 값이 들어오면 1칸 다음으로 진행 후 값을 저장한다.
    }
    
    bool pop(int &n) override {
        if(is_empty()) {
            cout << "Stack is empty.\n";
            return false;
        } // 스택이 비어있다면 값을 빼낼 수 없음
        else {
            n = arr[top--];
            return true;
        }
        // 전달받은 레퍼런스에 마지막 index의 값을 저장하고,
        // 마지막 index (top)을 1칸 앞으로 진행, 배열에 값이 저장은 돼 있지만 논리적으로 접근불가
    }

    int size() override {
        return top+1;
        // top은 맨 위에 저장 된 값의 index이기 때문에, 저장된 개수 -1의 값을 가진다.
        // 따라서 top+1의 값이 저장된 값의 개수이다.
    }

    bool is_empty() {
        if(top == -1) return true;
        else return false;
    } // stack이 비어있는지 확인하는 함수

    bool is_full() {
        if(size() == capacity) return true;
        else return false;
    } // stack이 가득 차 있는지 확인하는 함수, 현재 저장하고있는 값의 개수가, 수용량이면 최대로 저장 중
};

int main() {
    Stack s(10);
    int x; // stack에 push할 값을 저장할 변수

    do {
        cout << "push>> ";
        cin >> x;
    } while(s.push(x));
    // 입력받은 x의 값을 저장할 수 있을동안 계속 반복,
    // 수용량이 10인 스택에는 11개의 입력을 하면 11번째에 stack이 full인 것을 확인할 수 있다.

    int out; // stack에서 pop한 값을 저장할 변수
    while(s.pop(out)) {
        cout << out << " ";
    }
    // pop이 가능한 동안 (stack이 비어있지 않는 동안) pop을 반복,
    // 수용량이 10인 스택은 10개를 pop하고 스택이 비게 되므로 Stack is empty 까지 확인할 수 있다.
}
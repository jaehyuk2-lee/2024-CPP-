#include <iostream>
using namespace std;

class BaseArray {
private:
    int capacity;        // 배열의 크기
    int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    // 생성자가 protected이면 자식클래스에서 밖에 생성불가능
    // BaseArray만의 객체 생성 불가
    ~BaseArray() { delete[] mem; }
    // 자식클래스가 소멸할 때만 시행
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
    int top; // stack의 가장 높은 위치의 정보
public:
    MyStack(int capacity = 100) : BaseArray(capacity) {
        top = -1;
    }

    int is_full() {
        if (top == getCapacity() - 1) {
            return 1;
        }
        else return 0;
    } // 가장 위에있는 원소가 크기-1(마지막 index) 이면 stack은 full

    int length() {
        return top + 1;
    }
    // top은 맨 위 원소의 index이기 때문에 +1 한 값이 stack의 길이
    // ex) top == -1 이면 스택이 비어있기 때문에 길이가 +1한 0임을 알 수 있다.

    void push(int val) {
        if (!is_full()) {
            put(++top, val);
        }
    }
    // 입력이 들어왔을 때 스택에 빈공간이 있을 경우 상속받은 멤버함수로 배열에 값을 저장한다.

    int pop() {
        return get(top--);
    }
    // pop이후에는 값이 없다고 취급
    // 따라서 값을 리턴받고 최고index를 1개 낮추어 배열에 값은 존재하지만 논리적으로 접근불가

    int capacity() {
        return getCapacity();
    } // 외부함수에 수용량을 리턴합니다.
};

int main() {
    MyStack mStack(100);
    int size;
    cout << "스택에 입력할 개수 >> ";
    cin >> size;
    int n;
    cout << "스택에 삽입할 " << size << "개의 정수를 입력하라 >> ";
    for (int i = 0; i < size; i++) {
        cin >> n;
        mStack.push(n); // 스택에 푸시
    }
    cout << "스택용량 : " << mStack.capacity() << ", 스택크기: " << mStack.length() << endl;
    cout << "스택의 모든 원소를 팝하여 출력한다>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << " "; // 스택에서 팝
    }
    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
#include <iostream>
#define MAX_SIZE 100 // 스택의 최대개수 100으로 한정
using namespace std;

class Stack {
    int top; // stack의 맨위 원소 index
    int arr[MAX_SIZE]; // 값을 저장할 배열

public:
    Stack() {
        top = -1;
        for(int i = 0; i < MAX_SIZE; i++) {
            arr[i] = 0;
        } // 배열을 0으로초기화
    }

    bool operator!() {
        if (top == -1) return true;
        else return false;
        // top 즉 최고 인덱스가 -1이면 제일 첫번째 원소인 0에 값이 없음 -> stack이 비어있다
    }

    Stack& operator << (int x) {
        if(top == 99) {
            cout << "스택이 가득 참\n";
            return *this;
        }
        else arr[++top] = x;
        // 가장 높은 index를 하나 증가시키고 값을 추가
        return *this;
    } // 연속으로 push 하기위해 자기자신의 레퍼런스를 반환
    void operator >> (int& x) {
        if(top != -1) {
            x = arr[top--];
            // x에 현재 값 입력 후 가장 높은 index 하나 감소
        } // stack에 값이 존재할 때만 x
    } // pop한 정수를 대입해야 되기 때문에 레퍼런스로 값 전달
};

int main() {
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
    while (true) {
        if(!stack) break; // 스택 empty
        int x;
        stack >> x; // 스택의 탑에 있는 정수 팝
        cout << x << ' ';
    }
    cout << endl;
}
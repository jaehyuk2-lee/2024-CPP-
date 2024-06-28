#include <iostream>
using namespace std;

class MyVector {
    int* mem;
    int size;

public:
    MyVector(int n = 100, int val = 0) {
        this->size = n;
        this->mem = new int[size];
        for (int i = 0; i < size; i++) {
            this->mem[i] = val;
        }
    }
    // MyVector생성자는 매개변수가 없을시 기본으로 size = 100의 배열을 생성하고, 0의 값을 할당한다,
    // 매개변수가 입력되면, 입력받은 크기만큼 동적할당 후, 입력받은 값으로 배열의 요소들을 초기한다.

    void checkVector() {
        cout << "배열의 크기 : " << this->size << "\t 배열에 저장된 값 : " << this->mem[0] << "\n";
    }
    // 배열의 크기와, 안에 저장되어 있는 값을 확인하는 함수,
    // 배열이 초기화 될 때 모든 값이 같은 값으로 초기화 되기 때문에, 0번째 값만 출력한다.
    ~MyVector() { delete[] mem; }
};

int main() {
    MyVector arr0; // 매개변수가 없기 때문에 size 100 모든 값이 0으로 초기화 된 배열이다.
    arr0.checkVector();

    MyVector arr1(10);
    // 매개변수를 한개만 넣었기 때문에 size 10에 모든값이 0로 초기화 된 배열이다.
    // 디폴트 매개변수는 가장 오른쪽에 작성돼야하기 때문에, 매개변수가 들어오면 왼쪽 부터 적용된다. 
    arr1.checkVector();

    MyVector arr2(10, 2); // 크기의 매개변수, 값의 매개변수를 모두 넣었기 때문에 size 10에 모든 값이 2로 초기화 된 배열이다.
    arr2.checkVector();

    return 0;
}
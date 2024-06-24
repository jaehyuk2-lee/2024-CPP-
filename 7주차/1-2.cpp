#include <iostream>
using namespace std;

int arr[5] = {0};
// 3번째 배열을 디폴트 매개변수로 사용하기 위해 같은 크기 5의 요소가 0인 배열 생성, 합을 구할때 영향을 주지 않기위함
int add(int*, int, int* b = arr);
// b배열이 입력받아지지 않을 경우에는 크기 5 의 0 의 값을 가진 배열로 설정

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, 5);    // 배열 a의 정수를 모두 더한 값 리턴
    int d = add(a, 5, b); // 배열 a와 b의 정수를 모두 더한 값 리턴
    cout << c << endl;    // 15 출력
    cout << d << endl;    // 55 출력
}

int add(int* a, int size, int* b) {
    int ret = 0;
    for(int i = 0; i < size; i++) {
        ret = ret + a[i] + b[i];
    }
    return ret;
}
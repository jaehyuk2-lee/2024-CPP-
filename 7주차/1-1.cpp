#include <iostream>
using namespace std;

int add(int*, int); // 배열 1개와 정수자료가 들어올 때 사용할 함수
int add(int*, int, int*); // 배열, 정수, 배열 자료가 들어올 때 사용할 함수

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, 5);    // 배열 a의 정수를 모두 더한 값 리턴
    int d = add(a, 5, b); // 배열 a와 b의 정수를 모두 더한 값 리턴
    cout << c << endl;    // 15 출력
    cout << d << endl;    // 55 출력
}

int add(int* arr, int size) {
    int ret = 0; // 배열의 합을 저장할 변수
    for(int i = 0; i < size; i++) {
        ret += arr[i];
    }
    return ret;
}
int add(int* arr1, int size, int* arr2) {
    int ret = 0;
    for(int i = 0; i < size; i++) {
        ret = ret+arr1[i]+arr2[i];
    }
    return ret;
} // 배열이 2개 들어오면 배열 2개 모두 더한값을 저장해 리턴한다
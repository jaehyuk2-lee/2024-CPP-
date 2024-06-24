#include <iostream>
using namespace std;

template<class T> // T로 일반화된 함수를 먼저작성, 매개변수로 전달받는 배열의 타입으로 구체화
bool equalArrays(T x[], T y[], int size) {
    for(int i = 0; i < size; i++) {
        if(x[i] != y[i]) {
            return false;
        }
    }
    return true;
}
// 배열과 크기를 전달받아, 배열의 모든 값들을 비교
// 같은 위치의 값이 다르다면 false를 리턴하면 함수를 종료
// 반복문으로 배열을 전부 비교했다면, 같은 위치의 값들이 전부 같았기 때문에 true리턴

int main() {
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {1, 10, 100, 5, 4};
    cout << "int 배열 비교 결과\n";
    cout << "x: ";
    for(int i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }
    cout << "\ny: ";
    for(int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }
    cout << endl;
    // 결과 확인을 위해 비교할 배열들 출력

    if(equalArrays(x, y, 5)) cout << "같다\n"; // 배열 x, y가 같으므로 "같다" 출력
    else cout << "다르다\n";

    double z[] = {1.2, 10.3, 100.4, 5.5, 4.6};
    double w[] = {1.2, 10.3, 100.3, 5.4, 4.5};
    cout << "double 배열 비교 결과\n";
    cout << "w: ";
    for(int i = 0; i < 5; i++) {
        cout << w[i] << " ";
    }
    cout << "\nz: ";
    for(int i = 0; i < 5; i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    // 다른 자료형으로 함수가 작동하는지 확인하기 위해 double 배열 생성

    if(equalArrays(w, z, 5)) cout << "같다\n";
    else cout << "다르다\n";
}
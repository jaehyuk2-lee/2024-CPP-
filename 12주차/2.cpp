#include <iostream>
using namespace std;

template<class T>
bool search(T, T[], int);
// 제네릭함수를 먼저 선언 후 메인함수 뒤에서 구현

int main() {
    int x[] = {1, 10, 100, 5, 4};
    if(search(100, x, 5)) cout << "100이 배열 x에 포함되어 있다\n";
    else cout << "100이 배열 x에 포함되어 있지 않다\n";

    double y[] = {1.1, 1.2, 1.3, 3.14, 1.5};
    if(search(3.14, y, 5)) cout << "3.14가 배열 x에 포함되어 있다\n";
    else cout << "3.14 이 배열 x에 포함되어 있지 않다\n";
    // double로 구체화한 함수 작동
}

template<class T> // 구현부에서도 template<class T>를 작성해야 선언부와 매칭가능
bool search(T n, T x[], int size) {
    for(int i = 0; i < size; i++) {
        if(x[i] == n) return true;
    }
    return false;
}
// 배열에 저장된 값을 찾는 값이랑 비교, 반복중 값을 찾았다면 true를 리턴하며 종료
// 배열을 전부확인했다면 찾는 값이 없었다는 의미이므로, false를 리턴하며 종료
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    while (strcmp("yes", str) != 0) {
        // strcmp는 두 문자열이 같으면 0을 반환하기 때문에 yes가 아닌동안 계속 반복한다.
        cout << "종료하고 싶으면 yes를 입력하세요. >>";
        cin.getline(str, 100); // 공백문자를 포함해서 입력받기위해 getline()함수를 사용한다.
    }
    cout << "종료합니다...\n";
    return 0;
}
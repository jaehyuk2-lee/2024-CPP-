#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    while (strcmp("yes", str) != 0) {
        cout << "종료하고 싶으면 yes를 입력하세요. >>";
        cin >> str;
    }
    cout << "종료합니다...\n";
    return 0;
}
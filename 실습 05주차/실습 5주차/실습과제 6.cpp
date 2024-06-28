#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "아래에 한줄을 입력해 주세요. (exit를 입력하면 종료합니다.)\n";

    while (1) {
        cout << ">>";
        getline(cin, str); // 공백을 포함해서 문자열 입력
        if (str == "exit") break; // exit을 입력받았으면 반복종료

        for (int i = str.length() - 1; i >= 0; i--) {
            cout << str[i];
        }
        // string클래스의 length()함수를 통해 문자열의 길이를 반환받아, 문자열의 마지막 요소부터 처음까지 출력
        cout << '\n';
    }
}
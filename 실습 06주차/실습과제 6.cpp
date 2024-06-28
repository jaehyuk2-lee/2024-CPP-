#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success) {
    success = false;
    for (int i = 0; a[i]; i++) {
        if (a[i] == c) {
            success = true;
            return a[i]; // a[i] 자체가 레퍼런스로 전달된다.
        }
    }
    return a[0];
    // char의 레퍼런스가 리턴되어야 하는 함수이기 때문에 일단 제일 첫번째 문자를 리턴한다.
    // 어차피 success가 변경되어 false인 경우기 때문에 사용되지는 않는다.
}

int main() {
    char s[] = "mike";
    bool b = false;
    char& loc = find(s, 'M', b); // find에서 리턴된 a[i]를 레퍼런스로 전달되어서 loc을 변경하면 a[i] 즉 s[i]가 변경된다.
    if (b == false) {
        cout << "M을 발견할 수 없다" << endl;
        return 0;
    }
    loc = 'm';         // ‘M’ 위치에 'm' 기록
    cout << s << endl; // “mike"가 출력됨
    return 0;
}
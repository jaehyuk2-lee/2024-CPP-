#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "문지열 입력 >>";
    getline(cin, text); // text객체를 공백을 포함해서 입력받는다.

    // 1번 방법
    int cnt = 0; // 'a'가 몇개가 있는지 저장할 변수
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'a') cnt++;
    }
    // string클래스의 length함수로 문자열의 길이를 반환받아서 객체의 맨마지막 요소까지 확인
    // 만약 text객체의 i번째가 'a'라면 개수를 한개 늘린다.
    cout << "문자 a는 " << cnt << "개 있습니다." << endl;

    // 2번 방법
    cnt = 0;
    int last = 0; // 'a'를 찾은 마지막 위치를 저장할 변수
    while (1) {
        if (text.find('a', last) == string::npos) {
            break;
        } // string::npos는 찾는 문자가 없을경우 find()함수가 반환하는 값으로 쓰레기 값이다.
        else {
            last = text.find('a', last) + 1;
             cnt++;
        }
        // find함수는 찾는문자가 있는 위치를 반환하기 때문에
        // 다음에 탐색할 위치는 그 다음 index부터이다. 따라서 반환값 +1 을 저장한다.
    }
    cout << "문자 a는 " << cnt << "개 있습니다." << endl;
}
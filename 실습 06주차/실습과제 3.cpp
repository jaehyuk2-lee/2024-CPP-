#include <iostream>
#include <string>
using namespace std;


void combine1(string&, string&, string&); // 존재하는 문자열을 레퍼런스로 받는 함수
void combine2(string, string, string&); // 존재하는 문자열을 레퍼런스로 받지 않는 함수
int main() {
    string text1("I love you"), text2("very much");
    string text3; // 비어 있는 문자열
    combine1(text1, text2, text3); // text1과 “ ”, 그리고 text2를 덧붙여 text3 만들기
    cout << text3 << "\n"; // "I love you very much“ 출력

    text3.clear(); // 2번째 함수를 활용해서 덧붙이기 위해 text3를 초기화
    combine2(text1, text2, text3);
    cout << text3 << "\n";
}

void combine1(string& s1, string& s2, string& s3) {
    s3 = s1 + " " + s2; // 공백으로 s1 s2를 구분
} // 매개변수로 넘겨받은 s3는 함수내에서 값이 변경되어야하므로 무조건 레퍼런스 변수로 사용해야한다.

void combine2(string s1, string s2, string& s3) {
    s3 = s1 + " " + s2;
} // s1과 s2는 함수내에서 변경되지 않기 때문에 레퍼런스 변수를 사용하지 않아도 무관하다.
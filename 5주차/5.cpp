#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string text;

    srand(time(NULL)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정

    cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)\n";
    while(1) {
        cout << ">>";
        getline(cin, text); // text객체를 공백을 포함해서 입력받는다.
        if(text == "exit") { // string 클래스가 제공하는 비교연산자  
            break;
        } // exit를 입력받으면 종료

        if(rand()%2==0) {
            text[rand()%text.size()] = (rand()%26 + 65);
            // 난수가 짝수면 임의의 문자를 대문자로 변셩
        }
        else {
            text[rand()%text.size()] = (rand()%26 + 97);
            // 난수가 홀수면 임의의 문자를 소문자로 변경
        }
        cout << text << endl;
        // string클래스의 size()함수를 사용해 문자열의 크기를 받는다.
        // 나머지 연산을 사용해 난수는 0부터 text의 크기-1 까지의 숫자가 무작위로 결정된다.
    }
}
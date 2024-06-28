#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "문자열 입력>> ";
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) { // 입력 받은 문자열의 크기 만큼 반복한다.
        for (int j = 0; j <= i; j++) { // i번째 만큼까지 문자열을 출력한다.
            cout << str[j];
        }
        cout << endl; // n번째에 n개의 문자열 출력 후 줄 바꿈
    }

    return 0;
}
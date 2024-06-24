#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char password1[10];
    char password2[10];

    cout << "새 암호를 입력하세요 >>";
    cin >> password1;
    cout << "새 암호를 다시한번 입력하세요 >>>";
    cin >> password2;

    if(!strcmp(password1, password2)) {
        cout << "같습니다.\n";
    }
    else cout << "다릅니다.\n";

    return 0;
}
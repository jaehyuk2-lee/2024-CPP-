#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "문자들을 입력하라(100개 미만)." << '\n';
    cin.getline(str, 100);
    /* 문자열을 공백을 포함해서 입력받기 위해 getline() 함수를 사용한다.
       기본적으로 <Enter>이전까지 자료를 입력하고, cin.getline(str, 100, ';'); 
       처럼 다른 형식으로 입력을 종료할 수도 있다.*/
    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'x')
        {
            cnt++;
        }
    }
    cout << "x의 개수는 " << cnt << "\n";

    return 0;
}
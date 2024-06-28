#include <iostream>
#include <cstring> // strcmp() 함수를 사용하기위해 선언한다.
using namespace std;

int main()
{
    char password1[10];
    char password2[10];

    cout << "새 암호를 입력하세요 >>";
    cin >> password1;
    cout << "새 암호를 다시한번 입력하세요 >>>";
    cin >> password2;

    if (!strcmp(password1, password2)) {
        // strcmp는 두 함수가 같으면 0을 return하기 때문에 !을 붙여야 참이 된다.
        cout << "같습니다." << endl;
        // std namespace를 사용한다고 선언해서 줄바꿈을해주는 endl을 사용할 수 있다.
    }
    else cout << "다릅니다." << endl;

    return 0;
}
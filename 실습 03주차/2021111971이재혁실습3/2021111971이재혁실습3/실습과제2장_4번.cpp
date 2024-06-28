#include <iostream>
using namespace std;

int main()
{
    float arr[5]; // 5개의 변수가 저장 될 공간
    cout << "5개의 실수를 입력해라>>";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    /* cin은 공백이전까지 자료를 입력하기 때문에
    반복으로 5개의 실수를 공백으로 입력받을 수 있다.*/

    float max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "제일 큰 수 = " << max << "\n";
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    float arr[5];
    cout << "5개의 실수를 입력해라>>";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    float max = arr[0];
    for(int i = 1; i < 5; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "제일 큰 수 = " << max << "\n";
    return 0;
}
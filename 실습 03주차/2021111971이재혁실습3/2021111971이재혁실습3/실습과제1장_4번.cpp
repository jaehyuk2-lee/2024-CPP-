#include <iostream>
using namespace std;
// std namespace사용을 선언해 cout에 std::를 붙이지 않고 사용할 수 있다.
// 본 코드에서는 cout만 사용하고 있기 때문에 using std::cout;으로 대체할 수 있다.
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
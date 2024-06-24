#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    if(num1 > num2) {
        cout << "큰수 = " << num1 << "\n";
    }
    else cout << "큰수 = " << num2 << "\n";

    return 0;
}
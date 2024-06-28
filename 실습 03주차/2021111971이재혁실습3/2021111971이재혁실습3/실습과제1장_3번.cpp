#include <iostream>

int main() {
    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "1부터 10 까지 더한값은 55입니다.\n";
    std::cout << "결과는 " << sum << "입니다. \n";
    // std namepsace내부의 cout 객체를 통해 문자열과 변수내의 값을 출력한다.

    return 0;
}
#include <iostream>

int main() {
    int sum = 0;

    for(int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "1부터 10 까지 더한값은 " << 55 << "입니다.\n";
    std::cout << "결과는 " << sum << "입니다. \n";

    return 0;
}
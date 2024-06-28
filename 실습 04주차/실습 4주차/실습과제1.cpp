// 2024.03.28
#include <iostream>
using namespace std;

class Tower {
public:
    Tower() { // 매개변수가 없을 때는 기본 1로 설정
        height = 1;
    }
    Tower(int h) { // int형 매개변수가 있을 때 그 값으로 설정
        height = h;
    }
    int getHeight(); // height 변수는 class외부에서 접근할 수 없기 때문에, method를 통해 return;
private:
    int height;
}; // 높이 값을 가지는 Tower class

int Tower::getHeight() {
    return height;
}

int main() {
    Tower myTower;
    Tower seoulTower(100);
    cout << "높이는 " << myTower.getHeight() << "미터" << endl;
    cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
#include <iostream>
using namespace std;
// std namespace����� ������ cout�� std::�� ������ �ʰ� ����� �� �ִ�.
// �� �ڵ忡���� cout�� ����ϰ� �ֱ� ������ using std::cout;���� ��ü�� �� �ִ�.
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
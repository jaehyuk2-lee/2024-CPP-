#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    Account(string n, int i, int b) {
        name = n;
        id = i;
        balance = b;
    }
    void deposit(int a) {
        balance += a;
    }
    int withdraw(int b) {
        balance -= b;
        return b;
    } // 현재 저금된 잔액에서 b원만큼을 제외하고 b원 출금
    string getOwner() {
        return name;
    }
    int inquiry() {
        return balance;
    }
private:
    string name;
    int id;
    int balance;
};

int main() {
    Account a("kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
    a.deposit(50000);            // 50000원 저금
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
    int money = a.withdraw(20000); // 20000원 출금. withdraw()는 출금한 실제 금액 리턴
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}
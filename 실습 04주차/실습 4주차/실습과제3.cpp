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
    } // ���� ���ݵ� �ܾ׿��� b����ŭ�� �����ϰ� b�� ���
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
    Account a("kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
    a.deposit(50000);            // 50000�� ����
    cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
    int money = a.withdraw(20000); // 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
    cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}
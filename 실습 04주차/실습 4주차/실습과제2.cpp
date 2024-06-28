#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    Date(string s) {
        year = stoi(s.substr(0, 4));  // s[0] ���� 4���� ���� ���ڿ��� return �� int�� ��ȯ
        month = stoi(s.substr(5, 1)); // s[5] ���� 1���� ���� ���ڿ��� return �� int�� ��ȯ
        day = stoi(s.substr(7));      // s[7] ���� ������ ���ڿ��� return �� int�� ��ȯ
    }

    void show() {
        cout << year << "��" << month << "��" << day << "��" << endl;
    } // class�� ������ �ִ� ������ ���

    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    // �� �� �� �� ��ȯ�ϴ� �Լ���

private:
    int year, month, day;
};

int main() {
    Date birth(2014, 03, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;
}
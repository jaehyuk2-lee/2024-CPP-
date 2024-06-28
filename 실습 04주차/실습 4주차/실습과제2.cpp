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
        year = stoi(s.substr(0, 4));  // s[0] 부터 4개의 값을 문자열로 return 후 int로 변환
        month = stoi(s.substr(5, 1)); // s[5] 부터 1개의 값을 문자열로 return 후 int로 변환
        day = stoi(s.substr(7));      // s[7] 부터 끝까지 문자열로 return 후 int로 변환
    }

    void show() {
        cout << year << "년" << month << "월" << day << "일" << endl;
    } // class가 가지고 있는 값들을 출력

    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    // 년 원 일 을 반환하는 함수들

private:
    int year, month, day;
};

int main() {
    Date birth(2014, 03, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;
}
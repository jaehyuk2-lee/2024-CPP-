#include <iostream>
#include <string> // 문자열을 입력받는 getline()함수를 사용하기위해 선언한다.
using namespace std;

int main()
{
    string name;
    string address;
    int age;

    cout << "이름은?";
    getline(cin, name); // string자료형 name에 들어갈 값을 입력받는다, 공백포함이 가능하다.
    cout << "주소는?";
    getline(cin, address);
    cout << "나이는?";
    cin >> age;

    cout << name << ", " << address << ", " << age << "세\n";

    return 0;
}
#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string text;

    srand(time(NULL)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����

    cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�)\n";
    while (1) {
        cout << ">>";
        getline(cin, text); // text��ü�� ������ �����ؼ� �Է¹޴´�.
        if (text == "exit") { // string Ŭ������ �����ϴ� �񱳿�����  
            break;
        } // exit�� �Է¹����� ����

        if (rand() % 2 == 0) {
            text[rand() % text.size()] = (rand() % 26 + 65);
            // ������ ¦���� ������ ���ڸ� �빮�ڷ� ����
        }
        else {
            text[rand() % text.size()] = (rand() % 26 + 97);
            // ������ Ȧ���� ������ ���ڸ� �ҹ��ڷ� ����
        }
        cout << text << endl;
        // stringŬ������ size()�Լ��� ����� ���ڿ��� ũ�⸦ �޴´�.
        // ������ ������ ����� ������ 0���� text�� ũ��-1 ������ ���ڰ� �������� �����ȴ�.
    }
}
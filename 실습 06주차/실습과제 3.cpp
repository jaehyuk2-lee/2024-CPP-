#include <iostream>
#include <string>
using namespace std;


void combine1(string&, string&, string&); // �����ϴ� ���ڿ��� ���۷����� �޴� �Լ�
void combine2(string, string, string&); // �����ϴ� ���ڿ��� ���۷����� ���� �ʴ� �Լ�
int main() {
    string text1("I love you"), text2("very much");
    string text3; // ��� �ִ� ���ڿ�
    combine1(text1, text2, text3); // text1�� �� ��, �׸��� text2�� ���ٿ� text3 �����
    cout << text3 << "\n"; // "I love you very much�� ���

    text3.clear(); // 2��° �Լ��� Ȱ���ؼ� �����̱� ���� text3�� �ʱ�ȭ
    combine2(text1, text2, text3);
    cout << text3 << "\n";
}

void combine1(string& s1, string& s2, string& s3) {
    s3 = s1 + " " + s2; // �������� s1 s2�� ����
} // �Ű������� �Ѱܹ��� s3�� �Լ������� ���� ����Ǿ���ϹǷ� ������ ���۷��� ������ ����ؾ��Ѵ�.

void combine2(string s1, string s2, string& s3) {
    s3 = s1 + " " + s2;
} // s1�� s2�� �Լ������� ������� �ʱ� ������ ���۷��� ������ ������� �ʾƵ� �����ϴ�.
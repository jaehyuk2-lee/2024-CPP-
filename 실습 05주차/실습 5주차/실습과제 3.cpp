#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "������ �Է� >>";
    getline(cin, text); // text��ü�� ������ �����ؼ� �Է¹޴´�.

    // 1�� ���
    int cnt = 0; // 'a'�� ��� �ִ��� ������ ����
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'a') cnt++;
    }
    // stringŬ������ length�Լ��� ���ڿ��� ���̸� ��ȯ�޾Ƽ� ��ü�� �Ǹ����� ��ұ��� Ȯ��
    // ���� text��ü�� i��°�� 'a'��� ������ �Ѱ� �ø���.
    cout << "���� a�� " << cnt << "�� �ֽ��ϴ�." << endl;

    // 2�� ���
    cnt = 0;
    int last = 0; // 'a'�� ã�� ������ ��ġ�� ������ ����
    while (1) {
        if (text.find('a', last) == string::npos) {
            break;
        } // string::npos�� ã�� ���ڰ� ������� find()�Լ��� ��ȯ�ϴ� ������ ������ ���̴�.
        else {
            last = text.find('a', last) + 1;
             cnt++;
        }
        // find�Լ��� ã�¹��ڰ� �ִ� ��ġ�� ��ȯ�ϱ� ������
        // ������ Ž���� ��ġ�� �� ���� index�����̴�. ���� ��ȯ�� +1 �� �����Ѵ�.
    }
    cout << "���� a�� " << cnt << "�� �ֽ��ϴ�." << endl;
}
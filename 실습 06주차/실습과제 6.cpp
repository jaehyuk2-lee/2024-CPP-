#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success) {
    success = false;
    for (int i = 0; a[i]; i++) {
        if (a[i] == c) {
            success = true;
            return a[i]; // a[i] ��ü�� ���۷����� ���޵ȴ�.
        }
    }
    return a[0];
    // char�� ���۷����� ���ϵǾ�� �ϴ� �Լ��̱� ������ �ϴ� ���� ù��° ���ڸ� �����Ѵ�.
    // ������ success�� ����Ǿ� false�� ���� ������ �������� �ʴ´�.
}

int main() {
    char s[] = "mike";
    bool b = false;
    char& loc = find(s, 'M', b); // find���� ���ϵ� a[i]�� ���۷����� ���޵Ǿ loc�� �����ϸ� a[i] �� s[i]�� ����ȴ�.
    if (b == false) {
        cout << "M�� �߰��� �� ����" << endl;
        return 0;
    }
    loc = 'm';         // ��M�� ��ġ�� 'm' ���
    cout << s << endl; // ��mike"�� ��µ�
    return 0;
}
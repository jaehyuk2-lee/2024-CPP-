#include <iostream>
#include <cstring> // strcmp() �Լ��� ����ϱ����� �����Ѵ�.
using namespace std;

int main()
{
    char password1[10];
    char password2[10];

    cout << "�� ��ȣ�� �Է��ϼ��� >>";
    cin >> password1;
    cout << "�� ��ȣ�� �ٽ��ѹ� �Է��ϼ��� >>>";
    cin >> password2;

    if (!strcmp(password1, password2)) {
        // strcmp�� �� �Լ��� ������ 0�� return�ϱ� ������ !�� �ٿ��� ���� �ȴ�.
        cout << "�����ϴ�." << endl;
        // std namespace�� ����Ѵٰ� �����ؼ� �ٹٲ������ִ� endl�� ����� �� �ִ�.
    }
    else cout << "�ٸ��ϴ�." << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "���ڵ��� �Է��϶�(100�� �̸�)." << '\n';
    cin.getline(str, 100);
    /* ���ڿ��� ������ �����ؼ� �Է¹ޱ� ���� getline() �Լ��� ����Ѵ�.
       �⺻������ <Enter>�������� �ڷḦ �Է��ϰ�, cin.getline(str, 100, ';'); 
       ó�� �ٸ� �������� �Է��� ������ ���� �ִ�.*/
    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'x')
        {
            cnt++;
        }
    }
    cout << "x�� ������ " << cnt << "\n";

    return 0;
}
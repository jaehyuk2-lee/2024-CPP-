#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);

    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'x')
        {
            cnt++;
        }
    }
    cout << "x의 개수는 " << cnt << "\n";

    return 0;
}
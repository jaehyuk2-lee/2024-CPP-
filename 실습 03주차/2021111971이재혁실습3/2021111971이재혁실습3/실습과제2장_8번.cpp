#include <iostream>
#include <cstring> // strlen() 함수 사용을 위해 선언한다.
using namespace std;

int main()
{
    char name[5][100]; // 최대길이가 99인 문자열 5개를 생성한다.
    cout << "5명의 이름을 ; 으로 구분하여 입력하세요\n>>";

    for (int i = 0; i < 5; i++) {
        cin.getline(name[i], 100, ';');
    } // ';'을 추가로 작성해주어 ';'이 입력되었을 때 그 이전까지의 자료를 입력한다.

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " : " << name[i] << "\n";
    }
    int max = strlen(name[0]); // 최댓값을 처음 입력받은 문자열의 길이로 설정한다.
    int max_index = 0;
    for (int i = 1; i < 5; i++) {
        // name[0]의 길이가 최댓값으로 설정되어 있으므로 name[1]부터 길이를 비교한다.
        if (strlen(name[i]) > max) {
            max = strlen(name[i]); // 최대길이를 최신화 해준다.
            max_index = i; // 가장 긴 이름이 저장되어있는 index를 저장한다.
        }
    }

    cout << "가장 긴 이름은 " << name[max_index] << "\n";
    return 0;
}
//Mozart;Elvis Presley;Jim Carry;Schubert;Dominggo;
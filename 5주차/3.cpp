#include <iostream>
#include <string>
#define MAX_SIZE 101 // 문자열을 저장하는 최대길이를 100으로 설정
using namespace std;

class String {
public:
    int* arr;
    // 입력받는 문자열이 존재하는 index정보를 저장할 배열 생성
    // 값이 객체가 소멸할때 까지 존재하는지 확인하기 위해 public 접근지정자로 사용

    String() {
        cout << "문자열 입력 >> ";
        cin.getline(str, 100);
        size = strlen(str); // 입력받은 문자열의 크기 저장
    } // 생성자에 문자열 입력을 구현해 객체가 생성될 때 사용자의 입력을 받아 문자열 초기화

    int* find(char c, int index) {
        arr = new int[size+1];
        // 입력받은 문자열이 모두 찾고자하는 문자일수 있기 때문에 문자열의 크기만큼 (NULL까지 1개더) 동적할당
        // 입력받은 문자열이 바뀌는 경우는 고려하지 않음

        int cnt = 0; // 문자열내에 몇개가 들어있는지 출력할 변수 생성
        for(int i = index; str[i]; i++) { // str[i]에 값이 있을동안 반복
            if(str[i] == c) {
                arr[cnt++] = i;
                // 현재 cnt번째에 들어오는 값은 cnt-1 인덱스에 저장되기 때문에 cnt에 현재 문자열의 인덱스 번호를 입력
            }
        }
        cout << "문자 " << c << "는 " << cnt << "개 있습니다." << endl;

        return arr; // 입력받은 문자가 존재하는 인덱스 정보를 리턴
    }

    ~String() {
        delete[] arr;
        // 사용한 arr배열을 해제
    }
    


private:
    char str[MAX_SIZE]; // 문자열을 저장할 배열설정
    int size; // 문자열의 정보를 저장할 배열
};

int main() {
    String text;
    int* index_info; // 리턴받은 인덱스 위치정보 기억하는 포인터

    index_info = text.find('a', 0);
    for(int i = 0; index_info[i]; i++) {
        cout << index_info[i] << " ";
    }
    cout << endl;

    index_info = text.find('a', 14);
    for(int i = 0; index_info[i]; i++) {
        cout << index_info[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; text.arr[i]; i++) {
        cout << index_info[i] << " ";
    }
    cout << endl; // 가장 마지막에 시행한 find() 작업의 index정보가 남아있는지 확인
}
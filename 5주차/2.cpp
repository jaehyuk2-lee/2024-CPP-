#include <iostream>
using namespace std;

int main() {
    int* arr;
    arr = new int[5]; // arr에 사이즈 5의 배열 동적할당
    cout << "정수 5개 입력 >> ";

    for(int i = 0; i < 5; i++) {
        cin >> arr[i]; 
    } // arr에 정수 값 입력

    double average = 0; // 평균값을 저장할 변수 선언
    for(int i = 0; i < 5; i++) {
        average += arr[i]; // arr의 i번째의 값을 계속 더하기
    }
    average /= 5; // 다더해진 값을 더한 개수로 나눠 평균값을 저장

    cout << fixed; // 출력시 소수점 자리수를 고정하기
    cout.precision(1); // 출력시 소수자리수 고정을 1자리로 설정

    cout << "평균 " << average << endl;
    delete[] arr; // 사용한 메모리 해제
}
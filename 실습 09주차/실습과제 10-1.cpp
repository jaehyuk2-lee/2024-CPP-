#include <iostream>
using namespace std;

class Statistics {
    int* arr;
    int size; // 집계된 데이터의 개수를 저장할 멤버변수
public:
    Statistics() {
        size = 0;
        arr = NULL;
    }
    ~Statistics() {
        if (arr) delete[] arr;
        // arr에 할당된 메모리가 있을 때만 동적할당 해제
        // 할당된 메모리가 없을 때 delete시 오류발생
    }

    bool operator!() {
        if (size == 0) {
            return true;
        }
        else return false;
    } // 통계데이터가 존재하면 size는 0보다 크다. 따라서 size가 0일 때 true출력

    Statistics& operator << (int x) {
        // 자기자신의 레퍼런스를 반환해  << 연산을 연속으로 수행
        if (size == 0) {
            size++;
            arr = new int[size];
            arr[0] = x;
        } // 입력받은 데이터가 없었다면 새로운 메모리할당
        else {
            size++;
            int* tmp = new int[size];
            // 전달받을 값까지 저장할수 있는 임시배열 동적할당
            for (int i = 0; i < size - 1; i++) {
                tmp[i] = arr[i];
            } // 이전까지 저장되어 있던 값을 임시로 복사
            tmp[size - 1] = x;
            // 새로 전달받은 값을 저장

            delete[] arr;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = tmp[i];
            }
            // 증가한 사이즈로 배열을 다시 동적할당해 저장해 뒀던 값 복사
            delete[] tmp;
            // 생성했던 임시배열 동적할당 해제
        }
        return *this; // 현재 객체 반환
    }
    void operator~ () {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void operator>> (int& a) {
        int avg = 0;
        for (int i = 0; i < size; i++) {
            avg += arr[i];
        }
        avg /= size;
        // arr의 모든 값을 더해서 size나누어 평균을 계산
        a = avg; // 계산한 값을 레퍼런스에 대입
    }
};

int main() {
    Statistics stat;
    if (!stat) cout << "현재 통계 데이터가 없습니다\n";

    int x[5];
    cout << "5개의 정수를 입력해라>> ";
    for (int i = 0; i < 5; i++) {
        cin >> x[i];
    } // x[i]에 정수입력

    for (int i = 0; i < 5; i++) {
        stat << x[i];
    } // x[i]의 값을 통계 객체에 삽입
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg; // avg에 값을 대입해야하기 때문에 레퍼런스로 전달해 값 수정
    cout << "avg = " << avg << endl;
}
#include <iostream>
using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
    retSize = sizeSrc - sizeMinus;
    int index[sizeMinus];
    // src배열에서 삭제할 원소의 위치를 저장하는 배열, 삭제할 배열의 크기보다 클 수 없음
    int k = 0; // 배열에 저장할 index
    for(int i = 0; i < sizeMinus; i++) {
        for(int j = 0; j < sizeSrc; j++) {
            if(src[j] == minus[i]) {
                index[k] = j;
                k++;
            }
        }
    }
    // 결과 배열을 생성할 때 src배열의 삭제할 위치는 건너뛰고 값을 저장
    // 삭제할 위치정보를 저장하기 위해 src배열에서 minus배열의 값을 가지고 있는 index를 저장

    for(int i = 0; i < k; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < sizeMinus-1; i++) {
        int min_index = i;
        for(int j = i; j < sizeMinus; j++) {
            if(index[min_index] > index[j]) {
                min_index = j;
            }
        }
        int tmp = index[i];
        index[i] = index[min_index];
        index[min_index] = tmp;
    }
    // minus배열이 정렬여부를 확인할 수 없음,
    // 삭제해야 하는 원소위치가 오름차순이 아닐 수 있음,
    // 리턴할 배열에 순차적으로 값을 집어 넣기 때문에, 비교를 위해 생략핧 index도 오름차순으로 정렬(선택정렬)

    for(int i = 0; i < k; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    T* ret = new T[retSize];
    k = 0; // 선언해 두었던 k재사용, 생략할 index를 확인했으면 다음 생략 index로 진행
    int j = 0;
    for(int i = 0; i < sizeSrc; i++) {
        if(i == index[k]) {
            k++;
        }
        else {
            ret[j] = src[i];
            j++;
        }
    }

    return ret;
}
// 제네릭 함수로 코드작성, 구체화 된 배열을 리턴해야되기 때문에 T*를 리턴
// 배열에 저장된 값이 T이기 떄문에, 배열의 사이즈는 int를 그대로 사용한다.

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int minus[5] = {3, 1, 4, 2, 5};
    int retSize = 0;
    int* deleted = remove(arr, 10, minus, 5, retSize);

    for(int i = 0; i < retSize; i++) {
        cout << deleted[i] << " ";
    }
}
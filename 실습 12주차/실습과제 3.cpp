#include <iostream>
using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
    int* index = new int[sizeMinus];
    // src�迭���� ������ ������ ��ġ�� �����ϴ� �迭, ������ �迭�� ũ�⺸�� Ŭ �� ����

    int k = 0; // �迭�� ������ index
    for (int i = 0; i < sizeMinus; i++) {
        for (int j = 0; j < sizeSrc; j++) {
            if (src[j] == minus[i]) {
                index[k] = j;
                k++;
            }
        }
    }
    // ��� �迭�� ������ �� src�迭�� ������ ��ġ�� �ǳʶٰ� ���� ����
    // ������ ��ġ������ �����ϱ� ���� src�迭���� minus�迭�� ���� ������ �ִ� index�� ����
    // k���� ���� index�� ������ִ� ���� �� �� �ִ�.

    cout << "������ �ڷ��� index\n";
    for (int i = 0; i < k; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < k-1; i++) { // ������ ���� ����(k) ��ŭ�� ��
        int min_index = i;
        for (int j = i; j < k; j++) {
            if (index[min_index] > index[j]) {
                min_index = j;
            }
        }
        int tmp = index[i];
        index[i] = index[min_index];
        index[min_index] = tmp;
    }
    // minus�迭�� ���Ŀ��θ� Ȯ���� �� ����,
    // �����ؾ� �ϴ� ������ġ�� ���������� �ƴ� �� ����,
    // ������ �迭�� ���������� ���� ���� �ֱ� ������, �񱳸� ���� �����C index�� ������������ ����(��������)

    cout << "���ĵ� ������ �ڷ��� index\n";
    for (int i = 0; i < k; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    retSize = sizeSrc; // Ư�����Ҹ� ������ �迭�� ũ���, ���� �迭�� ũ�⺸�� Ŭ �� ����
    T* ret = new T[retSize];
    k = 0; // ������ �ξ��� k����, ������ index�� Ȯ�������� ���� ���� index�� ����
    int j = 0;
    for (int i = 0; i < sizeSrc; i++) {
        if (i == index[k]) {
            k++;
        }
        else {
            ret[j] = src[i];
            j++;
            retSize--;
        }
    }

    delete[] index;
    return ret;
}
// ���׸� �Լ��� �ڵ��ۼ�, ��üȭ �� �迭�� �����ؾߵǱ� ������ T*�� ����
// �迭�� ����� ���� T�̱� ������, �迭�� ������� int�� �״�� ����Ѵ�.

int main() {
    int arr[10] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4 };
    int minus[6] = { 3, 1, 7, 2, 9, 100 };
    int retSize = 0;
    cout << "���� �迭\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "���� �� �ڷḦ ������ �迭\n";
    for (int i = 0; i < 6; i++) {
        cout << minus[i] << " ";
    }
    cout << endl;

    int* deleted = remove(arr, 10, minus, 6, retSize);
    
    cout << "���� �� �迭\n";
    for (int i = 0; i < retSize; i++) {
        cout << deleted[i] << " ";
    }
}
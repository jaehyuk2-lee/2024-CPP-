#include <iostream>
using namespace std;

class Statistics {
    int* arr;
    int size; // ����� �������� ������ ������ �������
public:
    Statistics() {
        size = 0;
        arr = NULL;
    }
    ~Statistics() {
        if (arr) delete[] arr;
        // arr�� �Ҵ�� �޸𸮰� ���� ���� �����Ҵ� ����
        // �Ҵ�� �޸𸮰� ���� �� delete�� �����߻�
    }

    bool operator!() {
        if (size == 0) {
            return true;
        }
        else return false;
    } // ��赥���Ͱ� �����ϸ� size�� 0���� ũ��. ���� size�� 0�� �� true���

    Statistics& operator << (int x) {
        // �ڱ��ڽ��� ���۷����� ��ȯ��  << ������ �������� ����
        if (size == 0) {
            size++;
            arr = new int[size];
            arr[0] = x;
        } // �Է¹��� �����Ͱ� �����ٸ� ���ο� �޸��Ҵ�
        else {
            size++;
            int* tmp = new int[size];
            // ���޹��� ������ �����Ҽ� �ִ� �ӽù迭 �����Ҵ�
            for (int i = 0; i < size - 1; i++) {
                tmp[i] = arr[i];
            } // �������� ����Ǿ� �ִ� ���� �ӽ÷� ����
            tmp[size - 1] = x;
            // ���� ���޹��� ���� ����

            delete[] arr;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = tmp[i];
            }
            // ������ ������� �迭�� �ٽ� �����Ҵ��� ������ �״� �� ����
            delete[] tmp;
            // �����ߴ� �ӽù迭 �����Ҵ� ����
        }
        return *this; // ���� ��ü ��ȯ
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
        // arr�� ��� ���� ���ؼ� size������ ����� ���
        a = avg; // ����� ���� ���۷����� ����
    }
};

int main() {
    Statistics stat;
    if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�\n";

    int x[5];
    cout << "5���� ������ �Է��ض�>> ";
    for (int i = 0; i < 5; i++) {
        cin >> x[i];
    } // x[i]�� �����Է�

    for (int i = 0; i < 5; i++) {
        stat << x[i];
    } // x[i]�� ���� ��� ��ü�� ����
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg; // avg�� ���� �����ؾ��ϱ� ������ ���۷����� ������ �� ����
    cout << "avg = " << avg << endl;
}
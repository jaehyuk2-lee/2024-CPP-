// ���� ����� �� �Ź� �迭�� �����Ҵ��ϰ� �����ϴ� ���� ���ŷο� ���� ������ �����ִ� vector�� ����� �ٽ� ����
// vector�� push������� �ս��� ������ �߰� ������ ����
#include <iostream>
#include <vector>
using namespace std;

class Statistics {
    vector<int> v;
public:
    bool operator!() {
        if (v.size() == 0) {
            return true;
        }
        else return false;
    } // v.size() -> ���Ϳ� ����� ���� ���� ��ȯ

    Statistics& operator << (int x) {
        v.push_back(x);
        return *this;
    }
    // push_back()���� �ڵ����� �迭�� ���� �ڿ� ���� �߰�
    // vector�� ����� �ڵ��� ���̸� ����ȭ

    void operator~() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        } // ���ʹ� �迭������� index�� ���ٰ���
        cout << endl;
    }

    void operator>> (int& a) {
        int avg = 0;
        for (int i = 0; i < v.size(); i++) {
            avg += v[i];
        }
        avg /= v.size();
        a = avg;
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
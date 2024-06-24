// 값을 계산할 때 매번 배열을 동적할당하고 해제하는 것이 번거로워 과제 문제에 나와있던 vector를 사용해 다시 구현
// vector의 push기능으로 손쉽게 데이터 추가 삭제가 가능
#include <iostream>
#include <vector>
using namespace std;

class Statistics {
    vector<int> v;
public:
    bool operator!() {
        if(v.size() == 0) {
            return true;
        }
        else return false;
    } // v.size() -> 벡터에 저장된 값의 개수 반환

    Statistics& operator << (int x) {
        v.push_back(x);
        return *this;
    }
    // push_back()으로 자동으로 배열의 가장 뒤에 원소 추가
    // vector를 사용해 코드의 길이를 간소화

    void operator~() {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        } // 벡터는 배열기반으로 index로 접근가능
        cout << endl;
    }

    void operator>> (int& a) {
        int avg = 0;
        for(int i = 0; i < v.size(); i++) {
            avg+=v[i];
        }
        avg/=v.size();
        a = avg;
    }
};

int main() {
    Statistics stat;
    if(!stat) cout << "현재 통계 데이터가 없습니다\n";

    int x[5];
    cout << "5개의 정수를 입력해라>> ";
    for(int i = 0; i < 5; i++) {
        cin >> x[i];
    } // x[i]에 정수입력

    for(int i = 0; i < 5; i++) {
        stat << x[i];
    } // x[i]의 값을 통계 객체에 삽입
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg; // avg에 값을 대입해야하기 때문에 레퍼런스로 전달해 값 수정
    cout << "avg = " << avg << endl; 
}
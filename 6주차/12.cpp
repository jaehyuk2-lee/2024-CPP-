#include <iostream>
using namespace std;

class Dept {
    int size;    // Scores 배열의 크기
    int *scores; // 동적 할당 받을 정수 배열의 주소
public:
    Dept(int size) { // 생성자
        this->size = size;
        scores = new int[size];
    }

    Dept(const Dept &dept) {
        if(this->scores) {
            delete[] scores;
        }
        scores = new int[dept.size];
        for(int i = 0; dept.scores[i]; i++) {
            this->scores[i] = dept.scores[i];
        }
        this->size = dept.size;
    } // 복사 생성자

    ~Dept() {
        delete[] scores;
    } // 소멸자
    int getSize() { return size; }

    void read() {
        cout << "10개 점수 입력 >> ";
        for(int i = 0; i < size; i++) {
            cin >> scores[i];
        }
    } // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
    bool isOver60(int index) {
        if(scores[index] > 60) {
            return true;
        }
        else return false;
    } // index의 학생의 성적이 60보다 크면 true 리턴
};

int countPass(Dept& dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i))
            count++;
    }
    return count;
}

int main() {
    Dept com(10);           // 총 10명이 있는 학과 com
    com.read();             // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
    int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
    cout << "60점 이상은 " << n << "명\n";
}

// 2) 위 코드의 countPass함수에서 객체를 매개변수로 넘길 때, call by value 형식으로 작동한다. 따라서 countPass에서 
//    새로운 객체가 만들어지고 이때 기본복사생성자가 생성되는데 함수작동 후 종료시 scores배열일 delete된다. 
//    그 후 메인함수가 종료될 때 com객체가 scores를 delete해야하는데 이미 countPass에서 배열일 delete되어 해제할 메모리가 없다.
//    따라서 컴파일 이후 프로그램종료시 얕은복사로인한 오류가 발생한다.

// 3) countPass에서 call by value로 인한 오류였기 때문에 Debt뒤에 &를 추가해 call by reference 형식으로 수정하면
//    간단하게 오류를 수정할 수 있다.
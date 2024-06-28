#include <iostream>
#include <string>
using namespace std;

class Printer {
    string model, manufactor;
    // 프린터의 모델명, 제조사
    int papers;
    // 종이의 잔량
protected:
    Printer(string model, string manufactor, int papers) {
        this->model = model;
        this->manufactor = manufactor;
        this->papers = papers;
    }
    // 전달받은 매개변수로 모델명, 제조사, 종이잔량 설정
    // 자식클래스를 활용하기 위한 클래스로 매개변수를 자식클래스에서 전달받는다.
    // 자식클래스에서 디폴트 매개변수 생성자를 선언하기 때문에, 굳이 매개변수 생성자를 사용할 필요가 없다.

    string getModel() {
        return model;
    }
    string getManufactor() {
        return manufactor;
    }
    // 모델명, 제조사 정보리턴 

    void Print(int papers) {
        this->papers -= papers;
    } // 전달받은 매수만큼 프린트

    int availableCount() {
        return papers;
    } // 현재 인쇄가능한 페이지 수 리턴
    // 부모클래스의 생성자를 포함한 기능들을 protected로 지정
    // Printer만의 객체는 사용하지 않고 자식클래스로 기능이 있는 객체들만 사용
};
// 모든 프린터 포함내용(변수): 모델명, 제조사, 인쇄 종이 잔량
// 모든 프린터 작동(함수) : 출력(인쇄량), 현재 인쇄 가능한 매수 확인

class InkJetPrinter : public Printer {
    int ink; // 잉크 잔량 변수
public:
    InkJetPrinter(string model = "", string manufactor = "", int pages = 0, int ink = 0) : Printer(model, manufactor, pages) {
        this->ink = ink;
        // 이름, 제조사, 용지량은 부모클래스의 생성자에서 입력
    }
    int availableInk() {
        return ink;
    } // 잉크 잔량 리턴

    void printInkJet(int pages) {
        if (availableCount() < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다.\n";
        } // 인쇄량이 남은 용지보다 많으면, 용지 부족 (용지 우선 확인)
        else if (availableInk() < pages) {
            cout << "잉크가 부족하여 프린트할 수 없습니다.\n";
        } // 인쇄량이 남은 잉크보다 많으면, 잉크 부족
        else {
            ink -= pages;
            Print(pages);
            // 현재 잉크 잔량 인쇄 매수 만큼 출력
            // 현재 용지 잔량 인쇄 매수 만큼 출력
            cout << "프린트 하였습니다\n";
        }
    }

    void showInfo() {
        cout << "잉크젯: " << getModel() << ", " << getManufactor() << ", 남은 종이 " << availableCount() << "장, 남은잉크 " << availableInk() << endl;
    }
    // 현재 프린터의 정보 출력
};


class LaserPrinter : public Printer {
    int toner; // 토너 잔량 정보
public:
    LaserPrinter(string model = "", string manufactor = "", int papers = 0, int toner = 0) : Printer(model, manufactor, papers) {
        this->toner = toner;
        // 이름, 제조사, 용지량은 부모클래스의 생성자에서 입력
    }

    int availableToner() {
        return toner;
    } // 토너 잔량정보 리턴

    void printLaser(int pages) {
        if (availableCount() < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다.\n";
        } // 인쇄량이 남은 용지보다 많으면, 용지 부족 (용지 우선 확인)
        else if (availableToner() < pages) {
            cout << "토너가 부족하여 프린트할 수 없습니다.\n";
        } // 인쇄량이 남은 토너보다 많으면, 토너 부족
        else {
            toner -= pages;
            Print(pages);
            // 현재 토너 잔량 인쇄 매수 만큼 출력
            // 현재 용지 잔량 인쇄 매수 만큼 출력
            cout << "프린트 하였습니다\n";
        }
    }
    void showInfo() {
        cout << "레이저: " << getModel() << ", " << getManufactor() << ", 남은 종이 " << availableCount() << "장, 남은토너 " << availableToner() << endl;
    }
    // 현재 프린터의 정보 출력
};

int main() {
    InkJetPrinter* i = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* l = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
    // 잉크젯 프린터, 레이저 프린터 동적 생성

    cout << "현재 작동중인 2 대의 프린터는 아래와 같다.\n";
    i->showInfo();
    l->showInfo();

    char command = '\0';
    int type, pages;
    while (command != 'n') { // 입력받은 command가 n이 아닐동안 계속 반복
        cout << "\n프린터(1: 잉크젯, 2: 레이저)와 매수 입력 >> ";
        cin >> type >> pages;
        switch (type) {
        case 1:
            i->printInkJet(pages);
            break;
        case 2:
            l->printLaser(pages);
            break;
        default:
            break;
        }
        // 프린터 선택 타입에 따라 다른 프린터 사용

        i->showInfo();
        l->showInfo();
        // 프린트 이후 남은 프린터 정보 출력

        cout << "계속 프린트 하시겠습니까?(y/n) >> ";
        cin >> command;
        while (command != 'y' && command != 'n') {
            cout << "잘못된 입력입니다\n";
            cout << "계속 프린트 하시겠습니까?(y/n) >> ";
            cin >> command;
        } // 입력이 y, n이 아니면 다시 입력받기
    }

    delete i;
    delete l;
    // 동적생성한 객체 메모리 해제
}
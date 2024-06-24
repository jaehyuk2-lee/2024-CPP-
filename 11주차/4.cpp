#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual string draw() = 0;
    Shape* link;
    int id;
};
// 추상클래스로, 상속받은 클래스들은 draw()함수가 자신의 형태를 string으로 리턴한다.
// 자신의 다음에 연결된 객체를 가리킬 포인터
// 자신의 자식클래스를 가리키게 되면, 업캐스팅 발생
// 가상함수로 인해 오버라이딩이 발생, 따라서 자식클래스의 draw()함수가 실행

class Line : public Shape {
public:
    string draw() override {
        return "Line";
    }
};

class Circle : public Shape {
public:
    string draw() override {
        return "Circle";
    }
};

class Rect : public Shape {
public:
    string draw() override {
        return "Rect";
    }
};

class UI {
public:
    static int funcType() {
        int n;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> n;

        return n;
    } // 어떤 기능을 수행할지 선택
    static int shapeType() {
        int n;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> n;

        return n;
    } // 어떤 도형을 삽입할 지 선택
    static int deleteIndex() {
        int n;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> n;

        return n;
    } // 어떤 index의 도형을 삭제할지 선택
};
// 입력의 관한 함수를 static으로 선언해서 UI의 객체를 생성하지 않고 함수를 사용할 수 있음

class GraphicEditor {
    Shape* pStart;
    Shape* pLast;
    // 연결되어있는 Shape 형태들을 가리키는 포인터
    int index;
    // 현재 저장하고 있는 객체들의 개수, 배열의 index처럼 사용가능

public:
    GraphicEditor() {
        cout << "그래픽 에디터 입니다.\n";
        pStart = NULL;
        pLast = NULL;
        index = 0;
    }

    ~GraphicEditor() {
        Shape* tmp;
        while(pStart) {
            tmp = pStart;
            pStart = pStart->link;
            delete tmp;
        } // 생성후 남아있는 객체들을 모두 반환한다
    }

    void insert(int type) { // UI의 함수로 부터 생성할 도형의 타입을 전달
        Shape* p;
        p->id = index++;
        switch(type) {
        case 1:
            p = new Line();
            break;
        case 2:
            p = new Circle();
            break;
        case 3:
            p = new Rect();
            break;
        default:
            break;
        }

        if(is_empty()) {
            pStart = pLast = p;
        } // 생성된 Shape이 없으면 시작 위치와 마지막 위치로 설정
        else {
            pLast->link = p;
            pLast = p;
        } // 생성된 Shape이 있으면 가장 마지막에 연결
    }

    void deleteL(int index) {
        Shape* tmp = pStart;
        for(int i = 0; i < index-1; i++) {
            tmp = tmp->link;
        } // 삭제할 노드의 위치 전까지 이동

        Shape* tmp2 = tmp->link; // 삭제 할 노드의 위치 
        while(tmp2) {
            tmp2->id--;
            tmp2 = tmp2->link;
        } // 삭제할 위치부터, id(index)를 1개씩 감소

        tmp2 = tmp->link; // 삭제할 노드의 위치 다시 저장
        tmp->link = tmp->link->link; // 삭제할 노드의 다음으로 링크

        delete tmp2; // 저장했던 위치 메모리 삭제

        this->index--; // 현재 저장하고 있는 객체가 1개 삭제 되었기 때문에 -1
    }

    void show() {
        Shape* tmp = pStart;
        while(tmp) {
            cout << tmp->id << " : " << tmp->draw() << endl;
            tmp = tmp->link;
        }
        // 연결되어있는 Shape포인터들의 처음부터 끝까지 id와 오버라이딩 된 draw()함수를 시행
        // 상속되어있는 클래스의 종류에 따라 다르게 시행
    }

    bool is_empty() {
        if(pStart == NULL) return true;
        else return false;
    }
    // Shape들이 있는 리스트가 비어있으면 시작 부분이 NULL, 비어있는지에 대한 bool값 반환
};

int main() {
    GraphicEditor g;
    while(1) {
        int n = UI::funcType();
        switch(n) {
        case 1:
            g.insert(UI::shapeType());
            break;
        case 2:
            g.deleteL(UI::deleteIndex());
            break;
        case 3:
            g.show();
            break;
        case 4:
            exit(1);
        default:
            break;
        }
    }
}
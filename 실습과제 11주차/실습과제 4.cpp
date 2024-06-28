#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual string draw() = 0;
    Shape* link;
    int id;

    Shape() {
        link = NULL;
        id = 0;
    } // Shape�� �����Ǹ� ���� ��ü�� ������ link�� NULL�� �ʱ�ȭ �Ѵ�.

    virtual ~Shape() {}
    // ���� �Ҹ��ڸ� ����� ��ü ������ �ڽ�Ŭ������ �Ҹ��ڸ� �����Ѵ�.
};
// �߻�Ŭ������, ��ӹ��� Ŭ�������� draw()�Լ��� �ڽ��� ���¸� string���� �����Ѵ�.
// �ڽ��� ������ ����� ��ü�� ����ų ������
// �ڽ��� �ڽ�Ŭ������ ����Ű�� �Ǹ�, ��ĳ���� �߻�
// �����Լ��� ���� �������̵��� �߻�, ���� �ڽ�Ŭ������ draw()�Լ��� ����

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
        cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
        cin >> n;

        return n;
    } // � ����� �������� ����
    static int shapeType() {
        int n;
        cout << "��:1, ��:2, �簢��:3 >> ";
        cin >> n;

        return n;
    } // � ������ ������ �� ����
    static int deleteIndex() {
        int n;
        cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
        cin >> n;

        return n;
    } // � index�� ������ �������� ����
};
// �Է��� ���� �Լ��� static���� �����ؼ� UI�� ��ü�� �������� �ʰ� �Լ��� ����� �� ����

class GraphicEditor {
    Shape* pStart;
    Shape* pLast;
    // ����Ǿ��ִ� Shape ���µ��� ����Ű�� ������
    int index;
    // ���� �����ϰ� �ִ� ��ü���� ����, �迭�� indexó�� ��밡��

public:
    GraphicEditor() {
        cout << "�׷��� ������ �Դϴ�.\n";
        pStart = NULL;
        pLast = NULL;
        index = 0;
    }

    ~GraphicEditor() {
        Shape* tmp;
        while (pStart) {
            tmp = pStart;
            pStart = pStart->link;
            delete tmp;
        } // ������ �����ִ� ��ü���� ��� ��ȯ�Ѵ�
    }

    void insert(int type) { // UI�� �Լ��� ���� ������ ������ Ÿ���� ����
        Shape* p = NULL;
        switch (type) {
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
        // ���޹��� �Ű������� ������ ���� ���� 
        p->id = index++;


        if (is_empty()) {
            pStart = pLast = p;
        } // ������ Shape�� ������ ���� ��ġ�� ������ ��ġ�� ����
        else {
            pLast->link = p;
            pLast = p;
        } // ������ Shape�� ������ ���� �������� ����
    }

    void deleteL(int index) {
        Shape* tmp = pStart;
        if (index == 0) {
            pStart = pStart->link;
            delete tmp;
            tmp = pStart;
            while (tmp) {
                tmp->id--;
                tmp = tmp->link;
            } // ������ ��ġ����, id(index)�� 1���� ����
            this->index--;
            return;
        } // ù��° ������ �����ϴ� ��� pStart�� �ű�� ������ �����Ѵ�.

        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->link;
        } // ������ ����� ��ġ ������ �̵�

        Shape* tmp2 = tmp->link; // ���� �� ����� ��ġ 
        while (tmp2) {
            tmp2->id--;
            tmp2 = tmp2->link;
        } // ������ ��ġ����, id(index)�� 1���� ����

        tmp2 = tmp->link; // ������ ����� ��ġ �ٽ� ����
        tmp->link = tmp->link->link; // ������ ����� �������� ��ũ

        delete tmp2; // �����ߴ� ��ġ �޸� ����

        this->index--; // ���� �����ϰ� �ִ� ��ü�� 1�� ���� �Ǿ��� ������ -1

        tmp = pStart;
        while (tmp->link != NULL) {
            tmp = tmp->link;
        }
        pLast = tmp;
    }

    void show() {
        Shape* tmp = pStart;
        while (tmp) {
            cout << tmp->id << " : " << tmp->draw() << endl;
            tmp = tmp->link;
        }
        // ����Ǿ��ִ� Shape�����͵��� ó������ ������ id�� �������̵� �� draw()�Լ��� ����
        // ��ӵǾ��ִ� Ŭ������ ������ ���� �ٸ��� ����
    }

    bool is_empty() {
        if (pStart == NULL) return true;
        else return false;
    }
    // Shape���� �ִ� ����Ʈ�� ��������� ���� �κ��� NULL, ����ִ����� ���� bool�� ��ȯ
};

int main() {
    GraphicEditor g;
    while (1) {
        int n = UI::funcType();
        switch (n) {
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
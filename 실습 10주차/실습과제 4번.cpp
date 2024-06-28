#include <iostream>
#include <string>
using namespace std;

class Printer {
    string model, manufactor;
    // �������� �𵨸�, ������
    int papers;
    // ������ �ܷ�
protected:
    Printer(string model, string manufactor, int papers) {
        this->model = model;
        this->manufactor = manufactor;
        this->papers = papers;
    }
    // ���޹��� �Ű������� �𵨸�, ������, �����ܷ� ����
    // �ڽ�Ŭ������ Ȱ���ϱ� ���� Ŭ������ �Ű������� �ڽ�Ŭ�������� ���޹޴´�.
    // �ڽ�Ŭ�������� ����Ʈ �Ű����� �����ڸ� �����ϱ� ������, ���� �Ű����� �����ڸ� ����� �ʿ䰡 ����.

    string getModel() {
        return model;
    }
    string getManufactor() {
        return manufactor;
    }
    // �𵨸�, ������ �������� 

    void Print(int papers) {
        this->papers -= papers;
    } // ���޹��� �ż���ŭ ����Ʈ

    int availableCount() {
        return papers;
    } // ���� �μⰡ���� ������ �� ����
    // �θ�Ŭ������ �����ڸ� ������ ��ɵ��� protected�� ����
    // Printer���� ��ü�� ������� �ʰ� �ڽ�Ŭ������ ����� �ִ� ��ü�鸸 ���
};
// ��� ������ ���Գ���(����): �𵨸�, ������, �μ� ���� �ܷ�
// ��� ������ �۵�(�Լ�) : ���(�μⷮ), ���� �μ� ������ �ż� Ȯ��

class InkJetPrinter : public Printer {
    int ink; // ��ũ �ܷ� ����
public:
    InkJetPrinter(string model = "", string manufactor = "", int pages = 0, int ink = 0) : Printer(model, manufactor, pages) {
        this->ink = ink;
        // �̸�, ������, �������� �θ�Ŭ������ �����ڿ��� �Է�
    }
    int availableInk() {
        return ink;
    } // ��ũ �ܷ� ����

    void printInkJet(int pages) {
        if (availableCount() < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
        } // �μⷮ�� ���� �������� ������, ���� ���� (���� �켱 Ȯ��)
        else if (availableInk() < pages) {
            cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
        } // �μⷮ�� ���� ��ũ���� ������, ��ũ ����
        else {
            ink -= pages;
            Print(pages);
            // ���� ��ũ �ܷ� �μ� �ż� ��ŭ ���
            // ���� ���� �ܷ� �μ� �ż� ��ŭ ���
            cout << "����Ʈ �Ͽ����ϴ�\n";
        }
    }

    void showInfo() {
        cout << "��ũ��: " << getModel() << ", " << getManufactor() << ", ���� ���� " << availableCount() << "��, ������ũ " << availableInk() << endl;
    }
    // ���� �������� ���� ���
};


class LaserPrinter : public Printer {
    int toner; // ��� �ܷ� ����
public:
    LaserPrinter(string model = "", string manufactor = "", int papers = 0, int toner = 0) : Printer(model, manufactor, papers) {
        this->toner = toner;
        // �̸�, ������, �������� �θ�Ŭ������ �����ڿ��� �Է�
    }

    int availableToner() {
        return toner;
    } // ��� �ܷ����� ����

    void printLaser(int pages) {
        if (availableCount() < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
        } // �μⷮ�� ���� �������� ������, ���� ���� (���� �켱 Ȯ��)
        else if (availableToner() < pages) {
            cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
        } // �μⷮ�� ���� ��ʺ��� ������, ��� ����
        else {
            toner -= pages;
            Print(pages);
            // ���� ��� �ܷ� �μ� �ż� ��ŭ ���
            // ���� ���� �ܷ� �μ� �ż� ��ŭ ���
            cout << "����Ʈ �Ͽ����ϴ�\n";
        }
    }
    void showInfo() {
        cout << "������: " << getModel() << ", " << getManufactor() << ", ���� ���� " << availableCount() << "��, ������� " << availableToner() << endl;
    }
    // ���� �������� ���� ���
};

int main() {
    InkJetPrinter* i = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* l = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
    // ��ũ�� ������, ������ ������ ���� ����

    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����.\n";
    i->showInfo();
    l->showInfo();

    char command = '\0';
    int type, pages;
    while (command != 'n') { // �Է¹��� command�� n�� �ƴҵ��� ��� �ݺ�
        cout << "\n������(1: ��ũ��, 2: ������)�� �ż� �Է� >> ";
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
        // ������ ���� Ÿ�Կ� ���� �ٸ� ������ ���

        i->showInfo();
        l->showInfo();
        // ����Ʈ ���� ���� ������ ���� ���

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n) >> ";
        cin >> command;
        while (command != 'y' && command != 'n') {
            cout << "�߸��� �Է��Դϴ�\n";
            cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n) >> ";
            cin >> command;
        } // �Է��� y, n�� �ƴϸ� �ٽ� �Է¹ޱ�
    }

    delete i;
    delete l;
    // ���������� ��ü �޸� ����
}
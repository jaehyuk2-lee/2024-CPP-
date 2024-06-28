#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill(); // �ִ뷮(10)���� ä���
	void consume(); // 1 ��ŭ �Ҹ��ϱ�
	int getSize(); // ���� ũ�� ����
}; // CoffeeVendingMachine ��ü�� Container�� ��ü�� �迭�� ���� �ֱ� ������ ���� ���� �Ǿ���Ѵ�.

void Container::fill() { // Container��ü�� fill() �Լ�
	this->size = 10; // ��ü�� ����ִ� ��Ḧ 10���� ä���.
}
void Container::consume() { // ��ü�� size�� ����� 1�� ���δ�.
	this->size--;
}
int Container::getSize() {
	return this->size;
} // ���� ��ü�� �������ִ� size����


class CoffeeVendingMachine {
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� ������
	void fill(); // 3���� ���� ��� 10���� ä��
	void selectEspresso(); // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano(); // �Ƹ޸�ī�븦 ������ ���, Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarcoffee(); // ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
	void show(); // ���� Ŀ��, ��, ������ �ܷ� ���

public:
	void run(); // �ٸ� ��ü �Լ����� private �����������̱� ������ run()�Լ��� ���ؼ� �����ؾ��Ѵ�.
};

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	} // ���� 3���� �ֱ� ������, ��� tong��ü���� fill()�Լ��� �����Ѵ�.
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << "\n";
	// ä���� ������ ������ �����ش�.
}
void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
		// ������������ ����� �� 1, Ŀ�� 1�̱� ������
		// �ܷ��� �䱸 ���Ẹ�� ���ų� Ŭ���� �����Ѵ�.
		tong[0].consume();
		tong[1].consume();
		cout << "���������� �弼��" << "\n";
	}
	else cout << "���ᰡ �����մϴ�.\n";
	// ���ᰡ ������ ��� �������� �ʴ´�.
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
		// �Ƹ޸�ī���� ����� �� 1, Ŀ�� 2�̱� ������
		// �ܷ��� �䱸 ���Ẹ�� ���ų� Ŭ���� �����Ѵ�.
		tong[0].consume();
		tong[1].consume();
		tong[1].consume(); // �Ƹ޸�ī���� ���� 2�� �Ҹ�
		cout << "�Ƹ޸�ī�� �弼��" << "\n";
	}
	else cout << "���ᰡ �����մϴ�.\n";
}
void CoffeeVendingMachine::selectSugarcoffee() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
		// ����Ŀ���� ����� �� 1, Ŀ�� 2, ���� 1�̱� ������
		// �ܷ��� �䱸 ���Ẹ�� ���ų� Ŭ���� �����Ѵ�.
		tong[0].consume();
		tong[1].consume();
		tong[1].consume(); // ����Ŀ�Ǵ� �� 2�� �Ҹ�
		tong[2].consume();
		cout << "����Ŀ�� �弼��" << "\n";
	}
	else cout << "���ᰡ �����մϴ�.\n";
}
void CoffeeVendingMachine::show() {
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << "\n";
} // ���� �뿡 ����ִ� ����� ũ����� ����Ѵ�.

void CoffeeVendingMachine::run() {
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ� *****" << endl;

	int choice; // ������� ������ �Է¹��� ����
	while (1) {
		cout << "�޴��� �����ּ��� (1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���, 0:����)>> ";
		cin >> choice;
		switch (choice) { // ������� �Է¿� ���� �Լ��� �����Ѵ�.
		case 1:
			this->selectEspresso();
			break;
		case 2:
			this->selectAmericano();
			break;
		case 3:
			this->selectSugarcoffee();
			break;
		case 4:
			this->show();
			break;
		case 5:
			this->fill();
			break;
		case 0:
			cout << "�����մϴ�.\n";
			exit(1); // 0�� �Է¹����� �ݺ��� �����Ѵ�.
			break;
		default:
			break;
		}
	}
}

int main() {
	CoffeeVendingMachine myMachine;
	myMachine.run();
}
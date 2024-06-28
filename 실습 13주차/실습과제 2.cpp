#include <iostream>
#include <iomanip> // �Ű� ������ ���� ������ setw�� ����ϱ� ���� include
#include <cmath>
using namespace std;

int main() {
	cout.setf(ios::left); // ��°����� �����͸� ����� �� �������� �����Ͽ� ���
	
	cout << setw(15) << "Number"; // ��������� �Ǵ� ������ 15�� ����
	cout << setw(15) << "Square";
	cout << setw(15) << "Square Root";
	cout << endl;

	streamsize prec;
	// ���ۿ��� �������� �������� ũ�⸦ �����ϴ� ����, ��ȿ���� 3�ڸ��� �����ٿ��� �����ϱ� ����
	// �ʱ� ��ȿ���ڸ� ������ �δ� ����
	for (int i = 0; i <= 45; i += 5) {
		cout << setw(15) << setfill('_') << i; // ��� ������ ���� �ڸ��� '-'��  ä��
		cout << setw(15) << setfill('_') << pow(i, 2);

		prec = cout.precision(); // ��ȿ ���ڸ� �����ϱ� �� ������ ��ȿ���� �ڸ� ����
		cout.precision(3); // �����ٿ��� ��ȿ ���� ����
		cout << setw(15) << setfill('_') << (double)sqrt(i); // �������� �Ǽ�, ���� double�� ����ȯ

		cout.precision(prec); // �ʱⰪ���� ��ȿ ���� ����
		cout << endl;
	}
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	string expression = "0"; // ���� ����� ����

	while (expression != "\0") { // �ƹ��͵� �Է����� ������ �ݺ� ����
		string num1, num2; // ���� �����κ��� ���� �� ����
		char cal = '\0'; // ���� ����ȣ�κ��� ���� �� ����
		cout << "? ";
		getline(cin, expression);
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ' ') { // ù��° ������ ��Ÿ���� ��
				for (int j = 0; j < i; j++) {
					num1 += expression[j]; // 0��° ���� �������������� ���ڿ��� ����
				}
				for (int k = i + 3; k < expression.size(); k++) {
					num2 += expression[k];
					// ù��° ����, ����, ����ȣ, ����, �ι�° ���� �����̱� ������
					// ù��° ������� 3ĭ �ڰ� �ι�° ������ ����, ���ڿ� �������� �ι�° ������ ��
				}
				cal = expression[i + 1]; // ù��° ���� ������ ����ȣ
				break; // ù��° ���� ������ �ݺ�
			}
		}
		int n1 = atoi(num1.c_str());
		int n2 = atoi(num2.c_str()); // ���ڿ��� ����� ���ڸ� int������ ��ȯ

		switch (cal) { // cal������ ��쿡 ���� �ٸ��� ����Ѵ�
		case '+':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 + n2 << endl;
			break;
		case '-':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 - n2 << endl;
			break;
		case '*':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 * n2 << endl;
			break;
		case '/':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 / n2 << endl;
			break;
		case '%':
			cout << n1 << " " << cal << " " << n2 << " = " << n1 % n2 << endl;
			break;
		default:
			break;
		}
	}
}
#include <iostream>
using namespace std;

int main() {
	char ch;
	while ((ch = cin.get()) != EOF) { // ctrl z�� �Է¹޾��� ��� cin.get()�� EOF�� �����Ѵ�.
		if (ch == ';') { // ��Ʈ���� �Է¹޴ٰ� ;�� ������ ���
			cin.ignore(30, '\n'); // ���๮�ڸ� ���� �� ���� ���ۿ� �����ִ� 30���� ���� �����.
			cout.put('\n'); // ���� �Է��� ���� ���� �ٲ۴�.
		}
		else cout.put(ch); // ;�� �ƴ϶�� ���ۿ� �ִ� ���ڸ� ����Ѵ�.
	}
}
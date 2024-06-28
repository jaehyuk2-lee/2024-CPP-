#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream fin("word.txt", ios::in | ios::binary);
	// ������ �о� �� ��ü, �о�� ������ ��θ� ����
	
	if (!fin) {
		cout << "���� ���� ����" << endl;
		return 0;
	}

	vector<string> v; // �о�� ���ڸ� ������ ����
	string tmp; // ���Ͽ��� ���� ���ڸ� �ӽ÷� ������ ����

	while (getline(fin, tmp)) {
		v.push_back(tmp);
	}
	cout << "...words.txt ���� �ε� �Ϸ�" << endl;
	cout << "�˻��� �����մϴ�. �ܾ �Է��� �ּ���." << endl;
	while (1) {
		int is_exist = 0; // ã�� �ܾ �����ϴ��� Ȯ���ϴ� ���� 
		cout << "�ܾ� >> ";
		cin >> tmp; // �ӽ� ���忡 �� ������ �Է� ������ ��Ȱ��
		if (tmp == "exit") break;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].find(tmp) == 0) {
				is_exist = 1;
				cout << v[i] << endl;
			}
			// ���͸� ��� Ȯ��, �Է¹޴� ���ڿ��� �����Ѵٸ� find(tmp)�� ���� index�� 0�� ��ȯ
			// �Է��� ���ڿ��� �����ϴ� �ܾ����� �� �� ����
			// ã�� �ܾ �����ϹǷ� is_exist 1�� ����
		}
		if (!is_exist) cout << "�߰��� �� ����" << endl;
		// is_exist�� ������ 0�̶��, ���ͳ��ο� ã�� �ܾ ����
	}
}
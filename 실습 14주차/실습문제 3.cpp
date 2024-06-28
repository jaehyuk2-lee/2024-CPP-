#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* file) {
	if (file == NULL) throw "NULL"; // file�� NULL �������̸� NULL�� throw

	ifstream fin(file, ios::in | ios::binary);
	if (!fin) throw -1; // ���Ⱑ �����ϸ� -1�� throw

	fin.seekg(0, ios::end); // ������ ������ ��ġ�� get �����͸� �̵���Ű��
	int length = fin.tellg(); // ��ġ������ ���� (������ ũ��)
	return length;
} // ����ũ�⸦ �����ϴ� �Լ�


int main() {
	try {
		int n = getFileSize("C:\\Windows\\system.ini");
		cout << "���� ũ�� = " << n << endl; // ���� ũ�� = 219�� ��µ�

		int m = getFileSize(NULL);
		cout << "���� ũ�� = " << m << endl; // ����ũ�� = -1�� ��µ�

	} // getFileSize �߰��� throw�� �߻� ���� -> getFileSize�Լ��� ����ϴ� ������ try ��� ó��

	catch (int a) { // ���� �ڷᰡ throw �ȴٸ�, ���Ͽ��� ����
		cout << "���� ���� ����" << endl;
	}
	catch (const char* s) { // ���ڿ� �ڷᰡ throw �ȴٸ�, "NULL"�� throw�� -> file�� NULL������
		cout << "���� �߻� : ���ϸ��� "<< s <<"�Դϴ�." << endl;
	}
}
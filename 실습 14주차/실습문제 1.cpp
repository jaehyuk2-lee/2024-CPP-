#include <iostream>
#include <fstream> // ���� �б� ���⸦ ���� Ŭ����
using namespace std;

int main() {
	ifstream fin("C:\\Windows\\system.ini", ios::in|ios::binary);
	// ������ �о� �� ��ü, �о�� ������ ��θ� ����, '\r'���� �б� ���� ���̳ʸ� ���� ����
	ofstream fout("C:\\Temp\\system.txt", ios::in | ios::binary);
	// ���� ������ ������ �ٸ� ���Ͽ� ������ ��ü, ������ ������ ��θ� ����

	if (!fin || !fout) {
		cout << "���� ���� ����" << endl;
		return 0;
	}
	// fin, fout ��ü�� ��� �����Ǿ�� ����

	cout << "���� ����..." << endl;
	int size = 0;
	fin.seekg(0, ios::end); // get�����͸� ������ ������ �̵���Ų��.
	size = fin.tellg(); // ���� get �������� ��ġ�� ���� ������ �����Ѵ�.
	// ���ڸ� ����Ʈ ������ �����ϱ� ������, ������ ��ġ�� ���� ���� ������ ����Ʈ ũ�Ⱑ �ȴ�.

	fin.seekg(0, ios::beg); // get�����͸� �ٽ� ������ �̵���Ų��.

	char* tmp = new char[size / 10]; // 10%�� �о� ���� ����, 10���� ���� size ��ŭ �ӽ� ���۸� �����Ѵ�.

	for (int i = 1; i <= 10; i++) {
		fin.read(tmp, size / 10); // 10%��ŭ �о� tmp�� ����
		fout.write(tmp, fin.gcount()); // ��� �о�� ���� ����ŭ �ٸ� ���Ͽ� ������ �ۼ��Ѵ�.
		cout << "." << fin.gcount() << "B " << i * 10 << "%" << endl;
	}
	cout << size << "B ���� �Ϸ�" << endl;

	fin.close();
	fout.close();
	delete[] tmp;
}
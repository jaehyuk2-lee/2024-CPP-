#ifndef RAM_H
#define RAM_H

#include <iostream>
using namespace std;

class Ram {
public:
    Ram();                                // mem �迭�� 0���� �ʱ�ȭ�ϰ� size 100*1024�� �ʱ�ȭ
    ~Ram();                               // ���޸� ���ŵʡ� ���ڿ� ���
    char read(int address);               // address �ּ��� �޸� ����Ʈ ����
    void write(int address, char value);  // address �ּҿ� �� ����Ʈ�� value ����

private:
    char mem[100 * 1024]; // 100KB �޸�. �� ������ �� ����Ʈ�̹Ƿ� char Ÿ�Ի��
    int size;
};
#endif
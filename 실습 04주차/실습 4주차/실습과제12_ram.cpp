#include "�ǽ�����12_ram.h"

Ram::Ram() {
    for (int i = 0; i < 100 * 1024; i++) {
        mem[i] = 0;
    }
    size = 100 * 1024;
} // mem �迭�� 0���� �ʱ�ȭ�ϰ� size 100*1024�� �ʱ�ȭ

Ram::~Ram() {
    cout << "�޸� ���ŵ�" << endl;
} // ���޸� ���ŵʡ� ���ڿ� ���

char Ram::read(int address) {
    return mem[address];
}               // address �ּ��� �޸� ����Ʈ ����
void Ram::write(int address, char value) {
    mem[address] = value;
} // address �ּҿ� �� ����Ʈ�� value ����
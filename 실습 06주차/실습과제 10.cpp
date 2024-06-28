#include <iostream>
#include <string>
using namespace std;


class Buffer {
    string text;

public:
    Buffer(string text) { this->text = text; }
    void add(string next) { text += next; } // text�� next ���ڿ� �����̱�
    void print() { cout << text << endl; }
};

Buffer& append(Buffer& buf, string str) {
    buf.add(str);
    return buf; // buf��ü�� ���ڿ��� �߰��� �� ���۷����� ��ȯ�Ѵ� �Ű������� ���Ϲ޴� ��ü ��� ���� ��ü�̴�.
} // ���� ������ ��ȯ�ϴ� �Լ�, �Է¹��� ��ü�� ���ڿ��� �߰��Ǿ��ϱ� ������, ���۷��� ������ �Ű������� �޴´�

int main() {
    Buffer buf("Hello");
    Buffer& temp = append(buf, "Guys"); // buf�� ���ڿ��� "Guys" ������
    temp.print();                       // "HelloGuys" ���
    buf.print();                        // "HelloGuys" ���

    buf.add("123");                     // buf�� ���ڿ��� 123�� �߰�
    temp.print();                       // temp�� buf�� ���۷����̱� ������ buf�� ���ڿ��� �߰��ϸ� temp�� ����ص� �߰��� ���� ��µȴ�.
    buf.print();
}
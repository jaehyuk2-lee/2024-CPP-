#ifndef BOX_H // ���� ���� ���� �ʾҴٸ� ����
#define BOX_H
#include <iostream>
using namespace std;

class Box {
public:
    Box(int, int); // ��ü�� ������ �� �޴� �Ű������� setSize�Լ� ���
    void setSize(int, int); // �ڽ��� ũ�� �����ϱ�
    void setFill(char); // �ڽ��� ä�� ���� �ٲٱ�
    void draw(); // �ڽ� �׸���

private:
    int width, height;
    char fill; // �ڽ��� ���θ� ä��� ����
};
#endif
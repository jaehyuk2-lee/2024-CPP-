#include <iostream>
using namespace std;

class CoffeeMachine
{
public:
    CoffeeMachine(int a, int b, int c)
    {
        coffee = a;
        water = b;
        sugar = c;
    } // Ŀ�Ƿ�:a, ����:b, ����:c�� �ʱ�ȭ

    void drinkespresso()
    {
        coffee -= 1;
        water -= 1;
    }; // Ŀ�� 1, �� 1 �Һ�

    void drinkAmericano()
    {
        coffee -= 1;
        water -= 2;
    } // Ŀ�� 1, �� 2 �Һ�

    void drinksugarCoffee()
    {
        coffee -= 1;
        water -= 2;
        sugar -= 1;
    } // Ŀ�� 1, �� 2, ���� 1 �Һ�

    void fill()
    {
        coffee = 10;
        water = 10;
        sugar = 10;
    } // Ŀ�� 10, �� 10, ���� 10���� ä���

    void show()
    {
        cout << "Ŀ�� �ӽ� ����, " << "Ŀ��: " << coffee << " \t��: " << water << " \t����: " << sugar << endl;
    } // ���� Ŀ�� �ӽ��� ���� ���

private: // Ŀ�� �� ������ ���� ������ �����������
    int coffee;
    int water;
    int sugar;
};

int main()
{
    CoffeeMachine java(5, 10, 3);
    java.drinkespresso();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinksugarCoffee();
    java.show();
    java.fill();
    java.show();
}
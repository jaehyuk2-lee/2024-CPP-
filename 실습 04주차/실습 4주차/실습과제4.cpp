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
    } // 커피량:a, 물량:b, 설탕:c로 초기화

    void drinkespresso()
    {
        coffee -= 1;
        water -= 1;
    }; // 커피 1, 물 1 소비

    void drinkAmericano()
    {
        coffee -= 1;
        water -= 2;
    } // 커피 1, 물 2 소비

    void drinksugarCoffee()
    {
        coffee -= 1;
        water -= 2;
        sugar -= 1;
    } // 커피 1, 물 2, 설탕 1 소비

    void fill()
    {
        coffee = 10;
        water = 10;
        sugar = 10;
    } // 커피 10, 물 10, 설탕 10으로 채우기

    void show()
    {
        cout << "커피 머신 상태, " << "커피: " << coffee << " \t물: " << water << " \t설탕: " << sugar << endl;
    } // 현재 커피 머신의 상태 출력

private: // 커피 물 설탕의 양을 저장할 멤버변수선언
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
#include <iostream>
using namespace std;

void half(double&); // ���޵� ���� �����ؾ� �Ǳ� ������ ���۷����� ���޹޾� ���� �����Ѵ�.

int main() {
    double n = 20;
    half(n); // n�� �ݰ��� ���� n�� �ٲ۴�. 
    cout << n; // 10�� ��µȴ�.
}

void half(double& a) { // a��� ������ ���� ���� n���� �Ҵ��ϴ� ���� �ƴ϶�, a�� ���޹��� n ��ü�� ����.
    a /= 2;
}
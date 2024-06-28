#include <iostream>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
public:
	void setRadius(int radius); // 반지름을 설정한다.
	double getArea(); // 면적을 리턴한다.
};

void Circle::setRadius(int radius) {
	this->radius = radius;
	// 객체의 멤버와 매개변수의 이름이 같을 때 this 포인터를 이용해 구분할 수 있다.
} // 반지름을 설정한다.


double Circle::getArea() {
	return this->radius * this->radius * 3.14;
	// getArea()는 Circle안에 포함되어 있기 때문에 this를 사용할 수 있다.
} // 면적을 리턴한다.

int main() {
	int N; // 원의 개수를 저장할 변수
	cout << "원의 개수 >> ";
	cin >> N;
	
	Circle* list; // 원들의 리스트를 가리키는 포인터, 아직 정해지지 않았음
	list = new Circle[N]; // Circle 객체를 N개 저장할수 있는 메모리를 동적할당

	int setR = 0; // 원들의 반지름을 설정할 변수
	for (int i = 0; i < N; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> setR;
		list[i].setRadius(setR);
	} // N개의 원이 있기 때문에 N번 입력받는다.

	int cnt = 0; // 면적이 100보다 큰 원의 개수를 저장할 변수
	for (int i = 0; i < N; i++) {
		if (list[i].getArea() > 100) {
			cnt++;
		}
	} // N개의 원이 있기 때문에 N번 비교한다.
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다" << endl;
}
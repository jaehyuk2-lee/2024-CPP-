#include <iostream>
using namespace std;

class SortedArray
{
    int size;    // 현재 배열의 크기
    int *p;      // 정수 배열에 대한 포인터
    void sort() {
        for(int i = 0; i < size; i++) {
            int min_index = i;
            for(int j = i; j < size; j++) {
                if(p[min_index] > p[j]) {
                    min_index = j;
                }
            }
            int tmp = p[i];
            p[i] = p[min_index];
            p[min_index] = tmp;
        }
    }// 정수 배열을 오름차순으로 정렬
public:
    SortedArray()
    {
        p = NULL;
        size = 0;
    } // p는 NULL로 size는 0으로 초기화
    SortedArray(SortedArray &src)
    {
        size = src.size;
        if (p)
            delete[] p; // 할당받은 메모리가 있었다면 우선 해제
        for (int i = 0; i < size; i++)
        {
            p[i] = src.p[i]; // 전달받은 객체의 배열 복사
        }
        sort();
    } // 복사 생성자

    SortedArray(int p[], int size)
    {
        this->size = size;
        this->p = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->p[i] = p[i];
        }
        sort();
    } // 생성자. 정수 배열과 크기를 전달받음

    ~SortedArray()
    {
        delete[] p; // 할당받은 메모리 해제
    } // 소멸자


    SortedArray operator+(SortedArray &op2) {
        SortedArray c;
        c.size = size+op2.size;
        c.p = new int[size];
        for(int i = 0; i < size; i++) {
            c.p[i] = p[i];
        }
        for(int i = 0; i < op2.size; i++) {
            c.p[size+i] = op2.p[i];
        }
        c.sort();
        return c;
    } // 현재 배열에 op2 배열 추가
    SortedArray &operator=(const SortedArray &op2) {
        size = op2.size;
        if(p) delete[] p;
        p = new int[size];
        for(int i = 0; i < size; i++) {
            p[i] = op2.p[i];
        }
        return *this;
    }
    // 현재 배열에 op2 배열 복사
    // 연속된 대입이 있을 수 있기 때문에 자신의 레퍼런스 반환
    void show(){
        for(int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }// 배열의 원소 출력
};

int main()
{
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n, 3), b(m, 4), c;
    c = a + b; // +, = 연산자 작성 필요
    // +연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
    a.show();
    b.show();
    c.show();
}

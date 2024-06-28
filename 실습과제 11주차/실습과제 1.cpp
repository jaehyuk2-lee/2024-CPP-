#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
    double ratio;
    virtual double convert(double src) = 0; // src를 다른 단위로 변환
    virtual string getSourceString() = 0;   // src 단위 명칭
    virtual string getDestString() = 0;     // dest 단위 명칭
public:
    Converter(double ratio) { this->ratio = ratio; }
    void run()
    {
        double src;
        cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
        cout << getSourceString() << "을 입력하세요>> ";
        cin >> src;
        cout << "변환 결과 :" << convert(src) << getDestString() << endl;
    }
};

class KmToMile : public Converter {
    double convert(double src) override {
        return src / ratio;
    };
    // 전달받은 값을 설정된 비율로 변환
    // dest에 ratio를 곱해서 변환한 길이가 src이므로, dest = src/ratio

    string getSourceString() override {
        return "Km";
    };
    string getDestString() override {
        return "Mile";
    };
    // Km를 Mile로 변환하는 클래스이기 때문에, source는 Km, dest는 Mile로 설정

    // run() 함수에서 사용할 함수기 때문에, private로 보호
public:
    KmToMile(double ratio) : Converter(ratio) {}
    // 변환하는 비율을 매개변수로 받아서 부모클래스의 생성자로 전달
};

int main() {
    KmToMile toMile(1.609344);
    toMile.run();
}
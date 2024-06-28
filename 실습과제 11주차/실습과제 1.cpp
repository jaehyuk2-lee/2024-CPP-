#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
    double ratio;
    virtual double convert(double src) = 0; // src�� �ٸ� ������ ��ȯ
    virtual string getSourceString() = 0;   // src ���� ��Ī
    virtual string getDestString() = 0;     // dest ���� ��Ī
public:
    Converter(double ratio) { this->ratio = ratio; }
    void run()
    {
        double src;
        cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
        cout << getSourceString() << "�� �Է��ϼ���>> ";
        cin >> src;
        cout << "��ȯ ��� :" << convert(src) << getDestString() << endl;
    }
};

class KmToMile : public Converter {
    double convert(double src) override {
        return src / ratio;
    };
    // ���޹��� ���� ������ ������ ��ȯ
    // dest�� ratio�� ���ؼ� ��ȯ�� ���̰� src�̹Ƿ�, dest = src/ratio

    string getSourceString() override {
        return "Km";
    };
    string getDestString() override {
        return "Mile";
    };
    // Km�� Mile�� ��ȯ�ϴ� Ŭ�����̱� ������, source�� Km, dest�� Mile�� ����

    // run() �Լ����� ����� �Լ��� ������, private�� ��ȣ
public:
    KmToMile(double ratio) : Converter(ratio) {}
    // ��ȯ�ϴ� ������ �Ű������� �޾Ƽ� �θ�Ŭ������ �����ڷ� ����
};

int main() {
    KmToMile toMile(1.609344);
    toMile.run();
}
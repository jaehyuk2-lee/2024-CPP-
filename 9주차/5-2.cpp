#include <iostream>
using namespace std;
class Color {
    int red, green, blue;

public:
    Color() { red = green = blue = 0; }
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
    void setColor(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
    void show() { cout << red << ' ' << green << ' ' << blue << endl; }

    friend Color operator+ (const Color&, const Color&);
    friend bool operator== (const Color&, const Color&);
};

Color operator+ (const Color& a, const Color& b) {
        Color ret(a.red+b.red,a.green+b.green,a.blue+b.blue);
        return ret;
    }

bool operator== (const Color& a, const Color& b) {
        if(a.red == b.red && a.green == b.green && a.blue == b.blue) return true;
        else return false;
    }

int main () {
    Color red (255, 0, 0), blue (0, 0, 255), c;
    c = red + blue;
    c.show(); // 색 값 출력
    Color fuchsia (255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";
}
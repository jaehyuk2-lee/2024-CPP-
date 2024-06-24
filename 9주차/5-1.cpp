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

    Color operator+ (const Color& a) {
        int r = red + a.red;
        int g = green + a.green;
        int b = blue + a.blue;

        Color ret(r,g,b);
        return ret;
    }

    bool operator== (const Color& a) {
        if(this->red == a.red && this->green == a.green && this->blue == a.blue) return true;
        else return false;
    }
};

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
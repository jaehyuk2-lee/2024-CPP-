class Box {
public:
    Box(int w, int h) {
        setSize(w, h);
        fill = '*'; // 기본적으로 * 출력
    } // 객체가 생성될 때 받는 매개변수로 setSize함수 사용

    void setSize(int, int); // 박스의 크기 설정하기
    void setFill(char); // 박스를 채울 문자 바꾸기
    void draw(); // 박스 그리기
    
private:
    int width, height;
    char fill; // 박스의 내부를 채우는 문자
};
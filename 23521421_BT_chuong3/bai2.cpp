#include<bits/stdc++.h>
using namespace std;

class Circle {
public:
    float x, y;      
    float radius;
    const float PI = 3.14159;

    float calculateArea() {
        return PI * pow(radius, 2);
    }

    float calculateCircumference() {
        return 2 * PI * radius;
    }

    void display() {
        cout << "Dien tich duong tron: " << calculateArea() << endl;
        cout << "Chu vi duong tron: " << calculateCircumference() << endl;
    }
};

int main() {
    Circle circle;
    float x, y, radius;
    cout << "Nhap toa do x cua tam: ";
    cin >> circle.x;
    cout << "Nhap toa do y cua tam: ";
    cin >> circle.y;
    cout << "Nhap ban kinh duong tron: ";
    cin >> circle.radius;

    circle.display();
    return 0;
}

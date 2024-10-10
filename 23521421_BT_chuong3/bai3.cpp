#include<bits/stdc++.h>
using namespace std;

class Point {
public:
    float x, y; 

float calculateDistance(Point p2) {
    return sqrt(pow(this -> x - p2.x, 2) + pow(this -> y - p2.y, 2));
}
};

int main() {
    Point p1, p2;
    cout << "Nhap toa do x cua diem thu nhat ";
    cin >> p1.x;
    cout << "Nhap toa do y cua diem thu nhat ";
    cin >> p1.y;

    cout << "Nhap toa do x cua diem thu hai ";
    cin >> p2.x;
    cout << "Nhap toa do y cua diem thu hai ";
    cin >> p2.y;

    cout << "Khoang cach giua 2 diem: " << p1.calculateDistance(p2) << endl;

    return 0;
}

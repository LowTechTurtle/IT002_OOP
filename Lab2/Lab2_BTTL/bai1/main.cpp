#include<bits/stdc++.h>
#include "bai1.cpp"
using namespace std;

int main() {
    cout << "Tao diem A bang default constructor" << endl;
    Diem A;
    A.Xuat();

    double x, y;
    cout << "Nhap hoanh do va tung do cua diem B: " ;
    cin >> x >> y;
    Diem B(x, y);
    B.Xuat();

    cout << "Tao diem C bang copy constructor, copy diem B" << endl;
    Diem C(B);
    C.Xuat();

    cout << "Hoanh do cua B: " << B.GetHoanhDo() << endl;
    cout << "Tung do cua B: " << B.GetTungDo() << endl;

    cout << "Nhap do tinh tien cho diem B: " << endl;
    cin >> x >> y;
    B.TinhTien(x, y);

    cout << "Diem B sau khi tinh tien: ";
    B.Xuat();

    return 0;
}

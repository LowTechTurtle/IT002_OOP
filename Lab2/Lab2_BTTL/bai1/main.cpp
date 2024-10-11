#include<bits/stdc++.h>
#include "bai1.cpp"
using namespace std;

int main() {
    Diem A;
    A.Xuat();

    Diem B(1, 1);
    B.Xuat();

    Diem C(B);
    C.Xuat();

    cout << "Hoanh do cua B: " << B.GetHoanhDo() << endl;
    cout << "Tung do cua B: " << B.GetTungDo() << endl;

    B.SetHoanhDo(1);
    B.SetTungDo(2);
    B.Xuat();

    B.TinhTien(3, 4);
    cout << "Diem B sau khi tinh tien delta_x=3 va delta_y=4 ";
    B.Xuat();

    return 0;
}

#include <bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

int main() {
    DaGiac dg;
    double x;
    dg.Nhap();
    dg.Xuat();

    cout << "Nhap lan luot dx va dy de tinh tien: ";
    dg.TinhTien(2, 3);
    cout << "\nDa giac sau khi tinh tien: " << endl;
    dg.Xuat();

    cout << "Nhap scale phong to da giac: ";
    cin >> x;
    dg.PhongTo(x);
    cout << "\nDa giac sau khi phong to: " << endl;
    dg.Xuat();

    cout << "Nhap scale thu nho dagiac: ";
    cin >> x;
    dg.ThuNho(x);
    cout << "\nDa giac sau khi thu nho: " << endl;
    dg.Xuat();

    cout << "Nhap goc de quay da giac: ";
    cin >> x;
    dg.Quay(x);
    cout << "\nDa giac sau khi quay: " << endl;
    dg.Xuat();

    return 0;
}
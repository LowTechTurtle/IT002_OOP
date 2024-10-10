#include<bits/stdc++.h>
#include "bai1.cpp"
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;
    arrPhanSo a;
    a.nhap(n);
    cout << "Phan so lon nhat la: " << endl;
    a.LayPSLonNhat().Xuat();
    cout << "Phan so nho nhat la: " << endl;
    a.LayPSNhoNhat().Xuat();
    return 0;
}

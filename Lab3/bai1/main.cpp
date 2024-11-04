#include<bits/stdc++.h>
#include "bai1.cpp"
using namespace std;

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat: " << endl;
    cin >> ps1;
    cout << "Nhap phan so thu hai: " << endl;
    cin >> ps2;

    PhanSo tong = ps1 + ps2;
    cout << "tong cua 2 phan so: " << tong << endl;

    PhanSo hieu = ps1 - ps2;
    cout << "hieu cua 2 phan so: " << hieu << endl;

    PhanSo tich = ps1 * ps2;
    cout << "tich cua 2 phan so: " << tich << endl;

    PhanSo thuong = ps1 / ps2;
    cout << "Thuong cua 2 phan so: " << thuong << endl;

    if (ps1 == ps2) {
        cout << "2 phan so bang nhau" << endl;
    } else {
        cout << "2 phan so khong bang nhau" << endl;
    }

    return 0;
}

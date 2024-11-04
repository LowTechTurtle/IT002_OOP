#include<bits/stdc++.h>
#include "bai2.cpp"
using namespace std;

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so thu nhat: " << endl;
    cin >> sp1;
    cout << "Nhap so thu hai: " << endl;
    cin >> sp2;

    cout << "So thu nhat: " << endl;
    cout << sp1 << endl;
    cout << "So thu hai: " << endl;
    cout << sp2 << endl;

    SoPhuc tong = sp1 + sp2;
    cout << "Tong: " << tong << endl;

    SoPhuc hieu = sp1 - sp2;
    cout << "Hieu: " << hieu << endl;

    SoPhuc tich = sp1 * sp2;
    cout << "Tich: " << tich << endl;

    SoPhuc thuong = sp1 / sp2;
    cout << "Thuong: " << thuong << endl;

    if (sp1 == sp2) {
        cout << "Hai so bang nhau" << endl;
    } else {
        cout << "Hai so khong bang nhau" << endl;
    }

    return 0;
}

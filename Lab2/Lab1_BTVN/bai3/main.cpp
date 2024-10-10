#include<bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> arr(n);
    cout << "Nhap danh sach cac phan so: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap tu so thu: " << i + 1 << " ";
        cin >> arr[i].tu;
        cout << "Nhap mau so thu: " << i + 1 << " ";
        cin >> arr[i].mau;
    }
    
    PhanSo phanSoDich;
    cout << "Nhap phan so dich: " << endl;
    cout << "Nhap tu so dich: ";
    cin >> phanSoDich.tu;
    cout << "Nhap mau so dich: " ;
    cin >> phanSoDich.mau;

    phanSoDich.rutGon();

    timTapCon(arr, phanSoDich);

    return 0;
}

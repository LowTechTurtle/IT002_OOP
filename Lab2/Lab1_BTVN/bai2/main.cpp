#include<bits/stdc++.h>
#include "bai2.cpp"
using namespace std;

int main() {
    int n, k;
    
    cout << "Nhap so phan so: ";
    cin >> n;
    arrPhanSo a;
    a.nhap(n);
    cout << "Nhap k de tim phan so lon thu k: ";
    cin >> k;
    a.LayPSLonThu(k);
    cout << "Nhap k de tim phan so nho thu k: ";
    cin >> k;
    a.LayPSNhoThu(k);

    return 0;
}

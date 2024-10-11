#include<bits/stdc++.h>
#include "bai5.cpp"
using namespace std;

int main() {
    int n, choice;
    Diem d;
    cin >> n;
    d.SetHoanhDo(n);
    cin >> n;
    d.SetTungDo(n);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> choice;
        if (choice == 1) {
            d.nhandoi();
        } else if (choice == 2) {
            d.GanGoc();
        } else if (choice == 3) {
            int k, _d;
            cin >> k >> _d;
            d.TinhTien(k, _d);
        }
    }

    d.Xuat();
    return 0;
}
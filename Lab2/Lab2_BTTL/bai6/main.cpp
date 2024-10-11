#include <bits/stdc++.h>
#include "bai6.cpp"
using namespace std;

int main() {
    TamGiac tg;
    double x, y;
    tg.Nhap();
    
    cin >> x >> y;
    tg.TinhTien(x, y);
    tg.Xuat();

    return 0;
}

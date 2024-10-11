#include<bits/stdc++.h>
#include "bai7.cpp"
using namespace std;

int main() {
    int n;
    cin >> n;

    DaGiac dg(n);
    dg.Nhap();
    cout << dg.DienTich() << endl;
    return 0;
}

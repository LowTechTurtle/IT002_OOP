#include<bits/stdc++.h>
using namespace std;

struct PhanSo {
    int Tu_so;
    int Mau_so;
};

void RutGon(PhanSo &ps) {
    int gcd = __gcd(ps.Tu_so, ps.Mau_so);
    ps.Tu_so = ps.Tu_so / gcd;
    ps.Mau_so = ps.Mau_so / gcd;
}

void Out(PhanSo ps) {
    if (abs(ps.Tu_so) == abs(ps.Mau_so) && abs(ps.Tu_so) == 1) {
        if (ps.Tu_so * ps.Mau_so > 0) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (ps.Tu_so == 0) {
        cout << 0 << endl;
    } else {
        cout << ps.Tu_so << "/" << ps.Mau_so << endl;
    }
}

int main() {
    PhanSo ps1, ps2;
    PhanSo temp;
    cin >> ps1.Tu_so >> ps1.Mau_so;
    cin >> ps2.Tu_so >> ps2.Mau_so;

    if (ps1.Mau_so == 0 || ps2.Mau_so == 0) {
        cout << "Mau so bang 0" << endl;
        return 0;
    }
    
    temp.Tu_so = ps1.Tu_so * ps2.Mau_so + ps2.Tu_so * ps1.Mau_so;
    temp.Mau_so = ps1.Mau_so * ps2.Mau_so;
    RutGon(temp);
    cout << "Tong 2 phan so vua nhap la: ";
    Out(temp);

    temp.Tu_so = ps1.Tu_so * ps2.Mau_so - ps2.Tu_so * ps1.Mau_so;
    temp.Mau_so = ps1.Mau_so * ps2.Mau_so;
    RutGon(temp);
    cout << "Hieu 2 phan so vua nhap la: ";
    Out(temp);

    temp.Tu_so = ps1.Tu_so * ps2.Tu_so;
    temp.Mau_so = ps1.Mau_so * ps2.Mau_so;
    RutGon(temp);
    cout << "Tich 2 phan so vua nhap la: ";
    Out(temp);

    temp.Tu_so = ps1.Tu_so * ps2.Mau_so;
    temp.Mau_so = ps1.Mau_so * ps2.Tu_so;
    RutGon(temp);
    cout << "Thuong 2 phan so vua nhap la: ";
    Out(temp);

    return 0;
}
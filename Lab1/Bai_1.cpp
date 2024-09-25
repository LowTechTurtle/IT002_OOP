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
};

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
    PhanSo ps;
    cin >> ps.Tu_so >> ps.Mau_so;

    if (ps. Mau_so == 0) {
        cout << "Mau so bang 0" << endl;
    }
    RutGon(ps);
    cout << "Phan so da duoc rut gon: ";
    Out(ps);
    return 0;
}
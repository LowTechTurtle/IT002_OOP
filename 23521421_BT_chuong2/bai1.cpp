#include<bits/stdc++.h>
using namespace std;

class PhanSo {
public:
    int Tu, Mau;

    PhanSo() {}
    
    PhanSo(int Tu, int Mau) {
        if (Mau != 0) { 
        this -> Tu = Tu;
        this -> Mau = Mau;
        }
    }
    void Tong(PhanSo ps) {
        cout << Tu * ps.Mau + ps.Tu * Mau << "/" << Mau * ps.Mau << endl;
    }

    void Hieu(PhanSo ps) {
        cout << Tu * ps.Mau - ps.Tu * Mau << "/" << Mau * ps.Mau << endl;
    }

    void Tich(PhanSo ps) {
        cout << Tu * ps.Tu << "/" << Mau * ps.Mau << endl;
    }

    void Thuong(PhanSo ps) {
        cout << Tu * ps.Mau << "/" << Mau * ps.Tu << endl;
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    PhanSo A;
    A.Tu = a;
    A.Mau = b;

    cin >> a >> b;
    PhanSo B;
    B.Tu = a;
    B.Mau = b;

    A.Tong(B);
    A.Hieu(B);
    A.Tich(B);
    A.Thuong(B);

    return 0;
}
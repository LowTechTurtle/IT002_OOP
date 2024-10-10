#include<bits/stdc++.h>
using namespace std;

class DonThuc {
public:

    double a; // he so
    int b;    // so mu
    DonThuc(double a = 0, int b = 0) : a(a), b(b) {}

    void nhap() {
        cout << "Nhap he so: ";
        cin >> a;
        cout << "Nhap so mu: ";
        cin >> b;
    }

    void xuat() const {
        if (b == 0) {
            cout << a; // chi in he so
        } else if (a == 0) {
            cout << 0; 
        } else if (b == 1) {
            cout << a << "x"; // khong in mu neu so mu la 1
        } else {
            cout << a << "x^" << b; 
        }
    }

    double tinhGiaTri(double x) const {
        return a * pow(x, b);
    }

    DonThuc daoHam() const {
        if (b == 0) {
            return DonThuc(0, 0);
        }
        return DonThuc(a * b, b - 1); 
    }

    DonThuc tong(DonThuc other) const {
        if (b == other.b) {
            return DonThuc(a + other.a, b);
        } else {
            cout << "2 don thuc khong cung bac" << endl;
            return -1;
        }
    }
};

int main() {
    DonThuc dt1, dt2;

    cout << "Nhap don thuc thu 1: \n";
    dt1.nhap();
    cout << "Nhap don thuc thu 2: \n";
    dt2.nhap();

    cout << "Don thuc 1: ";
    dt1.xuat();
    cout << endl;

    cout << "Don thuc 2: ";
    dt2.xuat();
    cout << endl;

    if (dt1.b == dt2.b) {
    DonThuc sum = dt1.tong(dt2);
    cout << "Tong 2 don thuc: ";
    sum.xuat();
    cout << endl;
    } else {
        cout << "Hai don thuc khong cung bac, khong tinh tong duoc" << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;
    
public:
    PhanSo() {
        iTu = 0;
        iMau = 1;
    }

    PhanSo(int Tu, int Mau) {
        iTu = Tu;
        iMau = Mau;
        rutGon();
    }

    void rutGon();

    PhanSo operator+(const PhanSo& ps) const;

    PhanSo operator-(const PhanSo& ps) const;

    PhanSo operator*(const PhanSo& ps) const;

    PhanSo operator/(const PhanSo& ps) const;

    bool operator==(const PhanSo& ps) const;

    bool operator!=(const PhanSo& ps) const;

    bool operator>(const PhanSo& ps) const;

    bool operator<(const PhanSo& ps) const;

    bool operator>=(const PhanSo& ps) const;

    bool operator<=(const PhanSo& ps) const;

    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu: ";
        is >> ps.iTu;
        cout << "Nhap mau: ";
        is >> ps.iMau;
        while (ps.iMau == 0) {
            cout << "Mau so khong the bang 0, hay nhap lai: ";
            is >> ps.iMau;
        }
        ps.rutGon();
        return is;
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.iTu;
        if (ps.iMau != 1) {
            os << "/" << ps.iMau;
        }
        return os;
    }
};
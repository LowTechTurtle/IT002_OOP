#include<bits/stdc++.h>
#include "bai1.h"
using namespace std;

    void PhanSo::rutGon() {
        int gcd = __gcd(abs(iTu), abs(iMau));
        iTu /= gcd;
        iMau /= gcd;
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    PhanSo PhanSo::operator+(const PhanSo& ps) const {
        int TuMoi = iTu * ps.iMau + ps.iTu * iMau;
        int MauMoi = iMau * ps.iMau;
        return PhanSo(TuMoi, MauMoi);
    }

    PhanSo PhanSo::operator-(const PhanSo& ps) const {
        int TuMoi = iTu * ps.iMau - ps.iTu * iMau;
        int MauMoi = iMau * ps.iMau;
        return PhanSo(TuMoi, MauMoi);
    }

    PhanSo PhanSo::operator*(const PhanSo& ps) const {
        int TuMoi = iTu * ps.iTu;
        int MauMoi = iMau * ps.iMau;
        return PhanSo(TuMoi, MauMoi);
    }

    PhanSo PhanSo::operator/(const PhanSo& ps) const {
        int TuMoi = iTu * ps.iMau;
        int MauMoi = iMau * ps.iTu;
        return PhanSo(TuMoi, MauMoi);
    }

    bool PhanSo::operator==(const PhanSo& ps) const {
        return iTu * ps.iMau == ps.iTu * iMau;
    }

    bool PhanSo::operator!=(const PhanSo& ps) const {
        return !(*this == ps);
    }

    bool PhanSo::operator>(const PhanSo& ps) const {
        return iTu * ps.iMau > ps.iTu * iMau;
    }

    bool PhanSo::operator<(const PhanSo& ps) const {
        return iTu * ps.iMau < ps.iTu * iMau;
    }

    bool PhanSo::operator>=(const PhanSo& ps) const {
        return !(*this < ps);
    }

    bool PhanSo::operator<=(const PhanSo& ps) const {
        return !(*this > ps);
    }

    
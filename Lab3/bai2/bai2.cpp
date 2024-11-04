#include<bits/stdc++.h>
#include "bai2.h"
using namespace std;

    SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
        return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
    }

    SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
        return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
    }

    SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
        double thucMoi = dThuc * sp.dThuc - dAo * sp.dAo;
        double aoMoi = dThuc * sp.dAo + dAo * sp.dThuc;
        return SoPhuc(thucMoi, aoMoi);
    }

    SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
        double mau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
        if (mau == 0) {
            cout << "Mau = 0, khong the chia" << endl;
            return SoPhuc(-1, -1);
        }
        double thucMoi = (dThuc * sp.dThuc + dAo * sp.dAo) / mau;
        double aoMoi = (dAo * sp.dThuc - dThuc * sp.dAo) / mau;
        return SoPhuc(thucMoi, aoMoi);
    }

    bool SoPhuc::operator==(const SoPhuc& sp) const {
        return dThuc == sp.dThuc && dAo == sp.dAo;
    }

    bool SoPhuc::operator!=(const SoPhuc& sp) const {
        return !(*this == sp);
    }
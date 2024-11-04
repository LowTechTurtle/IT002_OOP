#include<bits/stdc++.h>
#include "bai3.h"
using namespace std;

    int ThoiGian::TinhGiay() {
        return iGio * 3600 + iPhut * 60 + iGiay;
    }

    ThoiGian ThoiGian::TinhLaiGio(int Giay) {
        if (Giay <= 0) {
            return ThoiGian(0, 0, 0);
        }
        int gio = Giay / 3600;
        Giay = Giay - gio*3600;
        gio = gio % 24;
        int phut = Giay / 60;
        Giay = Giay - phut*60;
        return ThoiGian(gio, phut, Giay);
    }

    ThoiGian ThoiGian::operator+(int Giay) {
        return TinhLaiGio(Giay);
    }

    ThoiGian ThoiGian::operator-(int Giay) {
        return TinhLaiGio(-Giay);
    }

    ThoiGian ThoiGian::operator+(ThoiGian a) {
        return TinhLaiGio(this -> TinhGiay() + a.TinhGiay());
    }

    ThoiGian ThoiGian::operator-(ThoiGian a) {
        return TinhLaiGio(this -> TinhGiay() - a.TinhGiay());
    }

    ThoiGian ThoiGian::operator++() {
        ThoiGian giomoi = TinhLaiGio(this -> TinhGiay() + 1);
        this -> iGio = giomoi.iGio;
        this -> iPhut = giomoi.iPhut;
        this -> iGiay = giomoi.iGiay;
        return giomoi;
    }

    ThoiGian ThoiGian::operator--() {
        ThoiGian giomoi = TinhLaiGio(this -> TinhGiay() - 1);
        this -> iGio = giomoi.iGio;
        this -> iPhut = giomoi.iPhut;
        this -> iGiay = giomoi.iGiay;
        return giomoi;
    }

    bool ThoiGian::operator==(ThoiGian a) {
        return (iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay);
    }

    bool ThoiGian::operator!=(ThoiGian a) {
        if (this -> TinhGiay() == a.TinhGiay()) {
            return false;
        } else {
            return true;
        }
    }

    bool ThoiGian::operator>=(ThoiGian a) {
        return TinhGiay() >= a.TinhGiay();
    }

    bool ThoiGian::operator<=(ThoiGian a) {
        return TinhGiay() <= a.TinhGiay();
    }

    bool ThoiGian::operator>(ThoiGian a) {
        return TinhGiay() > a.TinhGiay();
    }

    bool ThoiGian::operator<(ThoiGian a) {
        return TinhGiay() < a.TinhGiay();
    }
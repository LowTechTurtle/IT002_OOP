#include<bits/stdc++.h>
#include "bai2.h"
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

    ThoiGian ThoiGian::operator++() {
        ThoiGian giomoi = TinhLaiGio(this -> TinhGiay() + 1);
        this -> iGio = giomoi.iGio;
        this -> iPhut = giomoi.iPhut;
        this -> iGiay = giomoi.iGiay;
        return giomoi;
    }


    istream& operator>>(istream& is, ThoiGian& tg) {
        cout << "Nhap gio: ";
        cin >> tg.iGio;
        while (tg.iGio < 0 || tg.iGio > 23) {
            cout << "Gio phai tu 0 den 23, hay nhap lai" << endl;
            cin >> tg.iGio;
        }
        cout << "Nhap phut: ";
        cin >> tg.iPhut;
        while (tg.iPhut < 0 || tg.iPhut > 59) {
            cout << "Phut phai tu 0 den 59, hay nhap lai" << endl;
            cin >> tg.iPhut;
        }
        cout << "Nhap giay: ";
        cin >> tg.iGiay;
        while (tg.iGiay < 0 || tg.iGiay > 59) {
            cout << "Giay phai tu 0 den 59, hay nhap lai" << endl;
            cin >> tg.iGiay;
        }
        return is;
    }

    ostream& operator<<(ostream& os, ThoiGian tg) {
        os << "Gio: " << tg.iGio << endl;
        os << "Phut: " << tg.iPhut << endl;
        os << "Giay: " << tg.iGiay << endl;
        return os;
    }
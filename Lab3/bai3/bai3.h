#include<bits/stdc++.h>
using namespace std;

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}
    ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    }

    int TinhGiay();

    ThoiGian TinhLaiGio(int Giay);

    ThoiGian operator+(int Giay);

    ThoiGian operator-(int Giay);

    ThoiGian operator+(ThoiGian a);

    ThoiGian operator-(ThoiGian a);

    ThoiGian operator++();

    ThoiGian operator--();

    bool operator==(ThoiGian a);;

    bool operator!=(ThoiGian a);

    bool operator>=(ThoiGian a);

    bool operator<=(ThoiGian a);

    bool operator>(ThoiGian a);

    bool operator<(ThoiGian a);

    friend istream& operator>>(istream& is, ThoiGian& tg) {
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

    friend ostream& operator<<(ostream& os, ThoiGian tg) {
        os << "Gio: " << tg.iGio << endl;
        os << "Phut: " << tg.iPhut << endl;
        os << "Giay: " << tg.iGiay << endl;
        return os;
    }
};
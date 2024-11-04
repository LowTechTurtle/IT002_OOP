#include<bits/stdc++.h>
#include "bai4.h"
using namespace std;

    int SoNgayTrongThang(int thang) {
        if (thang < 1 || thang > 12) {
            cout << "Thang khong hop le" << endl;
            return -1;
        }
        switch (thang) {
            case 1: 
                return 31;
            case 2:
                return 28;
            case 3: 
                return 31;
            case 4: 
                return 30;
            case 5: 
                return 31;
            case 6: 
                return 30;
            case 7: 
                return 31;
            case 8: 
                return 31;
            case 9: 
                return 30;
            case 10: 
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
        }
        return -1;
    }

    int NgayThangNam::TinhNgay() {
        int soNgay = iNgay;
        for (int i = 1; i < iThang; i++) {
            soNgay += SoNgayTrongThang(i);
        }
        soNgay += (iNam - 1) * 365;
        return soNgay;
    }

    NgayThangNam NgayThangNam::operator+(int ngay) {
        this -> iNgay += ngay;
        while (this -> iNgay > SoNgayTrongThang(iThang)) {
            this -> iNgay -= SoNgayTrongThang(iThang);
            if (this -> iThang < 12) {
                this -> iThang += 1;
            } else {
                this -> iThang = 1;
                this -> iNam += 1;
            }
        }
        return *this;
    }

    NgayThangNam NgayThangNam::operator-(int ngay) {
        this -> iNgay -= ngay;
        while (this -> iNgay < 1) {
            if (this -> iThang > 1) {
                this -> iNgay += SoNgayTrongThang(iThang-1);
                this -> iThang -= 1;
            } else {
                this -> iThang = 12;
                this -> iNgay += SoNgayTrongThang(iThang);
                this -> iNam -= 1;
            }
        }
        return *this;
    }

    int NgayThangNam::operator-(NgayThangNam a) {
        return this->TinhNgay() - a.TinhNgay();
    }

    NgayThangNam NgayThangNam::operator++() {
        if (this -> iNgay < SoNgayTrongThang(iThang)) {
            this -> iNgay++;
        } else {
            this -> iNgay = 1;
            this -> iThang += 1;
            if (this -> iThang > 12) {
                this -> iThang = 1;
                this -> iNam += 1;
            }
        }
        return *this;
    }

    NgayThangNam NgayThangNam::operator--() {
        if (this -> iNgay > 1) {
            this -> iNgay--;
        } else {
            if (this -> iThang > 1) {
                this -> iNgay = SoNgayTrongThang(iThang-1);
                this -> iThang -= 1;
            } else {
                this -> iThang = 12;
                this -> iNgay = SoNgayTrongThang(iThang);
                this -> iNam -= 1;
            }
        }
        return *this;
    }

    bool NgayThangNam::operator==(NgayThangNam a) {
        return (iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
    }

    bool NgayThangNam::operator!=(NgayThangNam a) {
        return !(iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
    }

    bool NgayThangNam::operator>=(NgayThangNam a) {
        return (TinhNgay() >= a.TinhNgay());
    }

    bool NgayThangNam::operator<=(NgayThangNam a) {
        return (TinhNgay() <= a.TinhNgay());
    }

    bool NgayThangNam::operator>(NgayThangNam a) {
        return (TinhNgay() > a.TinhNgay());
    }

    bool NgayThangNam::operator<(NgayThangNam a) {
        return (TinhNgay() < a.TinhNgay());
    }
    istream& operator>>(istream& is, NgayThangNam& ntn) {
        cout << "Nhap nam: ";
        cin >> ntn.iNam;
        while (ntn.iNam < 0) {
            cout << "Nam khong the am, hay nhap lai: " << endl;
            cin >> ntn.iNam;
        }

        cout << "Nhap thang: ";
        cin >> ntn.iThang;
        while (ntn.iThang < 1 || ntn.iThang > 12) {
            cout << "Thang tu 1 den 12, hay nhap lai" << endl;
            cin >> ntn.iThang;
        }

        cout << "Nhap ngay: ";
        cin >> ntn.iNgay;
        while (ntn.iNgay < 1 || ntn.iNgay > SoNgayTrongThang(ntn.iThang)) {
            cout << "Ngay trong thang khong hop le, hay nhap lai" << endl;
            cin >> ntn.iNgay;
        }
        return is;
    }

    ostream& operator<<(ostream& os, NgayThangNam ntn) {
        os << "Ngay: " << ntn.iNgay << endl;
        os << "Thang: " << ntn.iThang << endl;
        os << "Nam: " << ntn.iNam << endl;
        return os;
    }
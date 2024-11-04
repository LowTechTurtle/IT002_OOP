#include<bits/stdc++.h>
using namespace std;

int SoNgayTrongThang(int thang);

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    NgayThangNam() : iNgay(0), iThang(0), iNam(0) {}

    NgayThangNam(int nam, int thang, int ngay) {
        iNgay = ngay;
        iThang = thang;
        iNam = nam;
    }

    int TinhNgay();

    NgayThangNam operator+(int ngay);

    NgayThangNam operator-(int ngay);

    int operator-(NgayThangNam a);

    NgayThangNam operator++();

    NgayThangNam operator--();

    bool operator==(NgayThangNam a);

    bool operator!=(NgayThangNam a);

    bool operator>=(NgayThangNam a);

    bool operator<=(NgayThangNam a);

    bool operator>(NgayThangNam a);

    bool operator<(NgayThangNam a);

    friend istream& operator>>(istream& is, NgayThangNam& ntn);

    friend ostream& operator<<(ostream& os, NgayThangNam ntn);
};
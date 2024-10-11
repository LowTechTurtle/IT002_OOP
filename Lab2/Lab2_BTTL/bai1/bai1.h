#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    double iHoanh;
    double iTung;
public:
//constructor ko tham so
    Diem() {
        iHoanh = 0;
        iTung = 0;
    }

//constructor co tham so
    Diem(double Hoanh, double Tung) {
        iHoanh = Hoanh;
        iTung = Tung;
    }

//copy constructor
    Diem(const Diem &x) {
        iHoanh = x.iHoanh;
        iTung = x.iTung;
    }

    void Xuat();

// Tiep theo la 4 ham getter setter cho hoanh do va tung do

    double GetTungDo();

    double GetHoanhDo();

    void SetTungDo(double Tung);

    void SetHoanhDo(double Hoanh);

//tinh tien diem di 1 doan delta x va 1 doan delta y
    void TinhTien(double dx, double dy);
};

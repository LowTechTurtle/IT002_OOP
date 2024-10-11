#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    int iHoanh;
    int iTung;
public:
//constructor ko tham so
    Diem() {
        iHoanh = 0;
        iTung = 0;
    }

//constructor co tham so
    Diem(int Hoanh, int Tung) {
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

    int GetTungDo();

    int GetHoanhDo();

    void SetTungDo(int Tung);

    void SetHoanhDo(int Hoanh);

//tinh tien diem di 1 doan delta x va 1 doan delta y
    void TinhTien(int dx, int dy);
};

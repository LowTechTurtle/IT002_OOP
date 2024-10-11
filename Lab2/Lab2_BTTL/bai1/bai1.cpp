#include<bits/stdc++.h>
#include "bai1.h"
using namespace std;


    void Diem::Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")" << endl;
    }

    double Diem::GetTungDo() {
        return iTung;
    }

    double Diem::GetHoanhDo() {
        return iHoanh;
    }

    void Diem::SetTungDo(double Tung) {
        iTung = Tung;
    }

    void Diem::SetHoanhDo(double Hoanh) {
        iHoanh = Hoanh;
    }

    void Diem::TinhTien(double dx, double dy) {
        iHoanh += dx;
        iTung += dy;
    }

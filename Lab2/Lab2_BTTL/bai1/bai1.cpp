#include<bits/stdc++.h>
#include "bai1.h"
using namespace std;


    void Diem::Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")" << endl;
    }

    int Diem::GetTungDo() {
        return iTung;
    }

    int Diem::GetHoanhDo() {
        return iHoanh;
    }

    void Diem::SetTungDo(int Tung) {
        iTung = Tung;
    }

    void Diem::SetHoanhDo(int Hoanh) {
        iHoanh = Hoanh;
    }

    void Diem::TinhTien(int dx, int dy) {
        iHoanh += dx;
        iTung += dy;
    }
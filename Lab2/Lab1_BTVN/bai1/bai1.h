#include<bits/stdc++.h>
using namespace std;

class PhanSo{
private:
    int tuso;
    int mauso;

public:
    PhanSo(int tu = 0, int mau = 1) : tuso(tu), mauso(mau) {
    }

    int LayTu() const;

    int LayMau() const;

    PhanSo(const PhanSo &p) {
        this -> tuso = p.LayTu();
        this -> mauso = p.LayMau();
    }

    void GanTu(int t);

    void GanMau(int m);

    void Nhap();

    void Xuat();

    bool operator>(const PhanSo ps) const;
    bool operator<(const PhanSo ps) const;
    PhanSo operator+(const PhanSo ps) const;

    PhanSo operator-(const PhanSo ps) const;

};

class arrPhanSo {
private:
    vector<PhanSo> arr;

public:
    void nhap(int n);

    void xuat();

    PhanSo LayPS(int i);

    PhanSo LayPSLonNhat();

    PhanSo LayPSNhoNhat();
};

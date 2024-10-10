#include<bits/stdc++.h>
#include "bai1.h"
using namespace std;


    int PhanSo::LayTu() const {
        return this -> tuso;
    }

    int PhanSo::LayMau() const {
        return this -> mauso;
    }

    void PhanSo::GanTu(int t) {
        this -> tuso = t;
    }

    void PhanSo::GanMau(int m) {
        this -> mauso = m;
    }

    void PhanSo::Nhap() {
        cout << "Nhap tu so: ";
        cin >> this -> tuso;
        cout << "Nhap mau so: ";
        cin >> this -> mauso;
        while (this -> mauso == 0) {
            cout << "Mau khong the bang 0, nhap lai mau so: ";
            cin >> this -> mauso;
        }
    }

    void PhanSo::Xuat() {
        cout << tuso << "/" << mauso << endl;
    }
    bool PhanSo::operator>(const PhanSo ps) const {
        return (double)((double)tuso/(double)mauso) > (double)((double)(ps.LayTu())/(double)(ps.LayMau()));
    }

    bool PhanSo::operator<(const PhanSo ps) const {
        return (double)((double)tuso/(double)mauso) < (double)((double)(ps.LayTu())/(double)(ps.LayMau()));
    }
    PhanSo PhanSo::operator+(const PhanSo ps) const {
        return PhanSo(tuso * ps.LayMau() + mauso * ps.LayTu(), mauso * ps.LayMau());
    }
    PhanSo PhanSo::operator-(const PhanSo ps) const {
        return PhanSo(tuso * ps.LayMau() - mauso * ps.LayTu(), mauso * ps.LayMau());
    }



    void arrPhanSo::nhap(int n) {
        arr.clear();
        int tu, mau;
        for (int i = 0; i < n; ++i) {
            cout << "Nhap tu so cua ps thu " << i + 1 << ": ";
            cin >> tu;
            cout << "Nhap mau so cua ps thu " << i + 1 << ": ";
            cin >> mau;
            while (mau == 0) {
                cout << "Mau khong the bang 0, hay nhap lai: ";
                cin >> mau;
            }
            arr.push_back(PhanSo(tu, mau));
        }
    }

    void arrPhanSo::xuat() {
        for (PhanSo ps : arr) {
            ps.Xuat();
            cout << " ";
        }
        cout << endl;
    }

    PhanSo arrPhanSo::LayPS(int i) {
        return arr[i];
    }

    PhanSo arrPhanSo::LayPSLonNhat() {
        PhanSo psmax = arr[0];
        for (PhanSo ps: arr) {
            if (ps > psmax)
                psmax = ps;
        }
        return psmax;
    }

    PhanSo arrPhanSo::LayPSNhoNhat() {
        PhanSo psmin = arr[0];
        for (PhanSo ps: arr) {
            if (ps < psmin)
                psmin = ps;
        }
        return psmin;
    }

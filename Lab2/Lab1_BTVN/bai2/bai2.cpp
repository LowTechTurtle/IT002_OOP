#include<bits/stdc++.h>
#include "bai2.h"
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

    PhanSo arrPhanSo::LayPSLonThu(int k) {
        sort(arr.begin(), arr.end());
        if (k > arr.size()) {
            cout << "Khong co phan so lon thu " << k << endl;
        } else {
            cout << "Phan so lon thu " << k << " la ";
            arr[arr.size() - k].Xuat();
        }
        return arr[arr.size() - k];
    }

    PhanSo arrPhanSo::LayPSNhoThu(int k) {
        sort(arr.begin(), arr.end());
        if (k > arr.size()) {
            cout << "Khong co phan so nho thu " << k << endl;
        } else {
            cout << "Phan so nho thu " << k << " la ";
            arr[k-1].Xuat();
        }
        return arr[k];
    }

#include<bits/stdc++.h>
#include "bai1.h"
using namespace std;

    double NhanVien::TienThuong() {
        return 0;
    }

    void NhanVien::Xuat() {
        cout << "Ma so: " << maSo << endl;
        cout << "Ten: " << ten << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
    }

    double QuanLy::TienThuong() {
        return luongCoBan * tyLeThuong;
    }

    void QuanLy::Xuat() {
        NhanVien::Xuat();
        cout << "Ty le thuong: " << tyLeThuong << endl;
        cout << "Tien thuong: " << TienThuong() << endl;
    }

    double KySu::TienThuong() {
        return soGioLamThem * 100000;
    }

    void KySu::Xuat() {
        NhanVien::Xuat();
        cout << "So gio lam them: " << soGioLamThem << endl;
        cout << "Tien thuong: " << TienThuong() << endl;
    }

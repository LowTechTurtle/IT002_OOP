#include<bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string maNV;
    string ten;
    int tuoi;
    string sdt;
    string email;
    double luong;

public:
    NhanVien() {}

    virtual void nhap() {
        cout << "Nhap ma nhan vien: ";
        cin >> maNV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        cout << "Nhap email: ";
        cin >> email;
        cout << "Nhap luong co ban: ";
        cin >> luong;
    }

    virtual double tinhLuong() {
        return 0;
    }
    virtual void xuat() {
        return;
    }
};

class LapTrinhVien : public NhanVien {
private:
    int overtime;

public:
    LapTrinhVien() : overtime(0) {}

    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so gio lam them: ";
        cin >> overtime;
    }

    double tinhLuong() override {
        return luong + overtime * 200000;
    }

    void xuat() override {
        cout << "Lap Trinh Vien:\n";
        cout << "Ma NV: " << maNV << ", Ho Ten: " << ten << ", Tuoi: " << tuoi 
             << ", SDT: " << sdt << ", Email: " << email 
             << ", Luong: " << tinhLuong() << endl;
    }
};

class KiemChungVien : public NhanVien {
private:
    int soloi;

public:
    KiemChungVien() {}

    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so loi phat hien: ";
        cin >> soloi;
    }

    double tinhLuong() override {
        return luong + soloi * 50000;
    }

    void xuat() override {
        cout << "Kiem Chung Vien:\n";
        cout << "Ma NV: " << maNV << ", Ho Ten: " << ten << ", Tuoi: " << tuoi 
             << ", SDT: " << sdt << ", Email: " << email 
             << ", Luong: " << tinhLuong() << endl;
    }
};

double tinhLuongTB(const vector<NhanVien*>& danhSach) {
    double tongLuong = 0.0;
    for (NhanVien* nv : danhSach) {
        tongLuong += nv->tinhLuong();
    }
    return tongLuong / danhSach.size();
}

void nhanvienngheo(const vector<NhanVien*>& danhSach) {
    double luongTrungBinh = tinhLuongTB(danhSach);
    cout << "Danh sach nhan vien co luong thap hon trung binh (" << luongTrungBinh << "):\n";
    for (NhanVien* nv : danhSach) {
        if (nv->tinhLuong() < luongTrungBinh) {
            nv->xuat();
        }
    }
}

int main() {
    vector<NhanVien*> danhSachNhanVien;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loaiNV;
        cout << "\nNhap loai nhan vien (1: Lap trinh vien, 2: Kiem chung vien): ";
        cin >> loaiNV;

        NhanVien* nv = nullptr;
        if (loaiNV == 1) {
            nv = new LapTrinhVien();
        } else if (loaiNV == 2) {
            nv = new KiemChungVien();
        } else {
            cout << "Loai nhan vien khong hop le! Vui long nhap lai.\n";
            --i;
            continue;
        }

        nv->nhap();
        danhSachNhanVien.push_back(nv);
    }

    cout << "\nDanh sach nhan vien:\n";
    for (NhanVien* nv : danhSachNhanVien) {
        nv->xuat();
    }

    nhanvienngheo(danhSachNhanVien);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class CanBoVienChuc {
protected:
    string ma;
    string ten;
    string gioiTinh;

public:
    CanBoVienChuc(string ma, string ten, string gt) : ma(ma), ten(ten), gioiTinh(gt) {}

    virtual ~CanBoVienChuc() {}

    virtual double tinhLuong() {
        return 0;
    }

    virtual void hienThiThongTin() {
        return;
    }
};

class GiangVien : public CanBoVienChuc {
private:
    int gioday;
    int gioNC;
    double donGia;

public:
    GiangVien(string ma, string ten, string gt, int gioday, int gioNC, double dg)
        : CanBoVienChuc(ma, ten, gt), gioday(gioday), gioNC(gioNC), donGia(dg) {}

    double tinhLuong() override {
        return (gioday + gioNC) * donGia;
    }

    void hienThiThongTin() override {
        cout << "Giang Vien: " << ten << " | Ma Can Bo: " << ma << " | Gioi Tinh: " << gioiTinh
             << " | Luong: " << tinhLuong() << endl;
    }
};

class NhanVienHanhChinh : public CanBoVienChuc {
private:
    int songay;
    int sogio;
    double tiencong;
    double dongia;

public:
    NhanVienHanhChinh(string ma, string ten, string gt, int ngayLV, int gioLT, double tienCong, double donGiaLT)
        : CanBoVienChuc(ma, ten, gt), songay(ngayLV), sogio(gioLT), tiencong(tienCong), dongia(donGiaLT) {}

    double tinhLuong() override {
        return songay * tiencong + sogio * dongia;
    }

    void hienThiThongTin() override {
        cout << "Nhan Vien Hanh Chinh: " << ten << " | Ma Can Bo: " << ma << " | Gioi Tinh: " << gioiTinh
             << " | Luong: " << tinhLuong() << endl;
    }
};

int main() {
    vector<CanBoVienChuc*> danhSachCanBo;

    danhSachCanBo.push_back(new GiangVien("001", "Nguyen Van A", "Nam", 10, 20, 200000));
    danhSachCanBo.push_back(new GiangVien("002", "Nguyen Thi B", "Nu", 20, 30, 200000));
    danhSachCanBo.push_back(new NhanVienHanhChinh("003", "Nguyen Van C", "Nam", 20, 5, 150000, 50000));
    danhSachCanBo.push_back(new NhanVienHanhChinh("004", "Nguyen Thi D", "Nu", 25, 10, 150000, 50000));

    for (CanBoVienChuc* cb : danhSachCanBo) {
        cb->hienThiThongTin();
    }

    return 0;
}

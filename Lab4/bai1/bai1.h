#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maSo;
    string ten;
    double luongCoBan;

public:
    NhanVien(const string& ms, const string& t, double lcb)
        : maSo(ms), ten(t), luongCoBan(lcb) {}

    virtual double TienThuong() = 0;
    virtual void Xuat();
};

class QuanLy : public NhanVien {
private:
    double tyLeThuong;

public:
    QuanLy(const string& ms, const string& t, double lcb, double tl)
        : NhanVien(ms, t, lcb), tyLeThuong(tl) {}

    double TienThuong() override;

    void Xuat() override;
};

class KySu : public NhanVien {
private:
    int soGioLamThem;

public:
    KySu(const string& ms, const string& t, double lcb, int gio)
        : NhanVien(ms, t, lcb), soGioLamThem(gio) {}

    double TienThuong() override;

    void Xuat() override;
};

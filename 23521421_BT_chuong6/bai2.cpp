#include<bits/stdc++.h>
using namespace std;

class SinhVien {
protected:
    string mssv;
    string ten;
    string diachi;
    int tinchi;
    double diemTB;

public:
    SinhVien(string ma, string ten, string diachi, int tinchi, double diemTB)
        : mssv(ma), ten(ten), diachi(diachi), tinchi(tinchi), diemTB(diemTB) {}

    virtual bool totnghiep() = 0;
    virtual void xuat() = 0;
};

class SinhVienCaoDang : public SinhVien {
private:
    double diemTN;

public:
    SinhVienCaoDang(string ma, string ten, string diachi, int tinchi, double diemTB, double diemTN)
        : SinhVien(ma, ten, diachi, tinchi, diemTB), diemTN(diemTN) {}

    bool totnghiep() override {
        return tinchi >= 120 && diemTB >= 5.0 && diemTN >= 5.0;
    }

    void xuat() override {
        cout << "Sinh Vien Cao Dang:\n";
        cout << "Ma SV: " << mssv << ", Ho Ten: " << ten << ", Dia Chi: " << diachi
             << ", Tong Tin Chi: " << tinchi << ", Diem TB: " << diemTB
             << ", Diem Thi Tot Nghiep: " << diemTN << endl;
        cout << (totnghiep() ? "Du dieu kien tot nghiep.\n" : "Khong du dieu kien tot nghiep.\n");
    }
};

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLV;
    double diemLV;

public:
    SinhVienDaiHoc(string ma, string ten, string diachi, int tinchi, double diemTB, string luanVan, double diemLV)
        : SinhVien(ma, ten, diachi, tinchi, diemTB), tenLV(luanVan), diemLV(diemLV) {}

    bool totnghiep() override {
        return tinchi >= 170 && diemTB >= 5.0 && diemLV >= 5.0;
    }

    void xuat() override {
        cout << "Sinh Vien Dai Hoc:\n";
        cout << "Ma SV: " << mssv << ", Ho Ten: " << ten << ", Dia Chi: " << diachi
             << ", Tong Tin Chi: " << tinchi << ", Diem TB: " << diemTB
             << ", Ten Luan Van: " << tenLV << ", Diem Luan Van: " << diemLV << endl;
        cout << (totnghiep() ? "Du dieu kien tot nghiep.\n" : "Khong du dieu kien tot nghiep.\n");
    }
};

int main() {
    int tinchi;
    string mssv, ten, diachi, tenLV;
    double diemTB, diemTN, diemLV;
    cout << "Nhap mssv cho SV Cao Dang: ";
    getline(cin, mssv);
    cout << "Nhap ten cho SV Cao Dang: ";
    getline(cin, ten);
    cout << "Nhap dia chi cho SV Cao Dang: ";
    getline(cin, diachi);
    cout << "Nhap so tin chi cua SV Cao Dang: ";
    cin >> tinchi;
    cout << "Nhap diem trung binh cua SV Cao Dang: ";
    cin >> diemTB;
    cout << "Nhap diem tot nghiep cua SV Cao Dang: ";
    cin >> diemTN;
    SinhVienCaoDang svCaoDang(mssv, ten, diachi, tinchi, diemTB, diemTN);

    cout << "Nhap mssv cho SV Dai Hoc: ";
    cin.ignore();
    getline(cin, mssv);
    cout << "Nhap ten cho SV Dai Hoc: ";
    getline(cin, ten);
    cout << "Nhap dia chi cho SV Dai Hoc: ";
    getline(cin, diachi);
    cout << "Nhap so tin chi cua SV Dai Hoc: ";
    cin >> tinchi;
    cout << "Nhap diem trung binh cua SV Dai Hoc: ";
    cin >> diemTB;
    cout << "Nhap ten luan van cua SV Dai Hoc: ";
    cin.ignore();
    getline(cin, tenLV);
    cout << "Nhap diem luan van cua SV Dai Hoc: ";
    cin >> diemLV;
    SinhVienDaiHoc svDaiHoc(mssv, ten, diachi, tinchi, diemTB, tenLV, diemLV);

    svCaoDang.xuat();
    svDaiHoc.xuat();

    return 0;
}

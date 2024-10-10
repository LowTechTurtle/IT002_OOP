#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cBook {
public:
    string maSach;
    string tenSach;
    int namXuatBan;
    int tongSoTrang;
    cBook(string maSach = "", string tenSach = "", int namXuatBan = 0, int tongSoTrang = 0) 
        : maSach(maSach), tenSach(tenSach), namXuatBan(namXuatBan), tongSoTrang(tongSoTrang) {}

    void nhap() {
        cout << "Nhap ma sach : ";
        getline(cin, maSach);
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap tong so trang sach: ";
        cin >> tongSoTrang;
        cin.ignore();
    }

    void xuat() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "Tong so trang: " << tongSoTrang << endl;
    }

};

class cListBook {
public:
    vector<cBook> danhSach; 
    void nhapDanhSach(int soLuong) {
        for (int i = 0; i < soLuong; ++i) {
            cout << "Nhap sach thu " << i + 1 << ":\n";
            cBook sach;
            sach.nhap();
            danhSach.push_back(sach);
        }
    }

    void xuatDanhSach() {
        for (int i = 0; i < danhSach.size(); ++i) {
            cout << "Sach thu : " << i + 1 << ":\n";
            danhSach[i].xuat();
            cout << endl;
        }
    }

    void timSachMoiNhat() {
        int index = 0;
        for (int i = 1; i < danhSach.size(); ++i) {
            if (danhSach[i].namXuatBan > danhSach[index].namXuatBan) {
                index = i;
            }
        }

        cout << "Thong tin sach moi nhat:\n";
        danhSach[index].xuat();
    }
};

int main() {
    int soLuong;

    cout << "Nhap so sach: ";
    cin >> soLuong;
    cin.ignore();

    cListBook danhSachSach;

    danhSachSach.nhapDanhSach(soLuong);

    danhSachSach.xuatDanhSach();

    danhSachSach.timSachMoiNhat();

    return 0;
}

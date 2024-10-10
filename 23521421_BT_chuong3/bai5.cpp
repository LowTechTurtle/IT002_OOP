#include<bits/stdc++.h>
using namespace std;

class cHocSinh {
public:
    string maHS;       
    string hoTen;    
    string gioiTinh;
    int namSinh;  
    float diemTB;

    void nhapThongTin() {
        cout << "Nhap ma hoc sinh ";
        getline(cin, maHS);
        cout << "Nhap ten: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh( nam, nu): ";
        getline(cin, gioiTinh);
        cout << "Nhap nam sinh";
        cin >> namSinh;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
        cin.ignore(); 
    }

    void soTuoi(cHocSinh hs) {
        if (this -> namSinh < hs.namSinh) {
            cout << hs.hoTen << " nho tuoi hon " << this -> hoTen << endl;
        } else if (this -> namSinh > hs.namSinh) {
            cout << hs.hoTen << " lon tuoi hon " << this -> hoTen << endl;
        } else {
            cout << hs.hoTen << " bang tuoi " << this -> hoTen << endl;
        }
    }

    void soDTB(cHocSinh hs) {
        if (this -> diemTB < hs.diemTB) {
            cout << hs.hoTen << " co diem trung binh cao hon " << this -> hoTen << endl;
        } else if (this -> diemTB > hs.diemTB) {
            cout << hs.hoTen << " co diem trung binh thap hon " << this -> hoTen << endl;
        } else {
            cout << hs.hoTen << " co diem trung binh bang " << this -> hoTen << endl;
        }
    }
};

int main() {
    cHocSinh hs1, hs2;
    cout << "Nhap thong tin cho hoc sinh thu nhat:" << endl;
    hs1.nhapThongTin();

    cout << "Nhap thong tin cho hoc sinh thu hai:" << endl;
    hs2.nhapThongTin();

    hs1.soTuoi(hs2);
    hs1.soDTB(hs2);

    return 0;
}
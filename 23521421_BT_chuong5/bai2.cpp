#include<bits/stdc++.h>
using namespace std;

class PhanSo{
private:
    int tuso;
    int mauso;

public:
    PhanSo(int tu = 0, int mau = 1) : tuso(tu), mauso(mau) {
    }

    int LayTu() const {
        return this -> tuso;
    }

    int LayMau() const {
        return this -> mauso;
    }

    PhanSo(const PhanSo &p) {
        this -> tuso = p.LayTu();
        this -> mauso = p.LayMau();
    }

    void GanTu(int t) {
        this -> tuso = t;
    }

    void GanMau(int m) {
        this -> mauso = m;
    }

    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> this -> tuso;
        cout << "Nhap mau so: ";
        cin >> this -> mauso;
        while (this -> mauso == 0) {
            cout << "Mau khong the bang 0, nhap lai mau so: ";
            cin >> this -> mauso;
        }
    }

    void Xuat() {
        cout << tuso << "/" << mauso << endl;
    }
    bool operator>(const PhanSo ps) const {
        return (double)((double)tuso/(double)mauso) > (double)((double)(ps.LayTu())/(double)(ps.LayMau()));
    }

    PhanSo operator+(const PhanSo ps) const {
        return PhanSo(tuso * ps.LayMau() + mauso * ps.LayTu(), mauso * ps.LayMau());
    }
    PhanSo operator-(const PhanSo ps) const {
        return PhanSo(tuso * ps.LayMau() - mauso * ps.LayTu(), mauso * ps.LayMau());
    }

};

class arrPhanSo {
private:
    vector<PhanSo> arr;

public:
    void nhap(int n) {
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

    void xuat() {
        for (PhanSo ps : arr) {
            ps.Xuat();
            cout << " ";
        }
        cout << endl;
    }

    PhanSo LayPS(int i) {
        return arr[i];
    }

    PhanSo LayPSLonNhat() {
        PhanSo psmax = arr[0];
        for (PhanSo ps: arr) {
            if (ps > psmax)
                psmax = ps;
        }
        return psmax;
    }
};

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;
    arrPhanSo a;
    a.nhap(n);
    cout << "Phan so lon nhat la: " << endl;
    a.LayPSLonNhat().Xuat();
    return 0;
}
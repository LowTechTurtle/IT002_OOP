#include<bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string name;
    string birthday;
    double salary;

public:
    NhanVien(string name, string birthday, double salary) : name(name), birthday(birthday), salary(salary) {}

    virtual ~NhanVien() {}

    virtual double calculateSalary() const {return 0;};

    virtual void displayInfo() const {
        cout << "Ten: " << name << endl;
        cout << "Ngay sinh: " << birthday << endl; 
        cout << "Luong: " << calculateSalary() << endl;
    }

    string getName() const {
        return name;
    }
};

class NhanVienVP : public NhanVien {
private:
    int so_ngay_lam;
    double tro_cap;

public:
    NhanVienVP(string name, string birthday, double salary, int so_ngay_lam, double tro_cap)
        : NhanVien(name, birthday, salary), so_ngay_lam(so_ngay_lam), tro_cap(tro_cap) {}

    double calculateSalary() const override {
        return salary + so_ngay_lam * 200000 + tro_cap;
    }
};

class NhanVienSX : public NhanVien {
private:
    int SoSP;

public:
    NhanVienSX(string name, string birthday, double salary, int SoSP)
        : NhanVien(name, birthday, salary), SoSP(SoSP) {}

    double calculateSalary() const override {
        return salary + SoSP * 2000;
    }
};

class NhanVienQL : public NhanVien {
private:
    double HSCV; //he so chuc vu
    double thuong;

public:
    NhanVienQL(string name, string birthday, double salary, double HSCV, double thuong)
        : NhanVien(name, birthday, salary), HSCV(HSCV), thuong(thuong) {}

    double calculateSalary() const override {
        return salary * HSCV + thuong;
    }
};

int main() {
    int nvvp, nvsx, nvql;
    cout << "Nhap so nhan vien van phong: ";
    cin >> nvvp;
    cout << "Nhap so nhan vien san xuat: ";
    cin >> nvsx;
    cout << "Nhap so nhan vien quan ly: ";
    cin >> nvql;\

    vector<NhanVienVP> vp;
    vector<NhanVienSX> sx;
    vector<NhanVienQL> ql;
    for (int i = 0; i < nvvp; i++) {
        string name, birthday;
        double salary, tro_cap;
        int so_ngay_lam;
        cout << "Nhap thong tin nhan vien VP thu " << i+1 << endl;
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap ngay sinh nhat: ";
        getline(cin, birthday);
        cout << "Nhap luong: ";
        cin >> salary;
        cout << "Nhap tro cap: ";
        cin >> tro_cap;
        cout << "Nhap so ngay lam: ";
        cin >> so_ngay_lam;
        vp.push_back(NhanVienVP(name, birthday, salary, so_ngay_lam, tro_cap));
    }

    for (int i = 0; i < nvsx; i++) {
        string name, birthday;
        double salary;
        int so_sp;
        cout << "Nhap thong tin nhan vien SX thu " << i+1 << endl;
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap ngay sinh nhat: ";
        getline(cin, birthday);
        cout << "Nhap luong: ";
        cin >> salary;
        cout << "Nhap so san pham: ";
        cin >> so_sp;
        sx.push_back(NhanVienSX(name, birthday, salary, so_sp));
    }

    for (int i = 0; i < nvql; i++) {
        string name, birthday;
        double salary, hscv;
        int thuong;
        cout << "Nhap thong tin nhan vien QL thu " << i+1 << endl;
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap ngay sinh nhat: ";
        getline(cin, birthday);
        cout << "Nhap luong: ";
        cin >> salary;
        cout << "Nhap he so chuc vu: ";
        cin >> hscv;
        cout << "Nhap thuong: ";
        cin >> thuong;
        ql.push_back(NhanVienQL(name, birthday, salary, hscv, thuong));
    }

    for (int i = 0; i < nvvp; i++) {
        cout << "Thong tin nhan vien VP thu " << i+1 << ":" << endl;
        vp[i].displayInfo();
    }

    for (int i = 0; i < nvsx; i++) {
        cout << "Thong tin nhan vien SX thu " << i+1 << ":" << endl;
        sx[i].displayInfo();
    }
    for (int i = 0; i < nvql; i++) {
        cout << "Thong tin nhan vien QL thu " << i+1 << ":" << endl;
        ql[i].displayInfo();
    }

    int sum = 0;
    for (int i = 0; i < nvvp; i++) {
        sum += vp[i].calculateSalary();
    }
    for (int i = 0; i < nvsx; i++) {
        sum += sx[i].calculateSalary();
    }
    for (int i = 0; i < nvql; i++) {
        sum += ql[i].calculateSalary();
    }
    cout << "Tong luong cua ca cong ty la: " << sum << endl;

    string findname;
    cout << "Nhap ho ten cua nhan vien: ";
    cin.ignore();
    getline(cin, findname);
    for (int i = 0; i < nvvp; i++) {
        if (vp[i].getName() == findname) {
            cout << "Thong tin nhan vien can tim la: " << endl;
            vp[i].displayInfo();
        }
    }
    for (int i = 0; i < nvsx; i++) {
        if (sx[i].getName() == findname) {
            cout << "Thong tin nhan vien can tim la: " << endl;
            sx[i].displayInfo();
        }
    }
    for (int i = 0; i < nvql; i++) {
        if (ql[i].getName() == findname) {
            cout << "Thong tin nhan vien can tim la: " << endl;
            ql[i].displayInfo();
        }
    }
    return 0;
}
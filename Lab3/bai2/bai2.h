#include<bits/stdc++.h>
using namespace std;

class SoPhuc {
private:
    double dThuc;
    double dAo;

public:
    SoPhuc() {
        dThuc = 0;
        dAo = 0;
    }

    SoPhuc(double thuc, double ao) {
        dThuc = thuc;
        dAo = ao;
    }

    SoPhuc operator+(const SoPhuc& sp) const;

    SoPhuc operator-(const SoPhuc& sp) const;

    SoPhuc operator*(const SoPhuc& sp) const;

    SoPhuc operator/(const SoPhuc& sp) const;

    bool operator==(const SoPhuc& sp) const;

    bool operator!=(const SoPhuc& sp) const;

    friend istream& operator>>(istream& is, SoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        is >> sp.dThuc;
        cout << "Nhap phan ao: ";
        is >> sp.dAo;
        return is;
    }

    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        os << sp.dThuc;
        if (sp.dAo >= 0) {
            os << " + " << sp.dAo << "i";
        } else {
            os << " - " << abs(sp.dAo) << "i";
        }
        return os;
    }
};
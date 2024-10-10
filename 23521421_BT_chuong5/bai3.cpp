#include<bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int n;
    vector<double> heSo;

public:
    int layBac() const {
        return  n;
    }
    int layheSo(int i) const {
        return heSo[i];
    }
    DaThuc(int bac) {
        n = bac;
        heSo.resize(n + 1);
    }

    double tinhGiaTri(double x) const {
        double result = 0;
        for (int i = 0; i <= n; ++i) {
            result += heSo[i] * pow(x, n - i);
        }
        return result;
    }

    friend istream &operator>>(istream &is, DaThuc &dt) {
        for (int i = 0; i <= dt.n; ++i) {
            cout << "He so cua x^" << dt.n - i << ": ";
            is >> dt.heSo[i];
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const DaThuc &dt) {
        bool first = true;
        for (int i = dt.layBac(); i >= 0; --i) {
            if (dt.layheSo(i) != 0) {
                if (!first && dt.layheSo(i) > 0) {
                    cout << " + ";
                } else if (dt.layheSo(i) < 0) {
                    cout << " - ";
                }
                cout << abs(dt.layheSo(i));
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
                first = false;
            }
        }
        if (first) {
            cout << "0";
        }
        cout << endl;
        return os;
    }

    DaThuc operator+(const DaThuc &other) const {
        int maxBac = max(n, other.n);
        DaThuc result(maxBac);

        for (int i = 0; i <= maxBac; ++i) {
            int bacThis = n - i;
            int bacOther = other.n - i;

            if (bacThis >= 0) result.heSo[maxBac - i] += heSo[n - bacThis];
            if (bacOther >= 0) result.heSo[maxBac - i] += other.heSo[other.n - bacOther];
        }
        return result;
    }

    DaThuc operator-(const DaThuc &other) const {
        int maxBac = max(n, other.n);
        DaThuc result(maxBac);

        for (int i = 0; i <= maxBac; ++i) {
            int bacThis = n - i;
            int bacOther = other.n - i;

            if (bacThis >= 0) result.heSo[maxBac - i] += heSo[n - bacThis];
            if (bacOther >= 0) result.heSo[maxBac - i] -= other.heSo[other.n - bacOther];
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Nhap bac cua da thuc thu nhat:\n";
    cin >> n;
    DaThuc dt1(n);
    cin >> dt1;

    cout << "Nhap bac cua da thuc thu hai:\n";
    cin >> n;
    DaThuc dt2(n);
    cin >> dt2;

    cout << "Da thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    DaThuc dtSum = dt1 + dt2;
    cout << "Tong cua hai da thuc: " << dtSum << endl;

    DaThuc dtMinus = dt1 - dt2;
    cout << "Hieu cua hai da thuc: " << dtMinus << endl;

    double x;
    cout << "Nhap gia tri cua x de tinh gia tri da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class PhanSo {
public:
    int Tu, Mau;

    PhanSo() {}
    
    PhanSo(int Tu, int Mau) {
        if (Mau != 0) { 
        this -> Tu = Tu;
        this -> Mau = Mau;
        }
    }
    
};

pair<double, double> TinhTongVaTimMax(int n, PhanSo vps[]) {
    double Sum = 0;
    double max = (double)((double)vps[0].Tu / (double)vps[0].Mau);
    for (int i = 0; i < n; i++) {
        Sum += (double)((double)vps[i].Tu / (double)vps[i].Mau);
        if (max < (double)((double)vps[i].Tu / (double)vps[i].Mau)) {
            max = (double)((double)vps[i].Tu / (double)vps[i].Mau);
        }
    }
    pair<double, double> p(Sum, max);
    return p;
}  

int main() {
    int n, a, b;
    cin >> n;
    PhanSo A[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        A[i].Tu = a;
        A[i].Mau = b;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i].Tu << "/" << A[i].Mau << endl;
    }
    pair<double, double> p;
    p = TinhTongVaTimMax(n, A);
    cout << "Tong la " << p.first << " Phan so lon nhat la " << p.second << endl;
    return 0;
}
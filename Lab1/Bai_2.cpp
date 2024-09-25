#include<bits/stdc++.h>
using namespace std;

struct PhanSo {
    int Tu_so;
    int Mau_so;
    
};

int main() {
    PhanSo ps1, ps2;

    cin >> ps1.Tu_so >> ps1.Mau_so;
    cin >> ps2.Tu_so >> ps2.Mau_so;

    if (ps1.Mau_so == 0 || ps2.Mau_so == 0) {
        cout << "Mau so bang 0" << endl;
        return 0;
    }
    
    float x1 = ps1.Tu_so / ps1.Mau_so;
    float x2 = ps2.Tu_so / ps2.Mau_so;

    
    if (x1 > x2) {
        cout << "Phan so lon hon: " << ps1.Tu_so << "/" << ps1.Mau_so << endl;
    } else {
        cout << "Phan so lon hon: " << ps2.Tu_so << "/" << ps2.Mau_so << endl;
    }

    return 0;
}
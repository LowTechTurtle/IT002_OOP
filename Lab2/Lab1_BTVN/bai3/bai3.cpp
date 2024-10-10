#include<bits/stdc++.h>
#include "bai3.h"
using namespace std;

    void PhanSo::rutGon() {
        long long gcd_val = __gcd(tu, mau);
        tu /= gcd_val;
        mau /= gcd_val;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
    
    PhanSo PhanSo::operator*(const PhanSo& other) const {
        return PhanSo(tu * other.tu, mau * other.mau);
    }
    
    bool PhanSo::operator<(const PhanSo& other) const {
        return tu * other.mau < mau * other.tu;
    }

    bool PhanSo::operator>(const PhanSo& other) const {
        return tu * other.mau > mau * other.tu;
    }

    bool PhanSo::operator==(const PhanSo& other) const {
        return tu * other.mau == mau * other.tu;
    }

void timTapCon(vector<PhanSo> arr, PhanSo dich) {
    bool found = false; //tim thay hay chua
    int n = arr.size();
    vector<PhanSo> ans;
    
// lay 2^n truong hop cua tap con
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<PhanSo> tapcon;
        PhanSo tich(1, 1);
        
//lay tung phan so theo mask 
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                tapcon.push_back(arr[i]);
                tich = tich * arr[i];
                tich.rutGon();
            }
        }
        
        if (tich == dich) {
            found = true;
            if (ans.empty() || tapcon.size() < ans.size()) {
                ans = tapcon;
            }
        }
    }
    
    if (!found) {
        cout << "Ko co tap con nao thoa man" << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << "Tap hop con nho nhat co tich bang phan so dich: " << endl;
        for (auto ps : ans) {
            cout << ps.tu << "/" << ps.mau << " ";
        }
        cout << endl;
    }
}
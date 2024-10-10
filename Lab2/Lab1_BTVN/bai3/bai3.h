#include<bits/stdc++.h>
using namespace std;

class PhanSo {
public:
    long long tu, mau;
    
    PhanSo(long long tu = 0, long long mau = 1) : tu(tu), mau(mau) {}
    
    void rutGon();

    PhanSo operator*(const PhanSo& other) const;
    
    bool operator<(const PhanSo& other) const;

    bool operator>(const PhanSo& other) const;

    bool operator==(const PhanSo& other) const;
};

void timTapCon(vector<PhanSo> arr, PhanSo phanSoDich);

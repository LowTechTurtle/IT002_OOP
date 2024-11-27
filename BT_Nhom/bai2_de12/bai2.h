#include<bits/stdc++.h>
using namespace std;

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

    ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    }

    int TinhGiay();

    ThoiGian TinhLaiGio(int Giay);

    ThoiGian operator++();

    friend istream& operator>>(istream& is, ThoiGian& tg);

    friend ostream& operator<<(ostream& os, ThoiGian tg);

};
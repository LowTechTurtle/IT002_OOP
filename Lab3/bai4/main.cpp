#include<bits/stdc++.h>
#include "bai4.cpp"
using namespace std;

int main() {
    NgayThangNam ngay1, ngay2;

    cout << "Nhap ngay thu nhat:" << endl;
    cin >> ngay1;

    cout << "Nhap ngay thu hai:" << endl;
    cin >> ngay2;
    cout << "Ngay1: " << ngay1 << endl;
    cout << "Ngay2: " << ngay2 << endl;

    if (ngay1 < ngay2) {
        cout << "Ngay thu nhat den truoc" << endl;
    } else if ( ngay1> ngay2 ){
        cout << "Ngay thu hai den truoc" << endl;
    }
    else if (ngay1 == ngay2){
        cout<< "Hai ngay vua nhap la cung 1 ngay" <<endl;
    }
    ngay1 = ngay1 + 100;
    cout << "Ngay thu nhat sau 100 ngay: " << ngay1 << endl;

    ngay2 = ngay2 - 100;
    cout << "100 ngay truoc ngay thu hai: " << ngay2 << endl;

    ++ngay1;
    cout << "Ngay sau cua ngay thu nhat: " << ngay1 << endl;

    --ngay2;
    cout << "Ngay truoc cua ngay thu hai: " << ngay2 << endl;
    return 0;
}

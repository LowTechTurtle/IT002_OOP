#include<bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

int main() {
    ThoiGian t1, t2;

    cout << "Nhap thoi diem dau tien" << endl;
    cin>>t1;
    cout << "Nhap thoi diem thu hai" << endl;
    cin>>t2;

    if (t1 < t2) {
        cout << "Thoi diem dau tien som hon" << endl;
    } else if (t1 == t2) {
        cout << "Hai thoi diem bang nhau" << endl;
    } else {
        cout << "Thoi diem dau tien muon hon" << endl;
    }

    ++t1;
    cout << "Thoi diem dau tien sau khi tang 1 giay:" << endl << t1;

    --t2;
    cout << "Thoi diem thu hai sau khi giam 1 giay:" << endl << t2;
    return 0;
}

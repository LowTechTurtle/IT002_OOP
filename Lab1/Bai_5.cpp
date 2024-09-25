#include<bits/stdc++.h>
using namespace std;

int main() {
    int days_of_month[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d, m;
    cin >> d >> m;

    if (d == days_of_month[m-1]) {
        cout << "Ngay ke tiep la ngay 1" << endl;
    }  else {
        cout << "Ngay ke tiep la ngay " << d+1 << endl;
    }

    if (d == 1) {
        if (m == 1) {
            cout << "Ngay truoc la ngay 31" << endl;
        } else {
            cout << "Ngay truoc la ngay " << days_of_month[m-1] << endl;
        }
    }  else {
        cout << "Ngay truoc la ngay " << d-1 << endl;
    }

    int num_of_days = 0;
    for (int i = 0; i < m - 1; i++) {
        num_of_days += days_of_month[i];
    }
    num_of_days += d;
    cout << "Ngay " << d << " thang " << m << " la ngay thu " << num_of_days << " trong nam" << endl;
    return 0;
}
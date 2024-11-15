#include<bits/stdc++.h>
#include "bai2.cpp"
using namespace std;

int main() {
    Deluxe a(1, 200000, 30000);
    Deluxe b(2, 300000, 40000);
    Premium c(3, 40000);
    Premium d(5, 60000);
    Business e(7);

    int deluxe = a.revenue() + b.revenue();
    int premium = c.revenue() + d.revenue();
    int business = e.revenue();

    string maxRoom;
    int max = max({deluxe, premium, business});
    
    if (max == deluxe) {
        max = "Deluxe";
    } else if (max == premium) {
        maxRoom = "Premium";
    } else {
        maxRoom = "Business";
    }

    cout << "Loai phong co doanh thu  cao nhat la " << maxRoom
         << " voi doanh thu la " << max << endl;

    return 0;
}
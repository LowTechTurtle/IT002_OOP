#include<bits/stdc++.h>
#include "bai2.cpp"
using namespace std;

int main() {
    Deluxe a(5, 100000, 50000);  // 5 đêm, phí dịch vụ 100000, phí phục vụ 50000
    Deluxe b(3, 200000, 70000);  // 3 đêm, phí dịch vụ 200000, phí phục vụ 70000
    Premium c(4, 50000);         // 4 đêm, phí dịch vụ 50000
    Premium d(2, 30000);         // 2 đêm, phí dịch vụ 30000
    Business e(7);               // 7 đêm, không có phí dịch vụ

    int deluxeRevenue = a.revenue() + b.revenue();
    int premiumRevenue = c.revenue() + d.revenue();
    int businessRevenue = e.revenue();

    string maxRoomType;
    int maxRevenue = max({deluxeRevenue, premiumRevenue, businessRevenue});
    
    if (maxRevenue == deluxeRevenue) {
        maxRoomType = "Deluxe";
    } else if (maxRevenue == premiumRevenue) {
        maxRoomType = "Premium";
    } else {
        maxRoomType = "Business";
    }

    cout << "Loại phòng có doanh thu cao nhất là " << maxRoomType 
         << " với doanh thu là " << maxRevenue << " VNĐ." << endl;

    return 0;
}
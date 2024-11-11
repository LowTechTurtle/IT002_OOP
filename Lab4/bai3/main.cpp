#include<bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

int main() {
    srand(time(0));  // Khởi tạo seed cho số ngẫu nhiên

    int cowQty, sheepQty, goatQty;
    cout << "Nhập số lượng bò: ";
    cin >> cowQty;
    cout << "Nhập số lượng cừu: ";
    cin >> sheepQty;
    cout << "Nhập số lượng dê: ";
    cin >> goatQty;

    Cow cowFarm(cowQty);
    Sheep sheepFarm(sheepQty);
    Goat goatFarm(goatQty);

    // a) Các gia súc phát ra tiếng kêu khi đói
    cout << "\nTất cả gia súc đều đói và kêu:\n";
    cowFarm.makeSound();
    sheepFarm.makeSound();
    goatFarm.makeSound();

    // b) Thống kê sau một lượt sinh sản và cho sữa
    cowFarm.reproduce();
    cowFarm.giveMilk();
    sheepFarm.reproduce();
    sheepFarm.giveMilk();
    goatFarm.reproduce();
    goatFarm.giveMilk();

    // Thống kê kết quả
    cout << "\nThống kê sau một lứa sinh sản và một lượt cho sữa:\n";
    cout << "Số lượng bò: " << cowFarm.getQuantity() << ", Tổng sữa: " << cowFarm.getMilkProduced() << " lít\n";
    cout << "Số lượng cừu: " << sheepFarm.getQuantity() << ", Tổng sữa: " << sheepFarm.getMilkProduced() << " lít\n";
    cout << "Số lượng dê: " << goatFarm.getQuantity() << ", Tổng sữa: " << goatFarm.getMilkProduced() << " lít\n";

    return 0;
}

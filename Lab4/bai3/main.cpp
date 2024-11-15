#include<bits/stdc++.h>
#include "bai3.cpp"
using namespace std;

int main() {
    int cow, sheep, goat;
    cout << "Nhap so con bo: ";
    cin >> cow;
    cout << "Nhap so con cuu: ";
    cin >> sheep;
    cout << "Nhap so con de: ";
    cin >> goat;

    Cow Cows(cow);
    Sheep Sheeps(sheep);
    Goat Goats(goat);

    Cows.keu();
    Sheeps.keu();
    Goats.keu();

    Cows.sinh();
    Cows.choSua();
    Sheeps.sinh();
    Sheeps.choSua();
    Goats.sinh();
    Goats.choSua();

    cout << "So con bo la: " << Cows.getNumberOfAnimal() << endl;
    cout << "So sua con bo cho la: " << Cows.getNumberOfMilk() << endl;
    cout << "So con cuu la: " << Sheeps.getNumberOfAnimal() << endl;
    cout << "So sua con cuu cho la: " << Sheeps.getNumberOfMilk() << endl;
    cout << "So con de la: " << Goats.getNumberOfAnimal() << endl;
    cout << "So sua con de cho la: " << Goats.getNumberOfMilk() << endl;
    return 0;
}

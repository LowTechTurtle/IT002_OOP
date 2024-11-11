#include <bits/stdc++.h>
#include "bai3.h"
using namespace std;

    void Animal::makeSound() {
    }
    void Animal::giveMilk() {
    }

    void Animal::reproduce() {
    }

    int Animal::getQuantity() {
        return quantity;
    }

    int Animal::getMilkProduced(){
        return milkProduced;
    }

    void Cow::makeSound() {
        cout << "Bò kêu: Moo!" << endl;
    }

    void Cow::giveMilk() {
        for (int i = 0; i < quantity; ++i) {
            milkProduced += rand() % 21; // Mỗi bò cho từ 0 đến 20 lít sữa
        }
    }

    void Cow::reproduce() {
        for (int i = 0; i < quantity; ++i) {
            quantity += rand() % 3; // Mỗi bò có thể sinh từ 0 đến 2 con
        }
    }

    void Sheep::makeSound() {
        cout << "Cừu kêu: Baa!" << endl;
    }

    void Sheep::giveMilk() {
        for (int i = 0; i < quantity; ++i) {
            milkProduced += rand() % 6; // Mỗi cừu cho từ 0 đến 5 lít sữa
        }
    }

    void Sheep::reproduce() {
        for (int i = 0; i < quantity; ++i) {
            quantity += rand() % 3; // Mỗi cừu có thể sinh từ 0 đến 2 con
        }
    }

    void Goat::makeSound() {
        cout << "Dê kêu: Bleat!" << endl;
    }

    void Goat::giveMilk() {
        for (int i = 0; i < quantity; ++i) {
            milkProduced += rand() % 11; // Mỗi dê cho từ 0 đến 10 lít sữa
        }
    }

    void Goat::reproduce() {
        for (int i = 0; i < quantity; ++i) {
            quantity += rand() % 3; // Mỗi dê có thể sinh từ 0 đến 2 con
        }
    }
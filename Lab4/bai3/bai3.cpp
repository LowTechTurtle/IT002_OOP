#include <bits/stdc++.h>
#include "bai3.h"
using namespace std;

    void Animal::keu() {
    }
    void Animal::choSua() {
    }

    void Animal::sinh() {
    }

    int Animal::getNumberOfAnimal() {
        return count;
    }

    int Animal::getNumberOfMilk(){
        return milk;
    }

    void Cow::keu() {
        for (int i = 0; i < count; i++)
            cout << "Bo doi" << endl;
    }

    void Cow::choSua() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            milk += rand() % 21;
        }
    }

    void Cow::sinh() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            count += rand() % 3;
        }
    }

    void Sheep::keu() {
        int temp = count;
        for (int i = 0; i < temp; i++)
            cout << "Cuu doi" << endl;
    }

    void Sheep::choSua() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            milk += rand() % 6;
        }
    }

    void Sheep::sinh() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            count += rand() % 3; //
        }
    }

    void Goat::keu() {
        for (int i = 0; i < count; i++)
            cout << "De doi" << endl;
    }

    void Goat::choSua() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            milk += rand() % 11;
        }
    }

    void Goat::sinh() {
        int temp = count;
        for (int i = 0; i < temp; i++) {
            count += rand() % 3;
        }
    }
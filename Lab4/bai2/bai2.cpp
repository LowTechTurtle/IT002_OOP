#include<bits/stdc++.h>
#include "bai2.h"
using namespace std;

    int Room::revenue() {
        return 0;
    }

    int Deluxe::revenue() {
        return nights * 750000 + service + serving;
    }

    int Premium::revenue() {
        return nights * 500000 + service;
    }

    int Business::revenue() {
        return nights * 300000;
    }
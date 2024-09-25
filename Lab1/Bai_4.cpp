#include<bits/stdc++.h>
using namespace std;

int main() {
    double x, sinx;
    cin >> x;
    double pi = 2 * acos(0.0); 
    x = x - floor(x/360)*360;
    x = x * pi / 180;
    sinx = x;
    int sign = 1;
    double powx = x;
    double sqrx = x * x;
    long long int facx = 1;
    for (int i = 1; i < 10; i++) {
        powx = powx * sqrx;
        sign = sign * -1;
        facx = facx * (2*i + 1) * (2*i);
        sinx += (sign * powx) / facx;
    }
    
    cout << "Gia tri sin can tim la: " << sinx << endl;

    return 0;
}
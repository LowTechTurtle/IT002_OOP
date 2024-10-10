#include<bits/stdc++.h>
#include "bai4.cpp"
using namespace std;

int main(){
    int n;
    cin >> n;
    matrix mat(n);
    mat.nhap();
    matrix matsave(mat);

    int count = 1;
    mat.cal();
    while (!mat.sosanh(matsave)) {
        mat.cal();
        count++;
    }
    cout << count << endl;
}
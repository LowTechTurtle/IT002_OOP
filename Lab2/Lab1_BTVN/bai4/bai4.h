#include<bits/stdc++.h>
using namespace std;

class matrix{
public:
    int n; //so hang, cot cua matran
    int mat[100][100] = {0};

    matrix(int n = 1) : n(n) {}

    matrix(matrix& othermat) {
        this -> n = othermat.n;
        for (int i = 0; i < othermat.n; i++) {
            for (int j = 0; j < othermat.n; j++) {
                this -> mat[i][j] = othermat.mat[i][j];
            }
        }
    }

    void nhap();

    void cal();

    bool sosanh(matrix othermat);

};
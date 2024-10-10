#include<bits/stdc++.h>
#include "bai4.h"
using namespace std;

    void matrix::nhap() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
             }
        }
    }

//phep bien doi
    void matrix::cal() {
        matrix temp(n);
        for (int i = 0; i < n; i++){
            for ( int j = 0; j < n; j++) {
                    temp.mat[i][j] = mat[(2*i+j)%n][(i+j)%n];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = temp.mat[i][j];
            }
        }
    }


    bool matrix::sosanh(matrix othermat) {
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < n; j++) {
                    if ( mat[i][j] != othermat.mat[i][j] ) {
                        return false;
                    }
            }
        }
        return true;
    }
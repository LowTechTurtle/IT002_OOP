#include<bits/stdc++.h>
using namespace std;

class MaTran {
public:
    int hang, cot;
    int matran[100][100];
    MaTran() {}
    MaTran(int hang, int cot) {
        this -> hang = hang;
        this -> cot = cot;
    }

    void Tong(MaTran mt) {
        if (hang != mt.hang || cot != mt.cot) {
            cout << "Ma tran khong tuong thich" << endl;
            return;
        }
        cout << "Tong 2 ma tran la: " << endl;
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < cot; j++) {
                cout << matran[i][j] + mt.matran[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Hieu(MaTran mt) {
        if (hang != mt.hang || cot != mt.cot) {
            cout << "Ma tran khong tuong thich" << endl;
            return;
        }

        cout << "Hieu 2 ma tran la: " << endl;
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < cot; j++) {
                cout << matran[i][j] - mt.matran[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Tich(MaTran mt) {
        if (cot != mt.hang) {
            cout << "Ma tran khong tuong thich" << endl;
            return;
        }
        cout << "tich 2 ma tran la: " << endl;
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < mt.cot; j++) {
                int sum = 0;
                for (int k = 0; k < cot; k++) {
                    sum += matran[i][k] * mt.matran[k][j] ;
                }    
                cout << sum << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int hang, cot, temp;
    cin >> hang >> cot;
    MaTran A(hang, cot); 
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cin >> A.matran[i][j];
        }
    }

    cin >> hang >> cot;
    MaTran B(hang, cot);
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cin >> B.matran[i][j];
        }
    }

    A.Tong(B);
    A.Hieu(B);
    A.Tich(B);
    cout << endl;
}
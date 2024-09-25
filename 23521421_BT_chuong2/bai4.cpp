#include<bits/stdc++.h>
using namespace std;


class info {
public:
    string id; 
    string ten;
    bool gioitinh; 
    float toan;
    float ly; 
    float hoa; 

    info() {
        cout<<"id: ";
        getline(cin, this->id);

        cout<<"ten: ";
        getline(cin, this->ten);

        cout << "gioi tinh: " << endl;
        cout << "0: nam" << endl;
        cout << "1: nu" << endl;
        cin >> this -> gioitinh;

        cout << "diem toan: ";
        cin >> this -> toan;

        cout << "diem ly: ";
        cin >> this -> ly;

        cout << "diem hoa: ";
        cin >> this -> hoa;
    }


    void xuat(){
        cout << "Diem trung binh: ";
        cout << fixed << setprecision(5) << (toan + ly + hoa)/3.0 << endl;
        cout << "id :" << id << endl;
        cout << "ten :" << ten << endl;

        if (gioitinh == 0) {
            cout << "gioi tinh: nam" << endl;
        } else {
            cout << "gioi tinh: nu" << endl;
        }

        cout << "diem toan :" << toan << endl;
        cout << "diem ly :" << ly << endl;
        cout << "diem hoa :" << hoa << endl;

    }
};

int main() {
    info hocsinh;
    hocsinh.xuat();
    return 0;
}

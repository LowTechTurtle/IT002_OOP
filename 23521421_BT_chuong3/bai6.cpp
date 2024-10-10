#include <iostream>
using namespace std;

class SoPhuc {
public:
    float phanThuc; 
    float phanAo;

    SoPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }

    SoPhuc(float thuc, float ao) {
        phanThuc = thuc;
        phanAo = ao;
    }

    void nhapSoPhuc() {
        cout << "Nhap phan thuc ";
        cin >> phanThuc;
        cout << "Nhap phan ao ";
        cin >> phanAo;
    }

    void xuatSoPhuc() const {
        if (phanAo >= 0) {
            cout << phanThuc << " + " << phanAo << "i" << endl;
        } else {
            cout << phanThuc << " - " << -phanAo << "i" << endl;
        }
    }

    SoPhuc cong(const SoPhuc& sp) const {
        SoPhuc ketQua;
        ketQua.phanThuc = phanThuc + sp.phanThuc;
        ketQua.phanAo = phanAo + sp.phanAo;
        return ketQua;
    }
};

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat" << endl;
    sp1.nhapSoPhuc();

    cout << "Nhap so phuc thu hai" << endl;
    sp2.nhapSoPhuc();

    cout << "So phuc thu nhat ";
    sp1.xuatSoPhuc();
    
    cout << "So phuc thu hai ";
    sp2.xuatSoPhuc();

    SoPhuc tong = sp1.cong(sp2);

    cout << "Tong cua 2 so phuc: ";
    tong.xuatSoPhuc();

    return 0;
}

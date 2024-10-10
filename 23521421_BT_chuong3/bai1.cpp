#include<bits/stdc++.h>
using namespace std;

class hocsinh {
public:
	string ten, loaihs;
	float toan, van, trungbinh;

bool CheckTen(string s) {
	bool OK = true;
	for(char v: s){
        if('a'<=v && v<='z') continue;
        if('A'<=v && v<='Z') continue;
        if(v==' ') continue;
        OK=false;
    }
	return OK;
}

// Check diem co hop le hay khong
bool CheckDiem(double diem) {
	if (0 * 1.0 <= diem && diem <= 10 * 1.0) {
		return true;
	} else {
		return false;
	}
}

// Nhap thong tin hoc sinh
void Nhap() {
	cout << "Nhap Ho va Ten hoc sinh: ";
	cin.ignore(); 

	getline(cin, this -> ten);

	while (!CheckTen(this -> ten)) {
		cout << "Nhap lai Ho va Ten hoc sinh: ";
//		cin.ignore(); 
		getline(cin, this -> ten);
	}
	cout << "Nhap diem mon Toan: ";
	cin >> this -> toan;

	while (!CheckDiem(this -> toan)) {
		cout << "Nhap lai diem mon Toan: ";
		cin >> this -> toan;
	}

	cout << "Nhap diem mon Van: ";
	cin >> this -> van;

	while (!CheckDiem(this -> van)) {
		cout << "Nhap lai diem mon Van: ";
		cin >> this -> van;
	}
}

// Tinh diem trung binh
double TinhGPA() {
	this -> trungbinh = 1.0 * (this -> toan + this -> van) / 2;
	return this -> trungbinh;
}

// Phan loai hoc sinh
void PhanLoai() {
	int trungbinh = this -> trungbinh;
	if (trungbinh >= 9) 
		this -> loaihs = "Xuat sac";
	else if (trungbinh >= 8)
		this -> loaihs = "Gioi";
	else if (trungbinh >= 6.5) 
		this -> loaihs = "Kha";
	else if (trungbinh >= 5) 
		this -> loaihs = "Trung binh";
	else 
		this -> loaihs = "Yeu";
}

// Xuat bang diem trung binh va phan loai
void Xuat() {
	cout << "Xuat diem trung binh va phan loai " << endl;
	cout << "Ten: " << this -> ten << endl;
	cout << "Diem TB: " << this -> trungbinh << endl;
	cout << "Danh Hieu: " << this -> loaihs << endl;
}
};

int main() {
	vector<hocsinh> vhs; // vector hoc sinh
	cout << "Nhap so sinh vien ban muon them vao" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		hocsinh hs;
		hs.Nhap();
		hs.TinhGPA();
		hs.PhanLoai();
		vhs.push_back(hs);
		hs.Xuat();
	}
    return 0;
}
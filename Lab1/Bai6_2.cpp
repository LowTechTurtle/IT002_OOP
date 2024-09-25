#include<bits/stdc++.h>
using namespace std;

struct hocsinh {
	string ten, loaihs;
	float toan, van, av, trungbinh;
};

// Check ten co hop le hay khong
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
void Nhap(hocsinh& hs) {
	cout << "Nhap Ho va Ten hoc sinh: ";
	cin.ignore(); 

	getline(cin, hs.ten);

	while (!CheckTen(hs.ten)) {
		cout << "Nhap lai Ho va Ten hoc sinh: ";
//		cin.ignore(); 
		getline(cin, hs.ten);
	}

	cout << "Nhap diem mon Toan: ";
	cin >> hs.toan;

	while (!CheckDiem(hs.toan)) {
		cout << "Nhap lai diem mon Toan: ";
		cin >> hs.toan;
	}

	cout << "Nhap diem mon Van: ";
	cin >> hs.van;

	while (!CheckDiem(hs.van)) {
		cout << "Nhap lai diem mon Van: ";
		cin >> hs.van;
	}

	cout << "Nhap diem mon Ngoai ngu: ";
	cin >> hs.av;

	while (!CheckDiem(hs.av)) {
		cout << "Nhap lai diem mon Ngoai ngu: ";
		cin >> hs.av;
	}

	cout << endl;

}

// Tinh diem trung binh
double TinhGPA(hocsinh& hs) {
	hs.trungbinh = 1.0 * (2 * hs.toan + hs.van + hs.av) / 4;
	return hs.trungbinh;
}

// Phan loai hoc sinh
void PhanLoai(hocsinh& hs) {
	if (hs.trungbinh >= 9) 
		hs.loaihs = "Xuat sac";
	else if (hs.trungbinh >= 8)
		hs.loaihs = "Gioi";
	else if (hs.trungbinh >= 6.5) 
		hs.loaihs = "Kha";
	else if (hs.trungbinh >= 5) 
		hs.loaihs = "Trung binh";
	else 
		hs.loaihs = "Yeu";
}

// Xuat bang diem trung binh va phan loai
void Xuat(hocsinh& hs) {
	cout << "Xuat diem trung binh va phan loai " << endl;
	cout << "Ten: " << hs.ten << endl;
	cout << "Diem TB: " << hs.trungbinh << endl;
	cout << "Danh Hieu: " << hs.loaihs << endl;
}

// Tim hoc sinh co diem trung binh cao nhat
void FindMax(vector<hocsinh> hs) {
	double MAX = 0;
	for (int i = 0; i < hs.size(); i++) {
		if (hs[i].trungbinh > MAX) {
			MAX = hs[i].trungbinh;
		}
	}

	vector<string> names;
	for (int i = 0; i < hs.size(); i++) {
		if (hs[i].trungbinh == MAX) {
			names.push_back(hs[i].ten);
		}
	}
	cout << "Danh Sach hoc sinh co diem trung binh cao nhat la: "<< endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}
}

//Tim hoc sinh co diem toan thap nhat
void FindMinMath(vector<hocsinh> hs) {
	int MIN = 11;
	for (int i = 0; i < hs.size(); i++) {
		if (hs[i].toan < MIN) {
			MIN = hs[i].toan;
		}
	}

	vector<string> names;
	for (int i = 0; i < hs.size(); i++) {
		if (hs[i].toan == MIN) {
			names.push_back(hs[i].ten);
		}
	}
	cout << "Danh Sach Hoc sinh co diem toan thap nhat la: "<< endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}
}
// Tim kiem theo ten
void FindName(vector<hocsinh> vhs, string name) {
	bool FOUND = false;
	for (hocsinh hs: vhs) {
		if (hs.ten == name) {
			FOUND = true;
			Xuat(hs);
		}
	}
	if (!FOUND) {
		cout << "khong tim thay hoc sinh nao voi ten " << name << endl;
	}
	return;
}

int main() {

	vector<hocsinh> vhs; // vector hoc sinh
	cout << "Nhap so sinh vien ban muon them vao" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		hocsinh hs;
		Nhap(hs);
		TinhGPA(hs);
		PhanLoai(hs);
		vhs.push_back(hs);
	}

	while (true) {
		cout << "1. Tinh diem trung binh" << endl;
		cout << "2. Phan loai HS" << endl;
		cout << "3. Tim hoc sinh co diem TB cao nhat" << endl;
		cout << "4. Tim hoc sinh theo ten" << endl;
		cout << "5. Tim hoc sinh co diem toan thap nhat" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			int j;
			cout << "Ban muon tinh diem TB cua hoc sinh thu may?" << endl;
			cin >> j;
			Xuat(vhs[j-1]);
		} else if (i == 2) {
			cout << "Ban muon xem loai hoc luc cua hoc sinh thu may?" << endl;
			int j;
			cin >> j;
			Xuat(vhs[j-1]);
		} else if (i == 3) {
			FindMax(vhs);
		} else if (i == 4) {
			cout << "Nhap ten: " << endl;
			string s;
			cin.ignore();
			getline(cin, s);
			FindName(vhs, s);
		} else if (i == 5) {
			FindMinMath(vhs);
		} else {
			cout << "Khong hop le" << endl;
		}
	}
	return 0;
}
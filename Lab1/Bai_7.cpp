#include<bits/stdc++.h>
using namespace std;

struct date {    
    int d; // day
    int m; // month
};


struct times {
    int h;
    int m;
};

struct flight {
    string fid; // flight id
    date day;
    times t;
    string depart;
    string arrive;
};

//ham dieu kien dung cho ham sort trong STL
bool sorty(flight a, flight b) {
    if (a.day.m < b.day.m) {
        return true;
    } else if (a.day.m == b.day.m) {
        if (a.day.d < b.day.d) {
            return true;
        } else if (a.day.d == b.day.d) {
            if (a.t.h < b.t.h) {
                return true;
            } else if (a.t.h == b.t.h) {
                if (a.t.m < b.t.h) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//check flight id co hop le hay khong
bool check_fid(string fid) {
    if (fid.size() > 5) {
        return false;
    }
    for (char x: fid) {
        if ('a' <= x && x <= 'z')
            continue;
        if ('A' <= x && x <= 'Z')
            continue;
        if ('0' <= x && x <= '9')
            continue;
        return false;
    }
    return true;
}

//kiem tra ngay da nhap co hop le hay khong
bool check_date(date d) {
    int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.m > 12 || d.m < 1) {
        return false;
    }
    if (d.d < 1 || d.d > days_of_month[d.m-1]) {
        return false;
    }
    return true;
}

// kiem tra ten cua diem di/diem den co hop le hay khong
bool check_location_name(string fid) {
    if (fid.size() > 20) {
        return false;
    }
    for (char x: fid) {
        if ('a' <= x && x <= 'z')
            continue;
        if ('A' <= x && x <= 'Z')
            continue;
        if (x == ' ') 
            continue;
        return false;
    }
    return true;
}

//ham nhap thong tin chuyen bay
void input(flight& f) {
    cout << "Nhap ma chuyen bay: ";
    cin >> f.fid;

    while (!(check_fid(f.fid))) {
        cout << "Nhap lai ma chuyen bay: ";
        cin >> f.fid;
    }

    cout << "Nhap ngay bay( nhap ngay, thang bang so): ";
    cin >> f.day.d >> f.day.m;
    
    while (!(check_date(f.day))) {
        cout << "Nhap lai ngay bay: ";
        cin >> f.day.d >> f.day.m;
    }

    cout << "Nhap gio bay( nhap gio, phut bang so): ";
    cin >> f.t.h >> f.t.m ;

    cout << "Nhap noi khoi hanh: ";
    cin.ignore();
    getline(cin, f.depart);

    while (!(check_location_name(f.depart))) {
        cout << "Nhap lai noi khoi hanh: ";
//        cin.ignore();
        getline(cin, f.depart);
    }

    cout << "Nhap noi ha canh: ";
//    cin.ignore();
    getline(cin, f.arrive);

    while (!(check_location_name(f.arrive))) {
        cout << "Nhap lai noi ha canh: ";
//        cin.ignore();
        getline(cin, f.arrive);
    }
}

//ham xuat thong tin chuyen bay
void Output(flight& f) {
    cout << "Ma chuyen bay: " << f.fid << endl;;
    cout << "Ngay bay: ";
    cout << f.day.d << "/" << f.day.m << endl;
    cout << "Gio bay: ";
    cout <<  f.t.h << ":" << f.t.m << endl;
    cout << "Noi khoi hanh: ";
    cout << f.depart << endl;
    cout << "Noi ha canh: ";
    cout << f.arrive << endl;
}

// tim thong tin chuyen bay bang ma chuyen bay
void find_flight_by_fid(vector<flight> lof, string fid) {
    bool found = false;
    for (flight f: lof) {
        if (f.fid == fid) {
            Output(f);
            found = true;
        }
    }
    if (!found) 
        cout << "Khong tim thay chuyen bay nao voi ma " << fid << endl;
}

// tim chuyen bay bang noi xuat phat
void find_flight_by_depart(vector<flight> lof, string depart) {
    bool found = false;
    for (flight f: lof) {
        if (f.depart == depart) {
            Output(f);
            found = true;
        }
    }
    if (!found) 
        cout << "Khong tim thay chuyen bay nao voi noi khoi hanh " << depart << endl;
}

// tim chuyen bay bang noi ha canh
void find_flight_by_arrival(vector<flight> lof, string arrive) {
    bool found = false;
    for (flight f: lof) {
        if (f.arrive == arrive) {
            Output(f);
            found = true;
        }
    }
    if (!found) 
        cout << "Khong tim thay chuyen bay nao voi diem den " << arrive << endl;
}


// tim chuyen bay bang noi ha canh va noi xuat phat
void find_flight_by_arrival_and_depart(vector<flight> lof, string arrive, string depart) {
    bool found = false;
    int count = 0;
    for (flight f: lof) {
        if (f.arrive == arrive && f.depart == depart) {
            count += 1;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay nao voi diem di va diem den ";
        cout << depart << ", " << arrive << endl;
    } else {
        cout << "Tim thay " << count << " chuyen bay" << endl;
    }
}

//tim chuyen bay bang noi khoi hanh, va ngay khoi hanh
void find_flight_by_depart_and_day(vector<flight> lof, string depart, date d) {
    bool found = false;
    for (flight f: lof) {
        if (f.depart == depart && f.day.d == d.d && f.day.m == d.m) {
            Output(f);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay nao voi diem di va ngay ";
        cout << depart << ", " << d.d << "/" << d.m << endl;
    }
}

int main() {
    int n;
    int temp;
    cout << "Nhap vao so chuyen bay: ";
    cin >> n;
    vector<flight> flights;

    for (int i = 0; i < n; i++) {
        flight f;
        input(f);
        flights.push_back(f);
    }

    while (true) {
        cout << "1. Tim chuyen bay bang ma chuyen bay" << endl;
        cout << "2. Tim chuyen bay bang noi di" << endl;
        cout << "3. Tim chuyen bay bang noi den" << endl;
        cout << "4. Tim chuyen bay tu mot noi cu the trong 1 ngay nhat dinh" << endl;
        cout << "5. Tim chuyen bay bang noi di va noi den nhat dinh" << endl;
        cout << "6. Sap xep chuyen bay theo ngay gio khoi hanh" << endl;

        cin >> temp;
        if (temp == 1) {
            string fid;
            cout << "Nhap ma chuyen bay: ";
            cin >> fid;

            while (!(check_fid(fid))) {
                cout << "Nhap lai ma chuyen bay: ";
                cin >> fid;
            }
            find_flight_by_fid(flights, fid);
        } else if (temp == 2) {
            string dep;
            cout << "Nhap noi khoi hanh: ";
            cin.ignore();
            getline(cin, dep);

            while (!(check_location_name(dep))) {
                cout << "Nhap lai noi khoi hanh: ";
//                cin.ignore();
                getline(cin, dep);
            }
            find_flight_by_depart(flights, dep);
        } else if (temp == 3) {
            string arr;
            cout << "Nhap noi ha canh: ";
            cin.ignore();
            getline(cin, arr);

            while (!(check_location_name(arr))) {
                cout << "Nhap lai noi ha canh: ";
//                cin.ignore();
                getline(cin, arr);
            }
            find_flight_by_arrival(flights, arr);
        } else if (temp == 4) {
            string dep;
            date d;
            cout << "Nhap noi khoi hanh: ";
            cin.ignore();
            getline(cin, dep);

            while (!(check_location_name(dep))) {
                cout << "Nhap lai noi khoi hanh: ";
//                cin.ignore();
                getline(cin, dep);
            }
            cout << "Nhap ngay va thang( nhap bang so): ";
            cin >> d.d >> d.m;
            while (!(check_date(d))) {
                cout << "Nhap lai ngay bay: ";
                cin >> d.d >> d.m;
            }
            find_flight_by_depart_and_day(flights, dep, d);
        } else if (temp == 5) {
            string dep;
            cout << "Nhap noi khoi hanh: ";
            cin.ignore();
            getline(cin, dep);

            while (!(check_location_name(dep))) {
                cout << "Nhap lai noi khoi hanh: ";
//                cin.ignore();
                getline(cin, dep);
            }

            string arr;
            cout << "Nhap noi ha canh: ";
 //           cin.ignore();
            getline(cin, arr);

            while (!(check_location_name(arr))) {
                cout << "Nhap lai noi ha canh: ";
//                cin.ignore();
                getline(cin, arr);
            }

            find_flight_by_arrival_and_depart(flights, arr, dep);
        } else if (temp == 6) {
            sort(flights.begin(), flights.end(), sorty);
            cout << "Cac chuyen bay da duoc sort theo ngay thang va gio bay" << endl;
        }
    }
    return 0;
}

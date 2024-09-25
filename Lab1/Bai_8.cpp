#include<bits/stdc++.h>
using namespace std;

struct day {
    int d;
    int m;
    int y;
};

struct info {
    string ma; 
    string cmnd;
    string name;
    string loaitk;
    day time; 
    double tien;
};

map<string, bool> quan_ly;
map<string, double> lai_suat;
day t;
vector<info> ds;
info a;
string s;

bool check_time(day a);
void get_time();

// kiem tra xem ma co hop le khong
bool check_ma(string ma){
    if (quan_ly[ma] == true) {
        cout << "Da ton tai tai khoan nay" << endl;; 
        return false;
    }

    if (ma.size() > 5) 
        return false;

    bool OK=true;
    
    for(char v: ma){
        if('0'<=v && v<='9') continue;
        if('a'<=v && v<='z') continue;
        if('A'<=v && v<='Z') continue;
        OK=false;
    }
    return OK;
}

//xem thu cmnd co hop le khong
bool check_cmnd(string a){
    if( a.size() != 9 && a.size() != 12) 
        return false;

    bool OK = true;

    for(char v: a){
        if ('0' <= v && v <= '9') 
            continue;
        OK=false;
    }
    return OK;
}

//kiem tra loai tk ( chi co 2 loai la ngan han va dai han)
bool check_loaitk(string loaitk){
    return ( loaitk == "ngan han" || loaitk == "dai han");
}

//kiem tra ten co hop le hay khong
bool check_name(string name){
    if (name.size() > 30) 
        return false;

    for(char v: name){
        if('a'<=v && v<='z') 
            continue;
        if('A'<=v && v<='Z') 
            continue;
        if (v == ' ') 
            continue;

        return false;
    }
    return true;
}

//nhap thong tin so tiet kiem
void input(){
    cout << "Nhap ma so :" << endl;
    getline(cin, a.ma);

    while (!check_ma(a.ma)) {
        cout << "Khong hop le, hay nhap lai" << endl;
        getline(cin, a.ma);
    }

    quan_ly[a.ma] = true;
    cout << "Chon loai tiet kiem (nhap ngan han hoac dai han)" << endl;
    cout << "Ngan han (6 thang) (3%/nam)" << endl;
    cout << "Dai han (12 thang) (5%/nam)" << endl;
    getline(cin, a.loaitk);

    while (!check_loaitk(a.loaitk)) {
        cout<<"Khong hop le" << endl;
        cout<<"Nhap lai: ";
        getline(cin,a.loaitk);
    }

    if (a.loaitk == "ngan han") 
        lai_suat[a.ma] = 0.03;
    else
        lai_suat[a.ma] = 0.05;

    cout << "Nhap Ten: ";
    getline(cin,a.name);

    while (!check_name(a.name)) {
        cout << "Khong hop le, nhap lai ten: ";
        getline(cin,a.name);
    }

    cout << "Nhap chung minh nhan dan: ";
    cin >> a.cmnd;

    while (!check_cmnd(a.cmnd)) {
        cout << "Khong hop le, hay nhap lai chung minh nhan dan" << endl;
        getline(cin,a.cmnd);
    }

    cout << "Ngay mo so, " ;
    get_time();

    while(!check_time(a.time)){
        cout<<"Khong hop le hay nhap lai" << endl;
        get_time();
    }

    cout<<"so tien gui: " << endl;
    cin>>a.tien;

    while (a.tien < 0){
        cout << "So tien khong the am, hay nhap lai" << endl;
        cin >> a.tien;
    }

    cin.ignore();
    ds.push_back(a);
}

//in ra ngay thang nam
void get_time(){
    cout<<"nhap ngay thang nam :";
    cin >> a.time.d >> a.time.m >> a.time.y;
}

//check xem ngay duoc nhap co hop le hay khong
bool check_time(day a){
    int days_of_month[12]={31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};

    if ( a.y < 1 || a.y > 2024) 
        return false;

    if (a.m < 1 || a.m > 12) 
        return false;

    if (a.d < 1 || a.d > days_of_month[a.m-1])
        return false;

    return true;
}

//ham dung de lam argument cho ham sort cua STL
//sort theo ngay thang nam
bool cmp_day(day a, day b){
    if (a.y != b.y) 
        return a.y < b.y;
    if (a.m != b.m) 
        return a.m < b.m;

    return a.d < b.d;
}

//ham dung cho 3rd argument cho sort cho STL
//sort theo chieu giam
bool cmp1(info a,info b){
    return a.tien>b.tien;
}

bool cmp2(info a,info b){
    return cmp_day(a.time,b.time) == true;
}

//vector chua cac info de xuat ra
vector<info> tap_xuat;

//cac ham helper cho ham xuat de xuat info
void search_1(){
    tap_xuat = ds;
}

void search_2(){
    string ma;
    cout << "Nhap ma so can tim" << endl;;
    cin >> ma;
    for(info a: ds){
        if(a.ma == ma){
            tap_xuat.push_back(a);
        }
    }
}

void search_3(){
    day a,b;
    cout << "Nhap ngay,thang,nam bat dau moi so cach 1 khoang trang: " << endl;
    cin >> a.d >> a.m >> a.y;
    while(!check_time(a)){
        cout << "Khong hop le, hay nhap lai" << endl;;
        cin >> a.d >> a.m >> a.y;
    }

    cout<<"Nhap ngay, thang, nam" << endl;
    cin >> b.d >> b.m >> b.y;
    while(!check_time(b)){
        cout << "Khong hop le, hay nhap lai" << endl;;
        cin >> b.d >> b.m >> b.y;
    }

    for(info v: ds){
        if(cmp_day(a,v.time) && cmp_day(v.time,b)){
            tap_xuat.push_back(v);
        }
    }
}

void xuat_tap_xuat(){
    cout << "\n";
    cout << "ma so, ho va ten, loai tiet kiem, cmnd, thoi gian mo so, so tien\n";
    for (info v: tap_xuat) {
        cout<<v.ma<<", "<<v.name<<", "<<v.loaitk<<", "<<
        v.cmnd<<", "<<v.time.d<<' '<<v.time.m<<' '<<
        v.time.y<<", "<<v.tien<<'\n';
    }
}

void search_info(){
    cout << "Go 1 chu so tuong ung voi cac lua chon sau day:" << endl;
    cout << "1: In ra tat ca" << endl;
    cout << "2: Tim kiem thong tin so" << endl;
    cout << "3: In ra cac thong tin so trong 1 khoang thoi gian nhat dinh" << endl;

    int x;
    cin >> x;
    tap_xuat.clear();
    if (x == 1){
        search_1();
        xuat_tap_xuat();
    }
    else if (x == 2){
        search_2();
        xuat_tap_xuat();
    }
    else if (x == 3){
        search_3();
        xuat_tap_xuat();
    }
    else{
        cout << "Khong hop le" << endl;;
    }
}

day now;
day han;
void get_now_time(){
    time_t old = time(0);
    tm *ltm = localtime(&old);
    now.y = 1900 + ltm -> tm_year;
    now.m = 1 + ltm -> tm_mon;
    now.d = ltm -> tm_mday;
}

void rut_tien(){
    string ma_so;
    cout<<"Nhap ma so can rut tien" << endl;
    cin >> ma_so;
    while(quan_ly[ma_so]==false){
        cout << "Khong ton tai: " << endl;
        cout << "Nhap lai hoac nhap out de thoat" << endl;
        cin >> ma_so;
        if(ma_so=="out") return;
    }

    double rut;
    for(info &a: ds){
        if (a.ma == ma_so) {
            cout<<"So tien can rut: \n";
            cin >> rut;
            while(rut < 0 || a.tien < rut){
                cout << "Tien rut phai > 0 vaf khong the > so tien dang co, nhap lai: " << endl;
                cin >> rut;
            }

            get_now_time();
            if( a.loaitk == "ngan han"){
                han=a.time;
                han.m+=6;
                if(han.m>12){
                    han.y++;
                    han.m-=12;
                }
            }
            else{
                han = a.time;
                han.y++;
            }
            if(cmp_day(now,han)){
                cout<<"Rut truoc han, tu dong tinh lai suat la 1%/nam \n";
                lai_suat[a.ma] = 1/100;
            }

            a.tien -= rut;
            break;
        }
    }
}

void cap_nhat_lai_suat(){
    string ma_so;
    cout <<"Nhap ma so" << endl;
    getline(cin,ma_so);
    while(quan_ly[ma_so] == false){
        cout << "Khong ton tai: " << endl;
        cout << "Nhap lai hoac nhap out de thoat" << endl;
        cin >> ma_so;
        if (ma_so == "out") return;
    }
    double lai;
    cout << "Nhap lai suat\n";
    cin >> lai;
    if (lai<0) {
        cout << "Khong the la so am, hay nhap lai" << endl;
        cin >> lai;
    }

    for(info &a: ds){
        if(a.ma == ma_so){
            cout << "Lai suat da duoc cap nhat" << endl;
            lai_suat[a.ma] = lai/100;
        }
    }
}
int diff(day borrow, day pay){
    int days_of_month[13] = {0,
                             31,28,31,30,31,30,
                             31,31,30,31,30,31};

    long total_borrow_day = borrow.y * 365 + borrow.d;
    for(int i = 1; i < borrow.m; i++){
        total_borrow_day += days_of_month[i];
    }

    long total_pay_day = pay.y * 365 + pay.d;
    for(int i = 1; i < pay.m; i++){
        total_pay_day += days_of_month[i];
    }
    return (total_pay_day - total_borrow_day);
}


void tinh_toan_tien_lai(){
    string ma_so;
    cout << "Nhap ma so" << endl;
    getline(cin,ma_so);
    while(1){
        if(quan_ly[ma_so]==true) break;
        cout<<"Khong ton tai:"<< endl;
        cout<<"Nhap lai hoac nhap out de thoat" << endl;
        getline(cin,ma_so);
        cin.ignore();
        if(ma_so=="out") return;
    }
    for(info a: ds){
        if(a.ma==ma_so){
            cout << "so tien lai: " << endl;
            get_now_time();
//            cout << "so ngay" << diff(a.time, now) << endl;;
//            cout << "tien " << a.tien << " " << lai_suat[a.ma] << endl;
            if (a.loaitk == "ngan han") {
                if (diff(a.time, now) > 180) 
                    cout << a.tien * (diff(a.time, now)/180) * lai_suat[a.ma]<<'\n';
                else
                    cout << a.tien * lai_suat[a.ma]<<'\n';
            } else if (a.loaitk == "dai han") {
                if (diff(a.time, now) > 365) 
                    cout << a.tien * (diff(a.time, now)/365) * lai_suat[a.ma]<<'\n';
                else
                    cout << (a.tien * lai_suat[a.ma]) <<'\n';
            }
        }
    }
}
int main() {
    while(1){
        cout << endl;
        cout << "1: Mo so tiet kiem" << endl;
        cout << "2: Tim kiem du lieu so tiet kiem" << endl;
        cout << "3: Cap nhat lai suat" << endl;
        cout << "4: Tinh tien lai" << endl;
        cout << "5: Rut tien" << endl;
        cout << "6.1: Sap xep danh sach giam dan theo tien gui" << endl;
        cout << "6.2: Sap xep theo ngay mo so tang dan" << endl;
        cout << "end: Thoat" << endl;

        cin>>s;
        cin.ignore();

        if ( s == "1") {
            input(); 
        } else if (s == "2") {
            search_info();
        } else if( s == "3") {
            cap_nhat_lai_suat();
        } else if(s == "4") {
            tinh_toan_tien_lai();
        } else if(s == "5") {
            rut_tien();
        } else if(s == "6.1") {
            sort(ds.begin(), ds.end(), cmp1);
            cout << "Cac so tiet kiem da duoc sort theo thu tu giam dan" << endl;
        } else if(s=="6.2") {
            sort(ds.begin(), ds.end(), cmp2);
            cout << "Cac so tiet kiem da duoc sort theo thu tu tang dan" << endl;
        } else if(s == "end") {
            break;
        } else {
            cout<<"khong hop le" << endl;
        }
    }
    return 0;
}

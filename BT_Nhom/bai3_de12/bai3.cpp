#include<bits/stdc++.h>
#include "bai3.h"
using namespace std;

int Trait::get_point() {
    return point;
}

void Trait::set_point(int p) {
    this -> point = p;
}

void Trait::output() {
        cout << "Some trait";
}

void Openness::output() {
    if (point <= 30) {
        cout << "San sang trai nghiem: Nguoi nay thuong kha bao thu, kho tiep nhan nhung \
y tuong moi, la. Ho thich su on dinh, quen thuoc va thuc te" << endl;
    } else if (point >= 70) {
        cout << "San sang trai nghiem: Nguoi nay thich nhung y tuong moi thich hieu biet \
linh vuc nhung dong thoi cung thich tu do, khong bi rang buoc" << endl;
    } else {
        cout << "San sang trai nghiem: Khong the ket luan ve nguoi nay" << endl;
    }
}

void Conscientiousness::output() {
    if (point <= 30) {
        cout << "Tu chu tan tam: Nguoi nay thuong de bo cuoc, kha nang chiu ap luc thap" << endl;
    } else if (point >= 70) {
        cout << "Tu chu tan tam: Nguoi nay thuong la nguoi cham chi co kha nang chiu ap luc tot, \
la nguoi gan bo, trung thanh voi to chuc" << endl;
    } else {
        cout << "Tu chu tan tam: Khong the ket luan ve nguoi nay" << endl;
    }
}

void Extraversion::output() {
    if (point <= 30) {
        cout << "Huong ngoai: Nguoi nay thuong ngai giao tiep, khong thich su noi bat" << endl;
    } else if (point >= 70) {
        cout << "Huong ngoai: Nguoi nay nhiet tinh, nang dong, giao tiep tot" << endl;
    } else {
        cout << "Huong ngoai: Khong the ket luan ve nguoi nay" << endl;
    }
}

void Agreeableness::output() {
    if (point <= 30) {
        cout << "Hoa dong de chiu: Nguoi nay thuong dat loi ich cua ban than len tren, \
it dong cam, chia se voi dong nghiep" << endl;
    } else if (point >= 70) {
        cout << "Hoa dong de chiu: Nguoi nay than thien coi mo, dong cam voi moi nguoi" << endl;
    } else {
        cout << "Hoa dong de chiu: Khong the ket luan ve nguoi nay" << endl;
    }
}

void Neuroticism::output() {
    if (point <= 30) {
        cout << "Bat on cam xuc: Nguoi nay thuong kiem soat duoc cam xuc,\
ung pho voi cang thang tot" << endl;
    } else if (point >= 70) {
        cout << "Bat on cam xuc: Nguoi nay thuong co cam xuc tieu cuc nhu \
lo lang, buc boi, tu ti, chiu ap luc kem" << endl;
    } else {
        cout << "Bat on cam xuc: Khong the ket luan ve nguoi nay" << endl;
    }
}

void Person::describe_person() {
    O.output();
    C.output();
    E.output();
    A.output();
    N.output();
}

int Person::get_id() {
    return person_id;
}

void Person::is_noticeable() {
    if (C.get_point() <= 30) {
        cout << "Nguoi nay co nguy co bi nha tuyen dung luu y" << endl;
    } else if (E.get_point() <= 30 && N.get_point() >= 70) {
        cout << "Nguoi nay co nguy co cao bi nha tuyen dung luu y dac biet" << endl;
    } else if (N.get_point() >= 70) {
        cout << "Nguoi nay co nguy co bi nha tuyen dung luu y" << endl;
    } else {
        cout << "Nguoi nay khong co nguy co cao bi nha tuyen dung luu y" << endl;
    }
}


void List_of_Person::push(Person p) {
    LoP.push_back(p);
}

Person List_of_Person::get_person_by_index(int i) {
    return LoP[i];
}

Person List_of_Person::get_person_by_pid(int pid) {
    for (Person p: LoP) {
        if (p.get_id() == pid) {
            return p;
        }
    }
    return Person("O00-C00-E00-A00-N00", 0);
}
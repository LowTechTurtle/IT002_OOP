#include<bits/stdc++.h>
#include "friends.h"
using namespace std;

    int Friend::getage() {
        return age;
    }

    string Friend::getname() {
        return name;
    }

    string BestFriend::getphone() {
        return phone;
    }

    double BoyFriend::getincome() {
        return income;
    }

    double OtherFriend::getattr() {
        return attr;
    }

    double BestFriend::calTimeSpent() {
        return 5;
    }

    double BoyFriend::calTimeSpent() {
        return 5 * income / 10000000.0;
    }

    double OtherFriend::calTimeSpent(int num_of_friends) {
        return attr * 20 / num_of_friends;
    }

    void FriendManager::Input() {
        int n, age, type;
        double income, attr;
        string name, phone;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> type;
            cin >> name;
            cin >> age;
            if (type == 1) {
                cin >> phone;
                bestfriends.push_back(BestFriend(name, age, phone));
            } else if (type == 2) {
                cin >> income;
                boyfriends.push_back(BoyFriend(name, age, income));
            } else if (type == 3) {
                cin >> attr;
                otherfriends.push_back(OtherFriend(name, age, attr));
            }
        }
    }
    
    void FriendManager::calTimeSpent() {
        double sumbestfriends = 0, sumboyfriends = 0, sumotherfriends = 0;
        for (BoyFriend bf: boyfriends) {
            sumboyfriends += bf.calTimeSpent();
        }

        for (BestFriend bf: bestfriends) {
            sumbestfriends += bf.calTimeSpent();
        }

        for (OtherFriend of: otherfriends) {
            sumotherfriends += of.calTimeSpent(otherfriends.size() + bestfriends.size() + boyfriends.size());
        }

        cout << "Thong ke:" << endl;
        cout << "\t - Thoi gian cho ban than: " << sumbestfriends << " h" << endl;
        cout << "\t - Thoi gian cho ban trai: " << sumboyfriends << " h" << endl;
        cout << "\t - Thoi gian cho ban trai khac: " << sumotherfriends << " h" << endl;
    }

    void FriendManager::mostImportantFriend() {
        int max = -1, type, temp;
        BoyFriend boyf;
        BestFriend bestf;
        OtherFriend otherf;

        for (BoyFriend bf: boyfriends) {
            temp =  bf.calTimeSpent();
            if (temp > max) {
                max = temp;
                type = 2;
                boyf = bf;
            }
        }

        for (BestFriend bf: bestfriends) {
            temp =  bf.calTimeSpent();
            if (temp > max) {
                max = temp;
                type = 1;
                bestf = bf;
            }
        }

        for (OtherFriend of: otherfriends) {
            temp =  of.calTimeSpent(otherfriends.size());
            if (temp > max) {
                max = temp;
                type = 3;
                otherf = of;
            }
        }

        if (type == 1) {
            string name = bestf.getname();
            string phone = bestf.getphone();
            int age = bestf.getage();

            cout << "Nguoi quan trong nhat:" << endl;
            cout << "Ten: " << name << ", tuoi: " << age << ", so dien thoai: " << phone << endl;
        }

        if (type == 2) {
            string name = boyf.getname();
            int age = boyf.getage();
            double income = boyf.getincome();

            cout << "Nguoi quan trong nhat:" << endl;
            cout << fixed << setprecision(2) << setprecision(2) << "Ten: " << name << ", tuoi: " << age << ", thu nhap: " << income << endl;
        }

        if (type == 3) {
            string name = otherf.getname();
            double attr = otherf.getattr();
            int age = otherf.getage();

            cout << "Nguoi quan trong nhat:" << endl;
            cout << "Ten: " << name << ", tuoi: " << age << ", do dep trai: " << attr << endl;
        }
    }
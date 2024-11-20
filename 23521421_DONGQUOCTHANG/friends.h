#include<bits/stdc++.h>
using namespace std;

class Friend {
protected:
    string name;
    int age;
public:
    Friend() {};
    Friend(string name, int age) : name(name), age(age) {}

    virtual double calTimeSpent() {return 0;};

    string getname();
    int getage();
};

class BestFriend : public Friend {
private:
    string phone;
public:
    BestFriend() {};
    BestFriend(string name, int age, string phone) : Friend(name, age), phone(phone) {}

    double calTimeSpent() override;
    string getphone();
};


class BoyFriend : public Friend {
private:
    double income;
public:
    BoyFriend() {};
    BoyFriend(string name, int age, double income) : Friend(name, age), income(income) {}

    double getincome();
    double calTimeSpent() override;
};

class OtherFriend : public Friend {
private:
    double attr;
public:
    OtherFriend() {};
    OtherFriend(string name, int age, double attr) : Friend(name, age), attr(attr) {}

    double calTimeSpent(int num_of_friends);
    double getattr();
};

class FriendManager {
public:
    vector<BestFriend> bestfriends;
    vector<BoyFriend> boyfriends;
    vector<OtherFriend> otherfriends;

    FriendManager() {};

    void Input();
    
    void calTimeSpent();

    void mostImportantFriend();
};
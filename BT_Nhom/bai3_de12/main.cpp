#include<bits/stdc++.h>
#include "bai3.cpp"

using namespace std;

int main() 
{
    List_of_Person A;
    string s; // OCEAN personality string
    int pid;
    int n;
    cout << "Nhap so nguoi: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap ket danh gia tam ly cua nguoi thu " << i+1 <<" : ";
        cin >> s;
        cout << "Nhap id cua nguoi do ";
        cin >> pid;
        Person p(s, pid);
        A.push(p);
    }

    cout << "Hay chon mot nguoi de in ra tinh cach cua nguoi do" << endl;
    cout << "Nhap pid cua nguoi do: ";
    cin >> pid;

    Person p = A.get_person_by_pid(pid);
    p.describe_person();
    p.is_noticeable();
    return 0;
}
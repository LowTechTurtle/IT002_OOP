#include<bits/stdc++.h>
using namespace std;

class Room {
protected:
    int nights;

public:
    Room(int n) : nights(n) {}

    virtual int revenue();
};

class Deluxe : public Room {
private:
    int service, serving;
public:
    Deluxe(int n, int service, int serving) : Room(n), service(service), serving(serving) {}

    int revenue() override;
};

class Premium : public Room {
private:
    int service;
public:
    Premium(int n, int service) : Room(n), service(service) {}

    int revenue() override;
};

class Business : public Room {
public:
    Business(int n) : Room(n) {}

    int revenue() override;
};


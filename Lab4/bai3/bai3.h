#include <bits/stdc++.h>
using namespace std;

class Animal {
protected:
    int count;  
    int milk; 

public:
    Animal(int count) : count(count), milk(0) {}

    virtual void keu();
    virtual void choSua();
    virtual void sinh();

    int getNumberOfAnimal();

    int getNumberOfMilk();
};

class Cow : public Animal {
public:
    Cow(int count) : Animal(count) {}

    void keu() override;

    void choSua() override;

    void sinh() override;
};

class Sheep : public Animal {
public:
    Sheep(int count) : Animal(count) {}

    void keu() override;

    void choSua() override;

    void sinh() override;
};

class Goat : public Animal {
public:
    Goat(int count) : Animal(count) {}

    void keu() override;

    void choSua() override;

    void sinh() override;
};
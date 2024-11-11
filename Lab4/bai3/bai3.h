#include <bits/stdc++.h>
using namespace std;

class Animal {
protected:
    int quantity;  
    int milkProduced; 

public:
    Animal(int qty) : quantity(qty), milkProduced(0) {}

    virtual void makeSound();
    virtual void giveMilk();
    virtual void reproduce();

    int getQuantity();

    int getMilkProduced();
};

class Cow : public Animal {
public:
    Cow(int qty) : Animal(qty) {}

    void makeSound() override;

    void giveMilk() override;

    void reproduce() override;
};

class Sheep : public Animal {
public:
    Sheep(int qty) : Animal(qty) {}

    void makeSound() override;

    void giveMilk() override;

    void reproduce() override;
};

class Goat : public Animal {
public:
    Goat(int qty) : Animal(qty) {}

    void makeSound() override;

    void giveMilk() override;

    void reproduce() override;
};
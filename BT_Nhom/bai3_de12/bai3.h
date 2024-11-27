#include<bits/stdc++.h>
using namespace std;

class Trait {
protected:
    int point;
public:
    Trait(int point) : point(point) {}

    int get_point();
    
    void set_point(int p);

    virtual void output();
};

class Openness : public Trait{
public:
    Openness(int point) : Trait(point) {}
    void output() override;
}; 

class Conscientiousness : public Trait {
public:
    Conscientiousness(int point) : Trait(point) {}
    void output() override;
};

class Extraversion : public Trait{
public:
    Extraversion(int point) : Trait(point) {}
    void output() override;
}; 

class Agreeableness : public Trait{
public:
    Agreeableness(int point) : Trait(point) {}
    void output() override;
}; 

class Neuroticism : public Trait{
public:
    Neuroticism(int point) : Trait(point) {}
    void output() override;
}; 

class Person {
private:
    int person_id;
    Openness O;
    Conscientiousness C;
    Extraversion E;
    Agreeableness A;
    Neuroticism N;
public:
    Person(string res, int person_id) : person_id(person_id), O(0),
    C(0), E(0), A(0), N(0) {
        regex ro("O([0-9]+)-");
        smatch m;
        regex_search(res, m, ro);
        O.set_point(stoi(m.str(1)));

        regex rc("C([0-9]+)-");
        regex_search(res, m, rc);
        C.set_point(stoi(m.str(1)));

        regex re("E([0-9]+)-");
        regex_search(res, m, re);
        E.set_point(stoi(m.str(1)));

        regex ra("A([0-9]+)-");
        regex_search(res, m, ra);
        A.set_point(stoi(m.str(1)));

        regex rn("N([0-9]+)$");
        regex_search(res, m, rn);
        N.set_point(stoi(m.str(1)));
    }

    int get_id();

    void describe_person();

    void is_noticeable();
};

class List_of_Person {
private:
    vector<Person> LoP;
public:
    void push(Person p);

    Person get_person_by_index(int i);

    Person get_person_by_pid(int pid);
};
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Hero {
public:
    string name;
    int age;
    int health;

    virtual void attack() {
        cout << name << ": " << "boo ! " << endl;
    }

    virtual void attackTo(Hero * hero) {
        if (hero != this) {
            cout << name << ": attacks to " << hero->name << endl;
            hero->health -= 1;
        }
    }

    Hero(string name, int age) : name(name), age(age), health(100) {
        cout << "Hero " << name << " has been created ! " << endl;
    }

    ~Hero() {
        cout << "Hero  " << name << " has been destroyed !! " << endl;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }
};

class Wizard : public Hero {
public:
    int mana;

    Wizard(string wizardname) : Hero(wizardname, 100), mana(100) {
        cout << "Wizard " << wizardname << " has been created with age " << age << " ! " << endl;
    }

    Wizard(string wizardname, int wizardage) : Hero(wizardname, wizardage), mana(100) {
        cout << "Wizard " << wizardname << " has been created with age " << age << " ! " << endl;
    }

    ~Wizard() {
        cout << "Wizard  " << name << " has been destroyed !! " << endl;
    }

    virtual void attack() {
        cout << name << ": " << "abra catabra !!! " << endl;
    }

    int getMana() const {
        return mana;
    }

    void setMana(int mana) {
        this->mana = mana;
    }
};

class Warrior : public Hero {
public:

    Warrior(string warriorname, int warriorage) : Hero(warriorname, warriorage) {
        cout << "Warrior " << warriorname << " has been created with age " << age << " ! " << endl;
    }

    ~Warrior() {
        cout << "Warrior  " << name << " has been destroyed !! " << endl;
    }

    virtual void attack() {
        cout << name << ": " << "charge !!! " << endl;
    }
};

class Paladin : public Warrior {
public:

    Paladin(string n, int a) : Warrior(n, a) {
        cout << "Paladin " << n << " has been created with age " << age << " ! " << endl;
    }

    ~Paladin() {
        cout << "Paladin  " << name << " has been destroyed !! " << endl;
    }

    virtual void attack() {
        Warrior::attack(); // java's super.attack();
        cout << name << ": " << "for justice !!! " << endl;
        Warrior::attack(); // java's super.attack();
    }
};

class Barbarian : public Warrior {
public:

    Barbarian(string n, int a) : Warrior(n, a) {
        cout << "Barbarian " << n << " has been created with age " << age << " ! " << endl;
    }

    ~Barbarian() {
        cout << "Barbarian  " << name << " has been destroyed !! " << endl;
    }

    virtual void attack() {
        cout << name << ": " << "for krom !!! " << endl;
    }
};

int main(int argc, char** argv) {
    Hero h("Bob", 100);
    h.attack();

    Wizard w1("Gandalf", 200);
    w1.attack();

    Wizard w2("Sarouman");
    w2.attack();

    Hero * ph = new Wizard("Bla"); // wizard -> hero   SOS => up casting:  X x = new Y() => valid iff y inherits X            
    Wizard * p1 = (Wizard*) ph; // down casting, valid since this hero is a wizard
    //    Warrior* p2 = (Warrior*) ph;            // down casting, invalid since this hero is a wizard

    ph->attack();



    delete ph;
    delete p1;

    return 0;
}


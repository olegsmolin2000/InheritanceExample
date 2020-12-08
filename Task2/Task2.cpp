#include <iostream>
using namespace std;

class ComputerGameObject {
protected:
    string title;
public:
    virtual void draw() = 0;
};

class Creature :public ComputerGameObject {
protected:
    int x, y;
public:
    virtual void move(int newX,int newY) = 0;
};

class MagicItem :public ComputerGameObject {
protected:
    int x, y;
    int damage;
public:
    MagicItem() {
        this->title = "Magic item";
        this->x = 0;
        this->y = 0;
        this->damage = 0;
    }
    MagicItem(const MagicItem& otherItem) {
        this->title = otherItem.title;
        this->x = otherItem.x;
        this->y = otherItem.y;
        this->damage = otherItem.damage;
    }
    MagicItem(string name, int damage):MagicItem() {
        this->title = name;
        this->damage = damage;
    }
    MagicItem(string name,int x,int y, int damage) {
        this->title = name;
        this->damage = damage;
        this->x = x;
        this->y = y;
    }
    ~MagicItem(){}
    void draw() {
        cout << "Position of "<<this->title<<" is X = " << this->x << " Y = " << this->y << endl;
        cout << "Damage is " << this->damage << endl<<endl;
    }
};

class MythAnimal :public Creature {
protected:
    int speed;
public:
    MythAnimal() {
        this->title = "Mythical animal";
        this->x = 0;
        this->y = 0;
        this->speed = 0;
    }
    MythAnimal(const MythAnimal& otherAnimal) {
        this->title = otherAnimal.title;
        this->x = otherAnimal.x;
        this->y = otherAnimal.y;
        this->speed = otherAnimal.speed;
    }
    MythAnimal(string _title,int speed):MythAnimal(){
        this->title = _title;
        this->speed = speed;
    }
    MythAnimal(string title, int x, int y,int speed) {
        this->title = title;
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
    void move(int newX, int newY) override {
        cout << title << " went to X = " << newX << " Y = " << newY << endl << endl;
        this->x = newX;
        this->y = newY;
    }
    void draw() override {
        cout << "Position of "<< this->title << " is X = " << this->x << " Y = " << y << endl;
        cout << "Speed of " << this->title << " is " << this->speed << endl << endl;
    }
};

class Human : public virtual Creature {
protected:
    int intellect;
public:
    Human() {
        this->title = "Human";
        this->x = 0;
        this->y = 0;
        this->intellect = 0;
    }
    Human(const Human& otherHuman) {
        this->title = otherHuman.title;
        this->x = otherHuman.x;
        this->y = otherHuman.y;
        this->intellect = otherHuman.intellect;
    }
    Human(string _title, int intellect) :Human() {
        this->title = _title;
        this->intellect = intellect;
    }
    Human(string title, int x, int y, int intellect) {
        this->title = title;
        this->x = x;
        this->y = y;
        this->intellect = intellect;
    }
    virtual void move(int newX, int newY) override {
        cout << title << " went to X = " << newX << " Y = " << newY << endl << endl;
        this->x = newX;
        this->y = newY;
    }
    virtual void draw() override {
        cout << "Position of " << this->title << " is X = " << this->x << " Y = " << y << endl;
        cout << "intellect of " << this->title << " is " << this->intellect << endl << endl;
    }
};

class MagicPerson : public virtual Creature {
protected:
    int magicPoint;
public:
    MagicPerson() {
        this->title = "Magic Person";
        this->x = 0;
        this->y = 0;
        this->magicPoint = 0;
    }
    MagicPerson(const MagicPerson& otherMagic) {
        this->title = otherMagic.title;
        this->x = otherMagic.x;
        this->y = otherMagic.y;
        this->magicPoint = otherMagic.magicPoint;
    }
    MagicPerson(string _title, int magicPoint) :MagicPerson() {
        this->title = _title;
        this->magicPoint = magicPoint;
    }
    MagicPerson(string title, int x, int y, int magicPoint) {
        this->title = title;
        this->x = x;
        this->y = y;
        this->magicPoint = magicPoint;
    }
    virtual void move(int newX, int newY) override {
        cout << title << " went to X = " << newX << " Y = " << newY << endl << endl;
        this->x = newX;
        this->y = newY;
    }
    virtual void draw() override {
        cout << "Position of " << this->title << " is X = " << this->x << " Y = " << y << endl;
        cout << "Magic Point of " << this->title << " is " << this->magicPoint << endl << endl;
    }
};

class MagicHuman : public Human, public MagicPerson {
public:
    MagicHuman() {
        this->title = "Magic Person";
        this->x = 0;
        this->y = 0;
        this->intellect = 0;
        this->magicPoint = 0;
    }
    MagicHuman(string _title,int _intelect,int _MP):MagicHuman() {
        this->title = _title;
        this->intellect = _intelect;
        this->magicPoint = _MP;
    }
    MagicHuman(const MagicHuman& other) {
        this->title = other.title;
        this->x = other.x;
        this->y = other.y;
        this->intellect = other.intellect;
        this->magicPoint = other.magicPoint;
    }
    MagicHuman(string _title,int x,int y, int _intelect, int _MP) {
        this->title = _title;
        this->x = x;
        this->y = y;
        this->intellect = _intelect;
        this->magicPoint = _MP;
    }
    void draw() {
        cout << "Position of " << this->title << " is X = " << this->x << " Y = " << y << endl;
        cout << "intellect of " << this->title << " is " << this->intellect << endl;
        cout << "Magic Point of " << this->title << " is " << this->magicPoint << endl << endl;
    }
    void move(int newX, int newY) {
        cout << title << " went to X = " << newX << " Y = " << newY << endl << endl;
        this->x = newX;
        this->y = newY;
    }
};

int main()
{
    MagicItem item = MagicItem("Magic beer", 14, 88, 228);
    item.draw();

    MythAnimal animal = MythAnimal("Myth pig", 1, 2, 3);
    animal.draw();
    animal.move(5, 5);

    Human hhuman = Human("putin", 10, 20, 30);
    hhuman.draw();
    hhuman.move(50, 50);

    MagicPerson person = MagicPerson("komar", 40, 40, 10);
    person.draw();
    person.move(0, 0);

    MagicHuman oleg = MagicHuman("oleg", 1, 1, 100, 100);
    oleg.draw();
    oleg.move(14, 88);
    return 0;
}

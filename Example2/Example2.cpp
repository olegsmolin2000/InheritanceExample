#include <iostream>
using namespace std;

class creature {
private:
    string title;
    double mass;
protected:
    creature():mass(0.0){}
    creature(const creature& obj):title(obj.title),mass(obj.mass){}
    creature(const string& _title,double _mass):title(_title),mass(_mass){}
    virtual ~creature() {
        cout << "creature deleted\n\n";
    }
    virtual void _print() const {
        cout << "title:" << title << ", mass:" << mass;
    }
public:
    void print() const {
        cout << typeid(*this).name() << ":(";
        _print();
        cout << ")\n";
    }
    double get_Mass()const {
        return mass;
    }
};

class animal :public creature {
private:
    double speed;
public:
    animal():creature(){}
    animal(const animal& obj):creature(obj),speed(obj.speed){}
    animal(const string& _title, double _mass,double _speed):creature(_title,_mass),speed(_speed){}
    ~animal() {
        cout << "animal deleted\n";
    }
    double get_speed()const {
        return speed;
    }
protected:
    void _print() const {
        creature::_print();
        cout << ", speed:" << speed;
    }
};

class bird :public virtual animal {
private:
    double topFly;
public:
    bird():animal(){}
    bird(const bird& obj):animal(obj),topFly(obj.topFly){}
    bird(const string& _title,double _mass,double _speed,double _topFly):animal(_title,_mass,_speed),topFly(_topFly){}
    ~bird() {
        cout << "bird deleted\n";
    }
protected:
    void _print() const
    {
        animal::_print();
        cout << ", topFly:" << topFly;
    }
};

class fish:public animal {
private:
    double maxdeep;
public:
    fish():animal(){}
    fish(const fish& obj):animal(obj),maxdeep(obj.maxdeep){}
    fish(const string& _title,double _mass,double _speed,double _maxdeep):animal(_title,_mass,_speed),maxdeep(_maxdeep){}
    ~fish() {
        cout << "fish deleted\n";
    }
protected:
    void _print() const {
        animal::_print();
        cout << ", maxDeep:" << maxdeep;
    }
};

class predator:public virtual animal {
protected:
    predator(){}
public:
    ~predator(){}
    virtual bool hunt(const animal& obj) = 0;
};

class eagle :public bird, public predator {
public:
    eagle():bird(){}
    eagle(const eagle& obj):bird(obj),animal(obj){}
    eagle(double _mass,double _speed,double _topFly):bird("",0,0,_topFly),animal("Орел",_mass,_speed){}
    bool hunt(const animal &obj) {
        return obj.get_Mass() < get_Mass() && obj.get_speed() < get_speed();
    }
};

int main(){
    setlocale(0, "Rus");
    bird raven("Ворона", 0.3, 10, 0.1);
    fish hammerHead("Рыба-молот", 150, 5, 0.5);
    raven.print();
    hammerHead.print();
    predator &eagle1 = *new eagle(1, 100, 1);
    cout << "eagle vs raven: " << eagle1.hunt(raven) << endl;
    cout << "eagle vs hammerhead: " << eagle1.hunt(hammerHead) << endl<<endl;
    delete &eagle1;
    return 0;
}
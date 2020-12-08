#include <iostream>
using namespace std;



class B1 {
    int b1;
public:
    B1() {
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    B1(int _b1) :B1() {
        b1 = _b1;
    }
    ~B1() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};



class B2 {
    int b2;
public:
    B2() {
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    B2(int _b2) :B2() {
        b2 = _b2;
    }
    ~B2() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};



class D1:public B1,protected B2 {
    int d1;
public:
    D1(int _d1,int _b2,int _b1) :B2(_b2),B1(_b1) {
        d1 = _d1;
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    ~D1() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};



class D2 :protected D1 {
    int d2;
public:
    D2(int _d2, int _d1, int _b2, int _b1) :D1(_d1, _b2, _b1) {
        d2 = _d2;
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    ~D2() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};



class D3 :private D2 {
    int d3;
public:
    D3(int _d3, int _d2, int _d1, int _b2, int _b1) :D2(_d2, _d1, _b2, _b1) {
        d3 = _d3;
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    ~D3() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};



class D4 :public D2 {
    int d3;
public:
    D4(int _d4, int _d2, int _d1, int _b2, int _b1) :D2(_d2, _d1, _b2, _b1) {
        d3 = _d4;
        cout << "Object of " << typeid(*this).name() << " was created\n";
    }
    ~D4() {
        cout << "Object of " << typeid(*this).name() << " was destroyed\n";
    }
};


int main()
{
    D3(1,2,3,4,5);
    D4(0, 1, 2, 3, 4);
    return 0;
}
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Figura{
protected:
    string nazwa, kolor;
public:
    void dodajnazwe(string cos){
        nazwa=cos;
    }
    string wypisznazwe(){
        return nazwa;
    }
};

class Kwadrat: public Figura {
protected:
    double a;
public:
    double obwod(double a){
        this->a;
        return 4*a;
    }
    double pole(double a){
        this->a;
        return a*a;
    }
};

class Prostokat: public Figura {
protected:
    double a,b;
public:
    double obwod(double a, double b){
        this->a;
        this->b;
        return 2*a+2*b;
    }
    double pole(double a, double b){
        this->a;
        this->b;
        return a*b;
    }
};

class Kolo: public Figura {
protected:
    double r;
public:
    double obwod(double r){
        this->r;
        return 2*M_PI*r;
    }
    double pole(double r){
        this->r;
        return M_PI*r*r;
    }

};

int main() {
    Kolo test;
    test.dodajnazwe("nazwa");
    cout<<test.obwod(3)<<" "<<test.wypisznazwe();
    return 0;
}

#define _USE_MATH_DEFINES
#include<iostream>
#include <cmath>

using namespace std;

class Prostopadloscian{
public:
    double a, b, h;
    double oblicz(double a, double b, double h){
        pp=2*a*b;
        pb=2*(b*h)+2*(a*h);
        return pp+pb;
    }
private:
    double pp, pb;
};

class Kula{
public:
    double r;
    double oblicz(double rr){
        ctpi=4/3.*M_PI;
        return ctpi* pow(rr,3);
    }
private:
    double ctpi;
};

class FunckjaKwadratowa{
public:
    int a, b, c;
    void wyswietl(int aa, int bb, int cc){
        std::cout<<"f(x)="<<aa<<"x^2 + "<<bb<<"x + "<<cc<<endl;
    }
};

class Student{
public:
    string imie, nazwisko;
    int nr_albumu, l_pytan, popr_odp;
    double procent(int liczba_pytan, int pop_odp){
        double temp;
        temp = (double)pop_odp/(double)liczba_pytan;
        temp*=100;
        return floor(temp);
    }
};

int main(){
    Prostopadloscian nazwa;
    Kula inna;
    FunckjaKwadratowa funkcja;
    Student uczen;

    cout<<"Podaj a, b, h: "<<endl;
    cin>>nazwa.a>>nazwa.b>>nazwa.h;
    cout<<"Pole powierzchni prostopadloscianu: "<<nazwa.oblicz(nazwa.a, nazwa.b, nazwa.h)<<endl;
    cout<<"Podaj R kuli: "<<endl;
    cin>>inna.r;
    cout<<"Objetosc kuli: "<<inna.oblicz(inna.r)<<endl;
    cout<<"Podaj a, b c: "<<endl;
    cin>>funkcja.a>>funkcja.b>>funkcja.c;
    funkcja.wyswietl(funkcja.a, funkcja.b, funkcja.c);
    cout<<"Podaj imie, nazwisko, numer albumu, ilosc pytan, ilosc poprawnych odpowiedzi: "<<endl;
    cin>>uczen.imie>>uczen.nazwisko>>uczen.nr_albumu>>uczen.l_pytan>>uczen.popr_odp;
    cout<<uczen.imie<<" "<<uczen.nazwisko<<" mial "<<uczen.procent(uczen.l_pytan, uczen.popr_odp)<<"%"<<endl;
    return 0;
}
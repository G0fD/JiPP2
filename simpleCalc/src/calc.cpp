#include "calc.h"
#include <iostream>

int Madd(int a, int b){
    return a + b;
}
int Msub(int a, int b){
    return a - b;
}
double Mvol(int a, int b, int h, int H){
    return double(((a+b)*h)/2.*H);
}
void Mhelp(){
    std::cout<<"Prosty kalkulator"<<std::endl<<"Dzialania: "<<std::endl;
    std::cout<<"add [a] [b]"<<std::endl<<"\tDodawanie liczb calkowitych [a] i [b]"<<std::endl;
    std::cout<<"subtract [a] [b]"<<std::endl<<"\tOdejmowanie liczby [b] od liczby [a]"<<std::endl;
    std::cout<<"volume [a] [b] [h] [H]"<<std::endl<<"\tObliczenie objetosci graniastoslupa prostego o podstawie trapezu"<<std::endl;
    std::cout<<"\tPole podstawy wyliczane ze wzoru (([a]+[b])*[h])/[2], objetosc otrzymuje sie przez pomnozenie pola podstawy przez [H]"<<std::endl;
    std::cout<<"help"<<std::endl<<"\tWyswietlenie dokumentacji"<<std::endl<<std::endl;
    std::cout<<"Bledy:"<<std::endl<<"0x1"<<std::endl<<"\tBlad ten oznacza bledna nazwe dzialania"<<std::endl<<"0x2"<<std::endl<<"\tBlad ten oznacza bledna ilosc parametrow"<<std::endl<<"0x3"<<std::endl<<"\tBlad ten oznacza brak parametrow"<<std::endl<<"0x4"<<std::endl<<"\tBlad ten oznacza cyfre mniejsza lub rowna zeru wprowadzona podczas liczenia objetosci"<<std::endl;
}
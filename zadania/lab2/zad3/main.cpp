#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void policz(int *jed, int *dwa, double *sre){
    *sre=(*jed+*dwa)/2.;
}
void znajdz(int *&tab){
    for(int i=0; i<10;i++){
        if(tab[i]>=0)
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void sortuj(int *jed, int *dwa, int *trz, int *czt, int *pie){
    int temp[]{*jed, *dwa, *trz, *czt, *pie};
    int n = sizeof(temp) / sizeof(temp[0]);
    sort(temp, temp + n);
    *jed=temp[0];*dwa=temp[1];*trz=temp[2];*czt=temp[3];*pie=temp[4];
}
void funkcja(int x, int* w){
    *w=x;
}

int main(){
    int pierwsza, druga;
    int *tablica=new int[10];
    double srednia;
    cout<<"Podaj dwie liczby: ";
    cin>>pierwsza>>druga;
    policz(&pierwsza, &druga, &srednia);
    cout<<"Srednia: "<<srednia<<endl<<endl;
    cout<<"Podaj 10 elementow tablicy (int): ";
    for(int i=0; i<10; i++){
        cin>>tablica[i];
    }
    znajdz(tablica);

    int jeden=23;
    int dwa=25;
    int trzy=214;
    int cztery=1;
    int piec=0;

    sortuj(&jeden, &dwa, &trzy, &cztery, &piec);
    cout<<endl<<endl<<"Posortowane: "<<jeden<<" "<<dwa<<" "<<trzy<<" "<<cztery<<" "<<piec<<" "<<endl<<endl;

    int calkowita, wskazywana;
    calkowita=123;
    funkcja(calkowita, &wskazywana);
    cout<<"Wartosc X wpisana do zmiennej przez wskaznik: "<<wskazywana<<endl;
    return 0;
}
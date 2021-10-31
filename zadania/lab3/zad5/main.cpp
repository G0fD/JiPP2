//Czesc 3
#include<iostream>
using namespace std;

class Punkt{
public:
    int &wspx, &wspy;
    Punkt(int &x, int &y);
};

Punkt::Punkt(int &x, int &y)
:wspx(x),wspy(y)
{
    if (wspx<wspy)cout<<"Odleglosc punktow: "<<wspy-wspx<<endl;
    else cout<<"Odleglosc punktow: "<<wspx-wspy<<endl;
}

class Figura{
public:
    int &l_wierzcholkow;
    int *tablica = new int[l_wierzcholkow];
    Figura(int &liczba);
};

Figura::Figura(int &liczba)
:l_wierzcholkow(liczba)
{
}

int main(){
    int x, y, temp;
    cout<<"Podaj dwa punkty: "<<endl;
    cin>>x>>y;
    Punkt odleglosc(x, y);
    cout<<"Podaj ilosc wierzcholkow: "<<endl;
    cin>>temp;
    Figura wierzcholki(temp);
    for(int i=0; i<wierzcholki.l_wierzcholkow; i++){
        cout<<"Podaj wierzcholek: "<<i+1<<endl;
        cin>>wierzcholki.tablica[i];
    }
    for (int i=0;i<wierzcholki.l_wierzcholkow; i++)cout<<wierzcholki.tablica[i]<<" ";
    return 0;
}
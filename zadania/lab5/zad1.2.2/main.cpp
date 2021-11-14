#include <iostream>
using namespace std;

class Pojazd{
private:
    string nr_rejestr;
    string nazwa;
    int il_miejsc;
    string marka_typ;
    string *dane;

public:
    Pojazd(string nr_rejestr, string nazwa, int il_miejsc, string marka_typ)
    {
        dane=new string[il_miejsc];
        this->nr_rejestr=nr_rejestr;
        this->nazwa=nazwa;
        this->il_miejsc=0;
        this->marka_typ=marka_typ;
        for(int i=0; i<il_miejsc; i++)
            dane[i]="puste";
    }
    void wypisz(){
        cout<<nr_rejestr<<" "<<nazwa<<" "<<il_miejsc<<" "<<marka_typ<<" "<<endl;
        cout<<dane[0]<<endl<<dane[11]<<endl;
    }
    void dodaj(int miejsce, string imnazw){
        dane[miejsce]=imnazw;
   }
   Pojazd(Pojazd& pojazd){
        nr_rejestr=pojazd.nr_rejestr;
        nazwa=pojazd.nazwa;
        il_miejsc=pojazd.il_miejsc;
        marka_typ=pojazd.marka_typ;
        *dane=*pojazd.dane;
    }
    string getNazwa(){
        return nazwa;
    }
    string getNrRejestr(){
        return nr_rejestr;
    }
    string getMarkaTyp(){
        return marka_typ;
    }
    void setNazwa(string x){
        nazwa=x;
    }
    void setNrRejestr(string x){
        nr_rejestr=x;
    }
};

int main() {
    Pojazd autobus("K2NOOB", "idk", 12, "BMW M3 Competiton");
    autobus.dodaj(0,"Ten Ktos");
    autobus.dodaj(11, "Ola Kot");
    autobus.wypisz();

    cout<<"setter i wypisanie przez getter"<<endl;

    autobus.setNazwa("Nowa nazwa");
    autobus.setNrRejestr("KWI00000");
    cout<<autobus.getNazwa()<<endl<<autobus.getNrRejestr()<<endl<<autobus.getMarkaTyp()<<endl;
    return 0;
}

#include <iostream>
using namespace std;

class Pojazd{
private:
    string nr_rejestr;
    string nazwa;
    int il_miejsc;
    string marka_typ;
    string *dane;
    static string najnowsza_wersja_oprogramowania;
    string zainstalowana_wersja_oprogramowania;
public:
    Pojazd(string nr_rejestr, string nazwa, int il_miejsc, string marka_typ, string x)
    {
        dane=new string[il_miejsc];
        this->nr_rejestr=nr_rejestr;
        this->nazwa=nazwa;
        this->il_miejsc=0;
        this->marka_typ=marka_typ;
        for(int i=0; i<il_miejsc; i++)
            dane[i]="puste";
        zainstalowana_wersja_oprogramowania=x;
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
    string getWerOprog(){
        return zainstalowana_wersja_oprogramowania;
    }
    void zaktualizuj(){
        zainstalowana_wersja_oprogramowania=najnowsza_wersja_oprogramowania;
    }

    static void opublikujNoweOprogramowanie(string x){
        najnowsza_wersja_oprogramowania=x;
    }
};

string Pojazd::najnowsza_wersja_oprogramowania="v1.9";


int main() {
    int cVal = 314;
    int test = 12;
    const int *p = &cVal;
    cout<<cVal<<"  "<<p<<"  "<<*p<<endl;
    cVal=132;
    cout<<cVal<<"  "<<p<<"  "<<*p<<endl;
    //*p=test;      //read-only
    //*p=628;
    p=&test;
    cout<<cVal<<"  "<<p<<"  "<<*p<<endl;

    int cVal2 = 314;
    int *const p2 = &cVal2;
    cout<<"P2"<<endl<<cVal2<<"  "<<p2<<"  "<<*p2<<endl;
    *p2=123;
    cout<<cVal2<<"  "<<p2<<"  "<<*p2<<endl;
    cVal2=989;
    cout<<cVal2<<"  "<<p2<<"  "<<*p2<<endl;
    //p2=&test;     //nie mozna

    int cVal3 = 314;
    const int* const youCantModifyMe = &cVal3;
    cout<<"P3"<<endl<<cVal3<<"  "<<youCantModifyMe<<"  "<<*youCantModifyMe<<endl;
    //youCantModifyMe=12;       //nie mozna
    //*youCantModifyMe=test;    //nie mozna
    cVal3=123;
    cout<<cVal3<<"  "<<youCantModifyMe<<"  "<<*youCantModifyMe<<endl;

    Pojazd samochod("KR1234", "idk", 5,"Marka Typ", "v1.1");
    cout<<endl<<endl<<samochod.getWerOprog()<<endl;
    samochod.zaktualizuj();
    cout<<samochod.getWerOprog()<<endl;

    samochod.opublikujNoweOprogramowanie("v2.3");
    samochod.zaktualizuj();
    cout<<samochod.getWerOprog()<<endl;
}

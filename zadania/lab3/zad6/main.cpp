//Czesc 4

#include <iostream>
using namespace std;

class Klasa{
public:
    int *tablica = new int[1024];
    Klasa();
    ~Klasa();
    void pause(){
        system("PAUSE");
    }
};

Klasa::Klasa() {
    cout<<"Konstruktor nie zostal wywolany"<<endl;
}

Klasa::~Klasa() {
    cout<<"Dekonstruktor dziala"<<endl;
    delete [] tablica;
}

int main(){
    //Klasa *kls;   //nie wyswietla nic
    Klasa cos;      //wyswietla konstruktor i dekonstruktor
    cos.pause();
    return 0;
}
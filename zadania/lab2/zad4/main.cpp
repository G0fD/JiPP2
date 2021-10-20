#include <iostream>
#include <string.h>

using namespace std;

int konwertuj(const char* tekst) {
    int wynik = 0;
    for (int i = 0; tekst[i]; i++) {
        if (tekst[i] >= '0' && tekst[i] <= '9') {
            wynik*=10;
            wynik += (tekst[i] - '0');  //0 to 48 w ASCII
            //tekst[i] przyjmuje wartosc ASCII 48-57 skoro jest cyfra 0-9
        }else {
            throw "wprowadzony ciag zawiera nieprawidlowe znaki";
        }
        if (wynik < 0) {
            throw "wprowadzona liczba jest za duza";
        }
    }
    return wynik;
}

int main() {
    string str;
    cin>>str;
    char* tekst = str.data();
    try {
        cout << konwertuj(tekst);
    }
    catch (const char* myTxT) {
        cout << myTxT;
    }
    cout<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    try {
        int a,b,wynik;
        double wyn;
        cout<<"Podaj a i b: \n";
        cin>>a>>b;
        wynik=a/b;
        wyn=double (a)/double (b);
        if (wynik==wyn) {
            cout << "Wynik dzielenia: "<<wyn<<endl;
        } else {
            throw "Wynikiem nie moze byc ulamek";
        }
    }
    catch (char const* myTxT) {
        cout << "Blad: " << myTxT<<endl;
    }
    return 0;
}

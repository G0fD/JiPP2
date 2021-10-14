#include <iostream>
#include <string.h>
#include "calc.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc==1){
        cout << "Blad 0x3" <<endl<<endl;
        Mhelp();
    }
    else if (strcmp(argv[1], "add") == 0){
        if(argc==4) {
            cout << "Wynik: " << Madd(atoi(argv[2]), atoi(argv[3])) << endl;
        }
        else {
            cout << "Blad 0x2" <<endl<<endl;
            Mhelp();
        }
    }
    else if (strcmp(argv[1], "subtract") == 0){
        if(argc==4) {
            cout << "Wynik: " << Msub(atoi(argv[2]), atoi(argv[3])) << endl;
        }
        else {
            cout << "Blad 0x2" <<endl<<endl;
            Mhelp();
        }
    }
    else if (strcmp(argv[1], "volume") == 0){
        if(argc==6) {
            for(int i=2; i<argc; i++){
                if ( (atoi(argv[i]))<=0) {
                    cout << "Blad 0x4" << endl << endl;
                    Mhelp();
                    return 0;
                }
            }
            cout << "Wynik: " << Mvol(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])) << endl;
        }
        else {
            cout << "Blad 0x2" <<endl<<endl;
            Mhelp();
        }
    }
    else if (strcmp(argv[1], "help") == 0){
        if(argc==2) {
            Mhelp();
        }
        else {
            cout << "Blad 0x2" <<endl<<endl;
            Mhelp();
        }
    }
    else {
        cout<<"Blad 0x1"<<endl<<endl;
        Mhelp();
    }
    return 0;
}
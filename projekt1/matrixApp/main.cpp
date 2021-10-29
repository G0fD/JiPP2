#include <iostream>
#include <string.h>
#include <math.h>
#include "matrix.h"
using namespace std;

void Mhelp();
void zwolnij(int **& intowe, double **& doublowe, int n);

int main(int argc, char* argv[]) {
    int wierszy, kolumn, intczydouble=0;
    if (argc==1 || strcmp(argv[1], "help") == 0){
        Mhelp();
    }
    else {
        if (strcmp(argv[1], "addMatrix") ==0 || strcmp(argv[1], "subtractMatrix") ==0) {
            string stop;
            cout << "Podaj romiar macierzy: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            double **doublematrixa = new double *[wierszy];
            double **doublematrixb = new double *[wierszy];
            double **doubletemp = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            int **intmatrixb = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                intmatrixb[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
                doublematrixb[i] = new double[kolumn];
                doubletemp[i] = new double[kolumn];
            }
            //dynamiczne tablice 2D

            if (strcmp(argv[1], "addMatrix") == 0){
                cout<<endl<<"Pierwsza macierz: "<<endl;
                for(int i = 0;i<wierszy;++i) {
                    cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                    for (int j = 0;j < kolumn; ++j) {
                        if (cin >> doubletemp[i][j]){
                            if(doubletemp[i][j] - (int)doubletemp[i][j] != 0) ++intczydouble;
                        } else {
                            cout<<"Podano zla wartosc";
                            return 10;
                        }
                        if (j>=kolumn-1)cin.ignore(1000, '\n');
                    }
                }
                if(intczydouble>0){
                    for(int i = 0;i<wierszy;++i){
                        for (int j = 0;j < kolumn; ++j) {
                            doublematrixa[i][j]=doubletemp[i][j];
                        }
                    }
                }else {
                    for(int i = 0;i<wierszy;++i){
                        for (int j = 0;j < kolumn; ++j) {
                            intmatrixa[i][j]=doubletemp[i][j];
                        }
                    }
                }
                //wpisywanie do macierzy A WIERSZAMI!

                cout<<endl<<"Druga macierz: "<<endl;
                for(int i = 0;i<wierszy;++i) {
                    cout << "Podaj element B" << i + 1 << 1 << " : "<<endl;
                    for (int j = 0;j < kolumn; ++j) {
                        if (cin >> doubletemp[i][j]){
                            if(doubletemp[i][j] - (int)doubletemp[i][j] != 0) ++intczydouble;
                        } else {
                            cout<<"Podano zla wartosc";
                            return 10;
                        }
                        if (j>=kolumn-1)cin.ignore(1000, '\n');
                    }
                }
                if(intczydouble>0){
                    doublematrixb=doubletemp;
                }else {
                    for(int i = 0;i<wierszy;++i){
                        for (int j = 0;j < kolumn; ++j) {
                            intmatrixb[i][j]=doubletemp[i][j];
                        }
                    }
                }
                //wpisywanie do macierzy B WIERSZAMI!
                cout<<"Wynik: ";
                if (intczydouble>0) {
                    doublematrixa = addMatrix(doublematrixa, doublematrixb, wierszy, kolumn);
                    cout<<endl;
                    for(int i = 0;i<wierszy;++i) {
                        for (int j = 0; j < kolumn; ++j)cout << doublematrixa[i][j] << " ";
                        cout<<endl;
                    }
                }else {
                    intmatrixa= addMatrix(intmatrixa, intmatrixb, wierszy, kolumn);
                    cout<<endl;
                    for(int i = 0;i<wierszy;++i) {
                        for (int j = 0; j < kolumn; ++j)cout << intmatrixa[i][j] << " ";
                        cout<<endl;
                    }
                }
                //Dodawanie z wypisywaniem
            }
            else if (strcmp(argv[1], "subtractMatrix") == 0) {
                cout << endl << "Pierwsza macierz: " << endl;
                for (int i = 0; i < wierszy; ++i) {
                    cout << "Podaj element A" << i + 1 << 1 << " : " << endl;
                    for (int j = 0;j < kolumn; ++j) {
                        if (cin >> doubletemp[i][j]){
                            if(doubletemp[i][j] - (int)doubletemp[i][j] != 0) ++intczydouble;
                        } else {
                            cout<<"Podano zla wartosc";
                            return 10;
                        }
                        if (j>=kolumn-1)cin.ignore(1000, '\n');
                    }
                }
                if (intczydouble > 0) {
                    for (int i = 0; i < wierszy; ++i) {
                        for (int j = 0; j < kolumn; ++j) {
                            doublematrixa[i][j] = doubletemp[i][j];
                        }
                    }
                } else {
                    for (int i = 0; i < wierszy; ++i) {
                        for (int j = 0; j < kolumn; ++j) {
                            intmatrixa[i][j] = doubletemp[i][j];
                        }
                    }
                }
                //wpisywanie do macierzy A WIERSZAMI!

                cout << endl << "Druga macierz: " << endl;
                for (int i = 0; i < wierszy; ++i) {
                    cout << "Podaj element B" << i + 1 << 1 << " : " << endl;
                    for (int j = 0;j < kolumn; ++j) {
                        if (cin >> doubletemp[i][j]){
                            if(doubletemp[i][j] - (int)doubletemp[i][j] != 0) ++intczydouble;
                        } else {
                            cout<<"Podano zla wartosc";
                            return 10;
                        }
                        if (j>=kolumn-1)cin.ignore(1000, '\n');
                    }
                }
                if (intczydouble > 0) {
                    doublematrixb = doubletemp;
                } else {
                    for (int i = 0; i < wierszy; ++i) {
                        for (int j = 0; j < kolumn; ++j) {
                            intmatrixb[i][j] = doubletemp[i][j];
                        }
                    }
                }
                //wpisywanie do macierzy B WIERSZAMI!
                cout<<"Wynik: ";
                if (intczydouble > 0) {
                    doublematrixa = subtractMatrix(doublematrixa, doublematrixb, wierszy, kolumn);
                    cout << endl;
                    for (int i = 0; i < wierszy; ++i) {
                        for (int j = 0; j < kolumn; ++j)cout << doublematrixa[i][j] << " ";
                        cout << endl;
                    }
                } else {
                    intmatrixa = subtractMatrix(intmatrixa, intmatrixb, wierszy, kolumn);
                    cout << endl;
                    for (int i = 0; i < wierszy; ++i) {
                        for (int j = 0; j < kolumn; ++j)cout << intmatrixa[i][j] << " ";
                        cout << endl;
                    }
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
            zwolnij(intmatrixb, doublematrixb, wierszy);
        }
        else if (strcmp(argv[1], "multiplyMatrix") == 0) {
            int kolumnb;
            cout<<"Podaj rozmiar macierzy: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            cout << "Podaj ilosc kolumn macierzy B: ";
            if(cin >>kolumnb)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }

            double **doublematrixa = new double *[wierszy];
            double **doublematrixb = new double *[kolumn];
            double **doublewynik = new double *[wierszy];
            int **intwynik = new int *[wierszy];
            int **intmatrixa = new int *[wierszy];
            int **intmatrixb = new int *[kolumn];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                intwynik[i] = new int [kolumnb];
                doublematrixa[i] = new double[kolumn];
                doublewynik[i] = new double [kolumnb];
            }
            for(int i =0; i<kolumn; i++){
                doublematrixb[i] = new double[kolumnb];
                intmatrixb[i] = new int[kolumnb];
            }
            //MACIERZE

            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            //wpisywanie do macierzy A WIERSZAMI!
            cout<<endl<<"Druga macierz: "<<endl;
            for(int i = 0;i<kolumn;i++) {
                cout << "Podaj element B" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumnb; j++) {
                    if (cin >> doublematrixb[i][j]){
                        if(doublematrixb[i][j] - (int)doublematrixb[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumnb-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0){
                for(int i = 0;i<kolumn;i++){
                    for (int j = 0;j < kolumnb; j++) {
                        intmatrixb[i][j]=doublematrixb[i][j];
                    }
                }
            }
            //wpisywanie do macierzy B wierszami
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                doublewynik = multiplyMatrix(doublematrixa, doublematrixb, wierszy, kolumn, kolumnb);
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumnb; ++j)cout << doublewynik[i][j] << " ";
                    cout<<endl;
                }
            }else {
                intwynik= multiplyMatrix(intmatrixa, intmatrixb, wierszy, kolumn, kolumnb);
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumnb; ++j)cout << intwynik[i][j] << " ";
                    cout<<endl;
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
            zwolnij(intwynik, doublewynik, wierszy);
            zwolnij(intmatrixb, doublematrixb, kolumn);
        } //Mnozenie z wypisywaniem
        else if (strcmp(argv[1], "multiplyByScalar") == 0) {
            int intskalar;
            double doubleskalar;
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            cout<<"Podaj skalar: ";
            if(cin >> doubleskalar){
                if(doubleskalar-(int)doubleskalar != 0) ++intczydouble;
            }
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }

            double **doublematrixa = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }
            cout<<endl<<"Macierz A: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
                intskalar=doubleskalar;
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                doublematrixa = multiplyByScalar(doublematrixa, wierszy, kolumn, doubleskalar);
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumn; ++j)cout << doublematrixa[i][j] << " ";
                    cout<<endl;
                }
            }else {
                intmatrixa= multiplyByScalar(intmatrixa, wierszy, kolumn, intskalar);
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumn; ++j)cout << intmatrixa[i][j] << " ";
                    cout<<endl;
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
        }//Mnozenie przez skalar
        else if (strcmp(argv[1], "transpozeMatrix") == 0) {
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }

            double **doublematrixa = new double *[wierszy];
            double **doublewynik = new double *[kolumn];
            int **intwynik = new int *[kolumn];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }
            for(int i = 0; i<kolumn; i++){
                doublewynik[i] = new double[wierszy];
                intwynik[i] = new int[wierszy];
            }
            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                doublewynik = transpozeMatrix(doublematrixa, wierszy, kolumn);
                for(int i = 0;i<kolumn;++i) {
                    for (int j = 0; j < wierszy; ++j)cout << doublewynik[i][j] << " ";
                    cout<<endl;
                }
            }else {
                intwynik= transpozeMatrix(intmatrixa, wierszy, kolumn);
                for(int i = 0;i<kolumn;++i) {
                    for (int j = 0; j < wierszy; ++j)cout << intwynik[i][j] << " ";
                    cout<<endl;
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
            zwolnij(intwynik, doublewynik, kolumn);
        }//TRANSPONOWANIE
        else if (strcmp(argv[1], "powerMatrix") == 0) {
            if(argv[2]==NULL || atoi(argv[2])==0 || atof(argv[2])-atoi(argv[2])!=0 ) {
                cout<<"Brak potegi lub bledna wartosc"<<endl;
                return 11;
            }
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc"<<endl;
                return 10;
            }
            if(wierszy!=kolumn){
                cout<<"Macierz musi byc kwadratowa"<<endl;
                return 12;
            }
            double **doublematrixa = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }

            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                doublematrixa = powerMatrix(doublematrixa, wierszy, kolumn, atoi(argv[2]));
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumn; ++j)cout << doublematrixa[i][j] << " ";
                    cout<<endl;
                }
            }else {
                intmatrixa= powerMatrix(intmatrixa, wierszy, kolumn, atoi(argv[2]));
                for(int i = 0;i<wierszy;++i) {
                    for (int j = 0; j < kolumn; ++j)cout << intmatrixa[i][j] << " ";
                    cout<<endl;
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
        }//POTEGOWANIE
        else if (strcmp(argv[1], "determinantMatrix") == 0) {
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            if(wierszy!=kolumn){
                cout<<"Macierz musi byc kwadratowa";
                return 12;
            }
            double **doublematrixa = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }
            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                cout<<determinantMatrix(doublematrixa,wierszy,kolumn)<<endl;
            }else cout<<determinantMatrix(intmatrixa,wierszy,kolumn)<<endl;
            zwolnij(intmatrixa, doublematrixa, wierszy);
        }//WYZNACZNIK MACIERZY
        else if (strcmp(argv[1], "matrixIsDiagonal") == 0) {
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            if(wierszy!=kolumn){
                cout<<"Macierz musi byc kwadratowa"<<endl;
                return 12;
            }
            double **doublematrixa = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }
            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                if(matrixIsDiagonal(doublematrixa,wierszy,kolumn)==0)cout<<"Macierz jest diagnizowalna";
                else cout<<"Macierz nie jest diagonizowalna";

            }else{
                if(matrixIsDiagonal(intmatrixa,wierszy,kolumn)==0)cout<<"Macierz jest diagnizowalna";
                else cout<<"Macierz nie jest diagonizowalna";
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
        }//CZY DIAGONIZOWALNA
        else if (strcmp(argv[1], "swap") == 0) {
            int inta, intb;
            double doublea, doubleb;
            cout << "Podaj wartosc a i b: ";
            if(cin >> doublea >> doubleb)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            intczydouble=1;
            if(doublea-(int)doublea == 0 && doubleb-(int)doubleb == 0){
                inta=doublea; intb=doubleb; intczydouble=0;
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                swap(&doublea, &doubleb); cout<<doublea<<" "<<doubleb;
            }else{
                swap(&inta, &intb); cout<<inta<<" "<<intb;
            }
        }//ZAMIANA
        else if (strcmp(argv[1], "sortRow") == 0) {
            cout<<"Podaj ilosc liczb w tablicy: ";
            if(cin >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc"<<endl;
                return 10;
            }
            if(kolumn<=0){
                cout<<"Podano zla wartosc"<<endl;
                return 10;
            }
            int *inttab = new int[kolumn];
            double *doubletab = new double[kolumn];
            cout<<"Podaj elementy tablicy: ";
            for(int i=0; i<kolumn; i++){
                if (cin >> doubletab[i]){
                    if(doubletab[i] - (int)doubletab[i] != 0) ++intczydouble;
                } else {
                    cout<<"Podano zla wartosc";
                    return 10;
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                sortRow(doubletab, kolumn);
                for(int i=0; i<kolumn; i++) cout<<doubletab[i]<<" ";
            }else{
                for(int i=0; i<kolumn; i++)inttab[i]=doubletab[i];
                sortRow(inttab, kolumn);
                for(int i=0; i<kolumn; i++) cout<<inttab[i]<<" ";
            }
            cout<<endl;
            delete [] inttab; delete [] doubletab;
        }//SORTOWANIE ARRAY
        else if (strcmp(argv[1], "sortRowsInMatrix") == 0) {
            cout << "Podaj romiar macierzy A: ";
            if(cin >> wierszy >> kolumn)cin.ignore(1000, '\n');
            else{
                cout<<"Podano zla wartosc";
                return 10;
            }
            double **doublematrixa = new double *[wierszy];
            int **intmatrixa = new int *[wierszy];
            for (int i = 0; i < wierszy; i++) {
                intmatrixa[i] = new int[kolumn];
                doublematrixa[i] = new double[kolumn];
            }

            cout<<endl<<"Pierwsza macierz: "<<endl;
            for(int i = 0;i<wierszy;++i) {
                cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
                for (int j = 0;j < kolumn; ++j) {
                    if (cin >> doublematrixa[i][j]){
                        if(doublematrixa[i][j] - (int)doublematrixa[i][j] != 0) ++intczydouble;
                    } else {
                        cout<<"Podano zla wartosc";
                        return 10;
                    }
                    if (j>=kolumn-1)cin.ignore(1000, '\n');
                }
            }
            if (intczydouble==0) {
                for(int i = 0;i<wierszy;++i){
                    for (int j = 0;j < kolumn; ++j) {
                        intmatrixa[i][j]=doublematrixa[i][j];
                    }
                }
            }
            cout<<"Wynik: "<<endl;
            if (intczydouble>0) {
                doublematrixa=sortRowsInMatrix(doublematrixa, wierszy, kolumn);
                for (int i = 0; i < wierszy; ++i) {
                    for (int j = 0; j < kolumn; ++j)cout << doublematrixa[i][j] << " ";
                    cout << endl;
                }
            }
            else{
                sortRowsInMatrix(intmatrixa, wierszy, kolumn);
                for (int i = 0; i < wierszy; ++i) {
                    for (int j = 0; j < kolumn; ++j)cout << intmatrixa[i][j] << " ";
                    cout << endl;
                }
            }
            zwolnij(intmatrixa, doublematrixa, wierszy);
        }
        else {
            Mhelp();
        }
    }
    return 0;
}

void Mhelp(){
    cout<<"Projekt 1"<<endl<<"Ogolne informacje: "<<endl;
    cout<<"Wprowadzanie rozmiaru macierzy"<<endl<<"\tNajpierw podaje sie ilosc wierszy, a nastepnie ilosc kolum. Liczby musza byc oddzielone spacja"<<endl<<endl;
    cout<<"Wprowadzanie elementow macierzy"<<endl<<"\tElementy dodaje sie wierszami oddzielone spacja, poczatek kolejnego wiersza jest komunikowany przez program"<<endl<<endl;
    cout<<"Wprowadzono za duzo elementow"<<endl<<"\tProgram sam ignoruje dodatkowe wartosci, do obliczen zostana wykorzystane te, ktore wprowadzono jako pierwsze"<<endl<<endl;
    cout<<"Wprowadzono niepoprawny parametr"<<endl<<"\tZostaje wypisana odpowiednia informacja, a program sie konczy"<<endl<<endl;
    cout<<"Dzialania:"<<endl;
    cout<<"addMatrix"<<endl<<"\tDodawanie macierzy. Macierze musza byc takiego samego rozmiaru"<<endl<<endl<<"subtractMatrix"<<endl<<"\tOdejmowanie macierzy. Macierze musza byc takiego samego rozmiaru"<<endl<<endl<<"multiplyMatrix"<<endl<<"\tMnozenie macierzy. Ilosc kolumn pierwszej macierzy musi odpowiadac ilosci wierszy drugiej co jest wykonywane automatycznie. Liczba kolumn drugiej macierzy jest podawana przez uzytkownika w trakcie dzialania programu. Program sumuje iloczyny odpowiadajacych liczb z wierszy macierzy A z kolejnymi liczbami w wierszach macierzy B"<<endl<<endl;
    cout<<"multiplyByScalar"<<endl<<"\tMnozenie macierzy przez skalar, czyli liczbe. Kazdy element macierzy zostaje pomnozony przez skalar"<<endl<<endl<<"transpozeMatrix"<<endl<<"\tTransponowanie podanej macierzy. Polega to na zamianie miejscami kolumn z wierszami"<<endl<<endl<<"powerMatrix liczba"<<endl<<"\tPodniesienie kwadratowej macierzy do podanej naturalnej potegi. Potega jest drugim argumentem podawanym po spacji przy uruchamianiu programu (tutaj 'liczba')"<<endl<<endl;
    cout<<"determinantMatrix"<<endl<<"\tWyliczanie wyznacznika macierzy. Macierz musi byc kwadratowa"<<endl<<endl<<"matrixIsDiagonal"<<endl<<"\tSprawdza czy macierz jest diagonalna i zwraca 0 badz 1 w zaleznosci od wyniku funkcji, wartosci te sa interpretowane przez program i wypisywana jest stosowna informacja"<<endl<<endl;
    cout<<"swap"<<endl<<"\tZamiana miejscami wartosci a i b. Program prosi o podanie tych wartosci"<<endl<<endl<<"sortRow"<<endl<<"\tUzytkownik jest proszony o wpisanie ilosci kolum(elementow tablicy), a nastepnie program wczytuje liczby oddzielone spacja. Tablica jest sortowana przy uzyciu bubblesort."<<endl<<endl;
    cout<<"sortRowsInMatrix"<<endl<<"\tSortowanie wierszy w macierzy. Program rosnaco sortuje kazdy wiersz podanej macierzy"<<endl<<endl;
}

void zwolnij(int **& intowe, double **& doublowe, int n){
    for(int i=0; i<n; i++){
        delete [] intowe[i];
        delete [] doublowe[i];
    }
    delete [] intowe;
    delete [] doublowe;
}
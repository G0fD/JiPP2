#include "matrix.h"
#include <iostream>
#include <math.h>

using namespace std;

int** addMatrix(int **a, int **b, int wiersze, int kolumny){
    int** wynik = new int*[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new int[kolumny];

    for(int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    return wynik;
}
double** addMatrix(double **a, double **b, int wiersze, int kolumny){
    double ** wynik = new double *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new double [kolumny];

    for(int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            wynik[i][j] = a[i][j] + b[i][j];
        }
    }
    return wynik;
}

int** subtractMatrix(int **a, int **b, int wiersze, int kolumny){
    int** wynik = new int*[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new int[kolumny];

    for(int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    return wynik;
}
double** subtractMatrix(double **a, double **b, int wiersze, int kolumny){
    double ** wynik = new double *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new double [kolumny];

    for(int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            wynik[i][j] = a[i][j] - b[i][j];
        }
    }
    return wynik;
}

int** multiplyMatrix(int **a, int **b, int w1, int k1, int k2){
    int ** wynik = new int *[w1];
    for(int i = 0; i < w1; i++) wynik[i] = new int [k2];

    for( int i = 0; i < w1; i++ ) {
        for (int j = 0; j < k2; j++) {
            int temp = 0;
            for (int k = 0; k < k1; k++) {
                temp += a[i][k] * b[k][j];
            }
            wynik[i][j] = temp;
        }
    }
    return wynik;
}
double** multiplyMatrix(double **a, double **b, int w1, int k1, int k2){
    double ** wynik = new double *[w1];
    for(int i = 0; i < w1; i++) wynik[i] = new double [k2];

    for( int i = 0; i < w1; i++ ) {
        for (int j = 0; j < k2; j++) {
            double temp = 0;
            for (int k = 0; k < k1; k++) {
                temp += a[i][k] * b[k][j];
            }
            wynik[i][j] = temp;
        }
    }
    return wynik;
}

int** multiplyByScalar(int **a, int wiersze, int kolumny, int skalar){
    int ** wynik = new int *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new int [kolumny];

    for(int i = 0; i < wiersze; i++) {
        for(int j = 0; j < kolumny; j++){
            wynik[i][j]=a[i][j]*skalar;
        }
    }
    return wynik;
}
double** multiplyByScalar(double **a, int wiersze, int kolumny, double skalar){
    double ** wynik = new double *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new double [kolumny];

    for(int i = 0; i < wiersze; i++) {
        for(int j = 0; j < kolumny; j++){
            wynik[i][j]=a[i][j]*skalar;
        }
    }
    return wynik;
}

int** transpozeMatrix(int **a, int wiersze, int kolumny){
    int ** wynik = new int *[kolumny];
    for(int i = 0; i < kolumny; i++) wynik[i] = new int [wiersze];

    for(int i = 0; i < kolumny; i++) {
        for(int j = 0; j < wiersze; j++){
            wynik[i][j]=a[j][i];
        }
    }
    return wynik;
}
double** transpozeMatrix(double **a, int wiersze, int kolumny){
    double ** wynik = new double *[kolumny];
    for(int i = 0; i < kolumny; i++) wynik[i] = new double [wiersze];

    for(int i = 0; i < kolumny; i++) {
        for(int j = 0; j < wiersze; j++){
            wynik[i][j]=a[j][i];
        }
    }
    return wynik;
}

int** powerMatrix(int **a, int wiersze, int kolumny, unsigned potega){
    int ** wynik = new int *[wiersze];
    for(int i = 0; i < wiersze+1; i++) wynik[i] = new int [kolumny];
    wynik=a;
    for(int i = 0; i<potega-1; i++){
        wynik = multiplyMatrix(wynik,a,wiersze,kolumny,kolumny);
    }
    return wynik;
}
double** powerMatrix(double **a, int wiersze, int kolumny, unsigned potega){
    double ** wynik = new double *[wiersze];
    for(int i = 0; i < wiersze+1; i++) wynik[i] = new double [kolumny];
    wynik=a;
    for(int i = 0; i<potega-1; i++){
        wynik = multiplyMatrix(wynik,a,wiersze,kolumny,kolumny);
    }
    return wynik;
}

int determinantMatrix(int **a, int wiersze, int kolumny){
    int tempwynik = 0;
    int ** wynik = new int *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new int [kolumny];

    if (wiersze == 1 && kolumny == 1){
        return a[0][0];
    }
    if (wiersze == 2 && kolumny == 2) {
        return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
    }
    else {
        for (int i = 0; i < wiersze; i++) {
            int tempjeden = 0;
            for (int j = 1; j < wiersze; j++) {
                int tempdwa = 0;
                for (int k = 0; k < wiersze; k++) {
                    if (k != i) {
                        wynik[tempjeden][tempdwa] = a[j][k];
                        tempdwa++;
                    }
                }
                tempjeden++;
            }
            tempwynik += (pow(-1, i) * a[0][i] * determinantMatrix( wynik, wiersze - 1, kolumny-1 ));
        }
    }
    return tempwynik;
}
double determinantMatrix(double **a, int wiersze, int kolumny){
    double tempwynik = 0;
    double ** wynik = new double *[wiersze];
    for(int i = 0; i < wiersze; i++) wynik[i] = new double [kolumny];

    if (wiersze == 1 && kolumny == 1){
        return a[0][0];
    }
    if (wiersze == 2 && kolumny == 2) {
        return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
    }
    else {
        for (int i = 0; i < wiersze; i++) {
            int tempjeden = 0;
            for (int j = 1; j < wiersze; j++) {
                int tempdwa = 0;
                for (int k = 0; k < wiersze; k++) {
                    if (k != i) {
                        wynik[tempjeden][tempdwa] = a[j][k];
                        tempdwa++;
                    }
                }
                tempjeden++;
            }
            tempwynik += (pow(-1, i) * a[0][i] * determinantMatrix( wynik, wiersze - 1, kolumny-1 ));
        }
    }
    return tempwynik;
}

bool matrixIsDiagonal(int **a, int wiersze, int kolumny) {
    int wynik = 0;
    for (int i = 0; i < wiersze; i++){
        for (int j = 0; j < kolumny; j++) {
            if (i == j) {
                if (a[i][j] == 0)
                    wynik = 1;
            } else {
                if (a[i][j] != 0)
                    wynik = 1;
            }
        }
    }
    return wynik;
}
bool matrixIsDiagonal(double **a, int wiersze, int kolumny){
    int wynik = 0;
    for (int i = 0; i < wiersze; i++){
        for (int j = 0; j < kolumny; j++) {
            if (i == j) {
                if (a[i][j] == 0)
                    wynik = 1;
            } else {
                if (a[i][j] != 0)
                    wynik = 1;
            }
        }
    }
    return wynik;
}

void swap(int *a, int *b){
    int temp = *b;
    *b=*a;
    *a=temp;
}
void swap(double *a, double *b){
    double temp = *b;
    *b=*a;
    *a=temp;
}

void sortRow(int *tab, int kolumny){
    int temp;
    for(int i=0; i<kolumny; i++)
    {
        for(int j=0; j<(kolumny-i-1); j++)
        {
            if(tab[j]>tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}
void sortRow(double *tab, int kolumny){
    double temp;
    for(int i=0; i<(kolumny-1); i++)
    {
        for(int j=0; j<(kolumny-i-1); j++)
        {
            if(tab[j]>tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

int** sortRowsInMatrix(int **a, int wiersze, int kolumny){
    int *temp = new int[kolumny];
    int ** wynik = new int *[kolumny];
    for(int i = 0; i < kolumny; i++) wynik[i] = new int [wiersze];

    for(int i=0; i<wiersze; i++){
        for(int j=0; j<kolumny; j++){
            temp[j]=a[i][j];
        }
        sortRow(temp, kolumny);
        for(int j=0; j<kolumny; j++){
            a[i][j]=temp[j];
        }
    }
    return a;
}
double** sortRowsInMatrix(double **a, int wiersze, int kolumny){
    double *temp = new double[kolumny];
    double ** wynik = new double *[kolumny];
    for(int i = 0; i < kolumny; i++) wynik[i] = new double [wiersze];

    for(int i=0; i<wiersze; i++){
        for(int j=0; j<kolumny; j++){
            temp[j]=a[i][j];
        }
        sortRow(temp, kolumny);
        for(int j=0; j<kolumny; j++){
            wynik[i][j]=temp[j];
        }
    }
    return wynik;
}
#pragma once

int** addMatrix(int **a, int **b, int wiersze, int kolumny);
double** addMatrix(double **a, double **b, int wiersze, int kolumny);

int** subtractMatrix(int **a, int **b, int wiersze, int kolumny);
double** subtractMatrix(double **a, double **b, int wiersze, int kolumny);

int** multiplyMatrix(int **a, int **b, int w1, int k1, int k2);
double** multiplyMatrix(double **a, double **b, int w1, int k1, int k2);

int** multiplyByScalar(int **a, int wiersze, int kolumny, int skalar);
double** multiplyByScalar(double **a, int wiersze, int kolumny, double skalar);

int** transpozeMatrix(int **a, int wiersze, int kolumny);
double** transpozeMatrix(double **a, int wiersze, int kolumny);

int** powerMatrix(int **a, int wiersze, int kolumny, unsigned potega);
double** powerMatrix(double **a, int wiersze, int kolumny, unsigned potega);

int determinantMatrix(int **a, int wiersze, int kolumny);
double determinantMatrix(double **a, int wiersze, int kolumny);

bool matrixIsDiagonal(int **a, int wiersze, int kolumny);
bool matrixIsDiagonal(double **a, int wiersze, int kolumny);

void swap(int *a, int *b);
void swap(double *a, double *b);

void sortRow(int *tab, int kolumny);
void sortRow(double *tab, int kolumny);

int** sortRowsInMatrix(int **a, int wiersze, int kolumny);
double** sortRowsInMatrix(double **a, int wiersze, int kolumny);
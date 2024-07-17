#ifndef MATRLIB_H
#define MATRLIB_H

#define MM 100
#define NN 100

typedef double Matr[MM][NN];
void FillMatrKBD(Matr M, int m, int n);
void FillMatrRND(Matr M, int m, int n, int from=-5, int to=10);
void ShowMatr(Matr M, int m, int n);
void ShowMatrRow(Matr M, int m, int n, int row);
void ShowMatrCol(Matr M, int m, int n, int col);
double GetSumOfRow (Matr M, int m, int n, int row);
double GetProdOfRow (Matr M, int m,int n, int row);
double GetSumOfCol (Matr M, int m,int n, int col);
double GetProdOfCol (Matr M, int m,int n, int col);


#endif // MATRLIB_H

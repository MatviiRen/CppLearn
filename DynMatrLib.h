#ifndef DYNMATRLIB_H_INCLUDED
#define DYNMATRLIB_H_INCLUDED

double** createMatr(int m, int n);
void removeMatr(double**& M, int m);
void showMatr(double** M, int m, int n);
void fillMatrRnd(double** M, int m, int n, int from, int to);
int getMinRowPos (double** M, int m, int n, int row);
double getMinElRow (double** M, int m, int n, int row);
int getMaxRowPos (double** M, int m, int n, int row);
double getMaxElRow (double** M, int m, int n, int row);
int getMinColPos (double** M, int m, int n, int col);
double getMinElCol (double** M, int m, int n, int col);
int getMaxColPos (double** M, int m, int n, int col);
double getMaxElCol (double** M, int m, int n, int col);
double getDet(double**M,int m);
double getSumRow (double** M, int m, int n, int row);
double getProdRow (double** M,int m, int n, int row);
double getSumCol (double** M, int m, int n, int col);
double getProdCol (double** M, int m, int n, int col);
double getAvgVal (double** M, int m, int n);
bool IsRowBalance(double**M, int m, int n, int row);
bool IsColBalance(double**M, int m, int n, int col);
bool IsRowEven(double**M, int m, int n, int row);
bool IsColOdd(double**M, int m, int n, int col);
bool IsRowsSimilar(double**M, int m, int n, int row_1, int row_2);


#endif // DYNMATRLIB_H_INCLUDED

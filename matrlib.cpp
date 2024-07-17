#include "matrlib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void FillMatrKBD(Matr M1, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << "M1[" << i << "][" << j << "] = ";
            cin >> M1[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void FillMatrRND(Matr M1, int m, int n, int from, int to){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            M1[i][j] = from + rand()%(to-from);
        }
    }
}

void ShowMatr(Matr M1, int m, int n){
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<setw(6)<< M1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ShowMatrRow(Matr M, int m, int n, int row){
    for(int j=0; j<n; j++){
        cout<<setw(6)<< M[row][j] << " ";
    }
    cout << endl;
}

void ShowMatrCol(Matr M, int m, int n, int col){
    for(int i=0; i<m; i++){
        cout<<setw(6)<< M[i][col] << " ";
    }
    cout << endl;
}

double GetSumOfRow (Matr M, int m, int n, int row){
    double sum=0;
    for (int j=0; j<n; j++){
        sum+=M[row][j];
    }
    return sum;
}

double GetProdOfRow (Matr M, int m,int n, int row){
    double prod=1;
    for (int j=0; j<n; j++){
        prod*=M[row][j];
    }
    return prod;
}

double GetSumOfCol (Matr M, int m,int n, int col) {
    double sum=0;
    for (int i=0; i<m; i++){
        sum+=M[i][col];
    }
    return sum;
}

double GetProdOfCol (Matr M, int m,int n, int col){
    double prod=1;
    for(int i=0; i<m; i++){
        prod*=M[i][col];
    }
    return prod;
}

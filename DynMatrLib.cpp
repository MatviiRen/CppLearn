#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

double** createMatr(int m, int n){
    double** M = new double*[m];
    for (int i=0; i<m; i++){
        M[i] = new double[n];
    }
    return M;
}

void removeMatr(double**& M, int m){
    for (int i=0; i<m; i++){
        delete[] M[i];
    }
    delete[] M;
    M = NULL;
}

void showMatr(double** M, int m, int n){
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<setw(7)<< M[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrRnd(double** M, int m, int n, int from, int to){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
           M[i][j] = (from*100 + rand()%((to-from)*100))/100.0;
        }
    }
}

void fillMatrZero(double**M, int m, int n) {
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            M[i][j] = 0;
        }
    }
}

int getMinRowPos (double** M, int m, int n, int row){
    int pos=0;
    double min = M[row][0];
    for (int j=0;j<n;j++){
        if(M[row][j]<min){
            min= M[row][j];
            pos=j;
        }
    }
    return pos;
}

double getMinElRow (double** M, int m, int n, int row){
    int pos= getMinRowPos ( M,  m, n, row);
    return M[row][pos];
}

int getMaxRowPos (double** M, int m, int n, int row){
    int pos=0;
    double max = M[row][0];
    for (int j=0;j<n;j++){
        if(M[row][j]>max){
            max= M[row][j];
            pos=j;
        }
    }
    return pos;
}

double getMaxElRow (double** M, int m, int n, int row){
    int pos= getMaxRowPos ( M,  m, n, row);
    return M[row][pos];
}

int getMinColPos (double** M, int m, int n, int col){
    int pos=0;
    double min = M[0][col];
    for (int i=0;i<m;i++){
        if(M[i][col]<min){
            min= M[i][col];
            pos=i;
        }
    }
    return pos;
}

double getMinElCol (double** M, int m, int n, int col){
    int pos= getMinColPos ( M,  m, n, col);
    return M[pos][col];
}


int getMaxColPos (double** M, int m, int n, int col){
    int pos=0;
    double max = M[0][col];
    for (int i=0;i<m;i++){
        if(M[i][col]>max){
            max= M[i][col];
            pos=i;
        }
    }
    return pos;
}

double getMaxElCol (double** M, int m, int n, int col){
    int pos= getMaxColPos ( M,  m, n, col);
    return M[pos][col];
}

double getDet(double**M,int m){
    for(int k=1; k<m ;k++){
        int p=k-1;
        double den= M[p][p];
        for(int i=k;i<m;i++){
            double num= M[i][p];
            for(int j=0;j<m;j++){
                M[i][j]=M[i][j]- (M[p][j]*num)/den;
            }
        }
    }
    double Det=1;
    for(int k=0;k<m;k++){
        Det*=M[k][k];
    }
    return Det;
}

double getSumRow (double** M, int m, int n, int row){
    if (row<0) throw "getSumRow() - error: row<0";
    if (row>=m) throw "getSumRow()- error: row have to be lower than m";
    double sum=0;
    for(int j=0;j<n;j++){
        sum+=M[row][j];
    }
    return sum;
}

double getProdRow (double** M, int m, int n, int row){
    if (row<0) throw "getProdRow() - error: row<0";
    if (row>=m) throw "getProdRow()- error: row have to be lower than m";
    double prod=1;
    for(int j=0;j<n;j++){
        prod*=M[row][j];
    }
    return prod;
}

double getSumCol (double** M, int m, int n, int col){
    if (col<0) throw "getSumCol() - error: col<0";
    if (col>=n) throw "getSumCol()- error: col have to be lower than n";
    double sum=0;
    for(int i=0;i<m;i++){
        sum+=M[i][col];
    }
    return sum;
}

double getProdCol (double** M, int m, int n, int col){
    if (col<0) throw "getProdCol() - error: col<0";
    if (col>=n) throw "getProdCol()- error: col have to be lower than n";
    double prod=1;
    for(int i=0;i<m;i++){
        prod*=M[i][col];
    }
    return prod;
}

double getAvgVal (double** M, int m, int n){
    double sum=0;
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            sum+=M[i][j];
        }
    }
    return sum/(m*n);
}

bool IsRowBalance(double**M, int m, int n, int row){
    double counter_plus=0;
    for (int j=0; j<n;j++){
        if(M[row][j]>0)counter_plus ++;
    }

    double counter_minus=0;
    for (int j=0; j<n;j++){
        if(M[row][j]<0)counter_minus ++;
    }

    return counter_plus == counter_minus;
}

bool IsRowEven(double**M, int m, int n, int row){
    for(int j=0;j<n;j++) {
        int x= M[row][j];
        if (x%2!=0) return false;
    }

    return true ;
}

bool IsColBalance(double**M, int m, int n, int col){
    double counter_plus=0;
    for (int i=0; i<m;i++){
        if(M[i][col]>0)counter_plus ++;
    }

    double counter_minus=0;
    for (int i=0; i<m;i++){
        if(M[i][col]<0)counter_minus ++;
    }

    return counter_plus == counter_minus;
}

bool IsColOdd(double**M, int m, int n, int col){
    for(int i=0;i<m;i++) {
        int x= M[i][col];
        if (x%2==0) return false;
    }

    return true ;
}

bool IsRowsSimilar(double**M, int m, int n, int row_1, int row_2){
    for (int j=0;j<n;j++){
        int x_1= M[row_1][j];
        bool found = false;
        for(int k=0;k<n;k++){
            int x_2= M[row_2][k];
            if(x_1==x_2){
                found = true;
                break;
            }
        }
        if (!found) return false;
    }

    for (int j=0;j<n;j++){
        int x_2= M[row_2][j];
        bool found = false;
        for(int k=0;k<n;k++){
            int x_1= M[row_1][k];
            if(x_1==x_2){
                found = true;
                break;
            }
        }
        if (!found) return false;
    }

}




//int main()
//{
//    srand(time(NULL));
//    int m, n;
//    cout << " m = "; cin >> m;
//    cout << " n = "; cin >> n;
//
//    double** M = createMatr(m, n);
//
//    fillMatrRnd(M, m, n, -5, 10);
//
//    if (M){
//        showMatr(M, m, n);
//    }
//
//    removeMatr(M, m);
//
//    return 0;
//}

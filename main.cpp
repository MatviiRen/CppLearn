#include "DynMatrLib.h"
#include "ArraysLib.h"
#include "matrlib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <math.h>

using namespace std;

void Matrix0(){
    Matr M1 = {0};

    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    FillMatrKBD(M1, m, n);

    ShowMatr(M1, m, n);


    FillMatrRND(M1, m, n);

    ShowMatr(M1, m, n);
}

void Matrix1(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M = {0};
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            M[i][j]=10*(i+1);
        }
    }

    ShowMatr(M, m, n);
}


void Matrix2(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M = {0};
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            M[i][j]=5*(j+1);
        }
    }

    ShowMatr(M, m, n);
}


void Matrix3(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double *A= new double [m];
    FillArrRnd(A,m);
    showArray(A,m);

    Matr M = {0};
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            M[i][j]=A[i];
        }
    }

    ShowMatr(M, m, n);
    delete [] A;
}

void Matrix4(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double *A= new double [n];
    FillArrRnd(A,n);
    showArray(A,n);

    Matr M = {0};
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            M[i][j]=A[j];
        }
    }

    ShowMatr(M, m, n);
    delete [] A;
}

void Matrix5(){
    int m, n;
    double d;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;
    cout << " d = "; cin >> d;

    double *A= new double [m];
    FillArrRnd(A,m);
    showArray(A,m);

    Matr M = {0};
    for(int i=0; i<m; i++) M[i][0]=A[i];
    ShowMatr(M, m, n);

    for(int i=0; i<m;i++){
        for(int j=1;j<n;j++){
            M[i][j]= M[i][j-1]+d;
        }
    }

    ShowMatr(M, m, n);
    delete [] A;
}

void Matrix7(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    int k;
    cout << " k = "; cin >> k;

    for(int j=0; j<n; j++){
        cout<<setw(6)<< M[k][j] << " ";
    }
    cout << endl;
}

void Matrix8(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    int k;
    cout << " k = "; cin >> k;

    for(int i=0; i<m; i++){
        cout<<setw(6)<< M[i][k] << " ";
    }
    cout << endl;
}

void Matrix9(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    for(int i=0; i<m; i+=2){
        ShowMatrRow(M, m, n, i);
    }
}


void Matrix10(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    for(int j=1; j<n; j+=2){
        ShowMatrCol(M, m, n, j);
    }
}

void Matrix11(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    for(int i=0;i<m;i++){
        if(i%2==0){
            for (int j=0; j<n; j++){
                cout<<setw(6)<< M[i][j] << " ";
            }
            cout << endl;
        }
        else {
            for (int j=n-1; j>=0; j--){
                cout<<setw(6)<< M[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void Matrix12(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M;
    FillMatrRND( M, m, n);
    ShowMatr(M, m, n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j%2==0){
                cout<<setw(6)<< M[i][j] << " ";
            }
            else{
                cout<<setw(6)<< M[m-i-1][j] << " ";
            }
        }
        cout<<endl;
    }
}

void Matrix13(){
    int m;
    cout << " m = "; cin >> m;

    Matr M;
    FillMatrRND( M, m, m);
    ShowMatr(M, m, m);

    for(int i=0;i<m;i++){
        for(int j=0;j<m-i;j++){
            cout<<setw(6)<< M[i][j] << " ";
        }

        for(int k=i+1;k<m;k++){
            cout<<setw(6)<< M[k][m-1-i] << " ";
        }
        cout<<endl;
    }
}

void Matrix17(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    int K;
    cout << " k = "; cin >> K;
    double sum= GetSumOfRow (M, m, n,K);
    double prod= GetProdOfRow ( M, m, n, K);

    cout<<"sum="<<sum<<endl;
    cout<<"prod="<<prod<<endl;
}

void Matrix18(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    int K;
    cout << " k = "; cin >> K;
    double sum= GetSumOfCol (M, m, n,K);
    double prod= GetProdOfCol (M, m,n,K);

    cout<<"sum="<<sum<<endl;
    cout<<"prod="<<prod<<endl;
}

void Matrix19(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    for(int i=0; i<m; i++){
        double  sum= GetSumOfRow (M, m, n,i);
        cout<<"sum"<<i<<" = "<<sum<<endl;
    }

}

void Matrix20(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    for(int j=0; j<n; j++){
        double prod= GetProdOfCol(M, m, n,j);
        cout<<"prod"<<j<<" = "<<prod<<endl;
    }

}

void Matrix21(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    for(int i=1; i<m; i+=2){
        double  avg= GetSumOfRow (M, m, n,i)/n;
        cout<<"avg"<<i<<" = "<<avg<<endl;
    }

}

void Matrix22(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    Matr M ;
    FillMatrRND(M, m, n);
    ShowMatr(M, m, n);

    for(int j=0; j<n; j+=2){
        double  avg= GetSumOfCol(M, m, n,j)/m;
        cout<<"avg"<<j<<" = "<<avg<<endl;
    }
}

void Matrix23(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    for(int i=0; i<m;i++){
        double RowMin= getMinElRow (M, m, n,i);
        cout<< "RowMin"<<i<<" = " << RowMin<<endl;
    }

    removeMatr(M,m);
}

void Matrix24(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    for(int j=0;j<n;j++){
        double ColMax= getMaxElCol (M, m, n,j);
        cout<< "ColMax"<<j<<" = " << ColMax<<endl;
    }

    removeMatr(M,m);
}


void calcDet(){

    int m;
    cout << " m = "; cin >> m;

    double** M= createMatr (m, m);
    fillMatrRnd (M,m,m,-5,12);
    showMatr(M,m,m);

    double Det= getDet(M,m);
    cout<< "Det ="<<Det<<endl;

    showMatr(M,m,m);
    removeMatr(M,m);

}

    void Matrix25(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    double max_sum= getSumRow (M,m,n,0);
    int row=0;
    for(int i=0;i<m;i++){
        double sum= getSumRow (M,m,n,i);
        cout<<"sum"<<i<<" ="<<sum<<endl;
        if(sum > max_sum){
            max_sum=sum;
            row=i;
        }
    }

    cout<<"max_sum ="<<max_sum<<endl;
    cout<<"row ="<<row<<endl;
    removeMatr(M,m);
}

void Matrix26(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    double min_prod= getProdCol (M,m,n,0);
    int col=0;
    for(int j=0;j<n;j++){
        double prod= getProdCol(M,m,n,j);
        cout<<"prod"<<j<<" ="<<prod<<endl;
        if(prod < min_prod){
            min_prod=prod;
            col=j;
        }
    }

    cout<<"min_prod="<<min_prod<<endl;
    cout<<"col ="<<col<<endl;
    removeMatr(M,m);
}

void Matrix27(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    double* A= new double [m];
    for(int i=0;i<m;i++){
        A[i]= getMinElRow(M,m,n,i);
    }
    showArray(A, m);

    double max= getMax(A,m);
    cout<<"max="<<max<<endl;

    delete [] A;
    removeMatr(M,m);
}

void Matrix29(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    for(int i=0;i<m;i++){
        double avg= getSumRow (M, m, n, i)/n;
        cout<<"avg"<<i<<" = "<<avg<<endl;
        int counter=0;
        for (int j=0; j<n; j++){
            if(M[i][j]< avg) counter++;
        }
        cout<<"counter="<<counter<<endl;
    }


    removeMatr(M,m);
}

void Matrix31(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    double avg= getAvgVal (M, m,n);
    cout<<"avg="<<avg<<endl;

    int I=0, J=0;
    double answer= M[I][J];
    double minDiff= fabs(answer-avg);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            double diff= fabs(M[i][j]-avg);
            if (diff< minDiff){
                minDiff=diff;
                answer= M[i][j];
                I=i;
                J=j;
            }
        }
    }

    cout<<"answer = "<<answer<<endl;
    cout<<"row"<<" ="<<I<<" col"<<" ="<<J<<endl;
    cout<<"diff = "<<minDiff<<endl;
    removeMatr(M,m);
}

void Matrix30(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    for(int j=0;j<n;j++){
        double avg= getSumCol (M, m, n, j)/m;
        cout<<"avg"<<j<<" = "<<avg<<endl;
        int counter=0;
        for (int i=0; i<m; i++){
            if(M[i][j]> avg) counter++;
        }
        cout<<"counter="<<counter<<endl;
    }


    removeMatr(M,m);
}

void Matrix32(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    int pos = -1;
    for(int i=0;i<m;i++){
        if(IsRowBalance(M, m, n, i)){
            pos=i;
            break;
        }
    }

    cout<<"pos="<<pos<<endl;
    removeMatr(M,m);
}

void Matrix34(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    int pos = -1;
    for(int i=0;i<m;i++){
        if(IsRowEven(M, m, n, i)) {
            pos=i;
        }
    }

    cout<<"pos="<<pos<<endl;
    removeMatr(M,m);
}

void Matrix33(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    int pos = -1;
    for(int j=0;j<n;j++){
        if(IsColBalance(M, m, n, j)){
            pos=j;
        }
    }

    cout<<"pos="<<pos<<endl;
    removeMatr(M,m);
}

void Matrix35(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    int pos = -1;
    for(int j=0;j<n;j++){
        if(IsColOdd(M, m, n, j)) {
            pos=j;
            break;
        }
    }

    cout<<"pos="<<pos<<endl;
    removeMatr(M,m);
}

void Matrix36(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;


    double** M= createMatr (m, n);
    fillMatrRnd (M,m,n,-5,12);
    showMatr(M,m,n);

    int counter = 0;
    for(int i=1;i<m;i++){
        if(IsRowsSimilar(M,  m, n, 0, i)) {
            cout<<"i="<<i<<endl;
            counter++;
        }
    }

    cout<<"counter="<<counter<<endl;
    removeMatr(M,m);
}



int main()	{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251. Нужно только будет изменить шрифт консоли на Lucida Console или Consolasbs
	srand(time(NULL));
	cout.setf(ios::boolalpha);
	try {
		while (true) Matrix36();
	} catch(const char* message) {
		cout<<message<<endl;
	}
	return 0;
}

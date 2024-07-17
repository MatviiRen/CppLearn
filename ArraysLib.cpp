#include "ArraysLib.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

void FillArrTransposition(int*A, int N){
	for(int i=0;i<N;i++){
		A[i]=0;
	}
	for(int i=1;i<=N;i++){
		int pos=rand()%N;
		while(A[pos]!=0){
			pos=rand()%N;
		}
		A[pos]=i;
	}
}

void FillArrRnd(double *A, int N, int from, int to) {
	for (int i=0;i<N;i++) {
		A[i]=(from*100 + rand()%((to-from)*100))/100.0;
	}	
}

void showArray(double *A, int N) {
	for (int i=0; i<N; i++){
        cout<< A[i]<<" ";
    }
    cout<<endl;	
}

void FillArrRnd(int *A, int N, int from, int to) {
	for (int i=0;i<N;i++) {
		A[i]=from + rand()%(to-from);
	}	
}

void showArray(int *A, int N) {
	for (int i=0; i<N; i++){
        cout<< A[i]<<" ";
    }
    cout<<endl;	
}

bool IsLocalMin (double *A, int N, int pos){
	if (pos==0) return A[0]<A[1];
	if (pos==N-1) return A[N-1]<A[N-2];
	return A[pos-1]>A[pos] && A[pos]<A[pos+1];
}

bool IsLocalMax (double *A, int N, int pos){
	if (pos==0) return A[0]>A[1];
	if (pos==N-1) return A[N-1]>A[N-2];
	return A[pos-1]<A[pos] && A[pos]>A[pos+1];
}

double Max(double A, double B){
	if(A>B) return A;
	return B;
}

void SortDoubleArrayUP (double *A, int N){
	for(int i=0; i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if (A[j]<A[i]){
				double L= A[i];
				A[i]=A[j];
				A[j]=L;
			}
		}
	}
}

int getNumberOfSeries (int*A, int N) {
	int counter = 1;
	for(int i=1;i<N;i++){
	  	if (A[i-1]!=A[i])counter++;
	}
	return counter;
}

int getPositionOfSeries (int*A, int N, int Ns) {
	if(Ns==0 && N>0) return 0;
	int counter = 0;
	for(int i=1;i<N;i++){
	  	if (A[i-1]!=A[i]){
	  		counter++;
	  		if(counter==Ns) return i;
		}
	}
	return -1;
}

int getSeriesLength (int*A, int N, int Ns) {
	int pos = getPositionOfSeries (A,  N, Ns);
	if(pos == -1) return 0;
	int length = 0;
	for(int i=pos;i<N;i++) {
		if(A[i]==A[pos]){
			length++;
		}
		else{
			break;
		}	
	}
	return length;
}

int getSeriesValue (int*A, int N, int Ns) {
	int pos = getPositionOfSeries (A,  N, Ns);
	if(pos==-1) throw " getSeriesValue() - Error: Wrong Series Number.Think about it";
	return A[pos];
}

void ExchangeSeries (int*A, int N, int Ns1, int Ns2) {
	int k=0;
	int *B= new int [N];
	int Q =  getNumberOfSeries (A,N);
	for(int i=0;i<Q;i++) {
		int Ns=i;
		if(i==Ns1) Ns=Ns2;
		if(i==Ns2) Ns=Ns1;
		int length= getSeriesLength (A,  N, Ns);
		int value= getSeriesValue (A, N,Ns);
		for(int j=0;j<length;j++) {
			B[k]= value;
			k++;
		}
	}
	for(int i=0;i<N;i++) A[i]=B[i];
	delete [] B;
}

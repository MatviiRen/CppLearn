const double pi=3.1415926;
void FillArrRnd(double *A, int N, int from=-5, int to=10);
void showArray(double *A, int N);
void FillArrRnd(int *A, int N, int from=-5, int to=10);
void showArray(int *A, int N);
bool IsLocalMin (double *A, int N, int pos);
bool IsLocalMax (double *A, int N, int pos);
void FillArrTransposition(int*A, int N);
double Max(double A, double B);
void SortDoubleArrayUP (double *A, int N);
int getNumberOfSeries (int*A, int N);
int getPositionOfSeries (int*A, int N, int Ns);
int getSeriesLength (int*A, int N, int Ns); 
int getSeriesValue (int*A, int  N, int Ns);
void ExchangeSeries (int*A, int N, int Ns1, int Ns2);


template <class T>
T getMax(T* A, int N){
	T max= A[0];
	for(int i=0;i<N;i++){
		if(A[i]>max){
			max= A[i];
		}
	}
	return max;
}

template <class T>
T getMin(T* A, int N){
	T min= A[0];
	for(int i=0;i<N;i++){
		if(A[i]<min){
			min= A[i];
		}
	}
	return min;
}

template <class T>
int getMaxPos(T* A, int N){
	T max= A[0];
	int pos = 0;
	for(int i=0;i<N;i++){
		if(A[i]>max){
			max= A[i];
			pos=i;
		}
	}
	return pos;
}

template <class T>
int getMinPos(T* A, int N){
	T min= A[0];
	int pos= 0;
	for(int i=0;i<N;i++){
		if(A[i]<min){
			min= A[i];
			pos= i;
		}
	}
	return pos;
}

template <class T>
void Swap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}

template <class T>
void Reverse(T *A, int N,int from = 0, int to = -1){
	if(from<0) throw"Reverse() - ERROR: You are wrong. From can`t be less than zero";
	int i = from;
	if(to==-1) to=N-1;
	if(to>=N) throw"Reverse() - ERROR: You are wrong. To can`t be more than amount of numbers in Array or equal";
	int j =to;
	while(i<j){
		Swap(A[i],A[j]);
		i++;
		j--;
	}
}

template <class T>
void ShiftRight(T *A, int N){
	for(int i= N-1;i>0;i--){
		A[i] = A[i-1];	
	}
	A[0]=0;
}

template <class T>
void ShiftLeft(T *A, int N){
	for(int i= 1;i<N;i++){
		A[i-1] = A[i];	
	}
	A[N-1]=0;
}

template <class T>
void ShiftRight(T *A, int N, int K){
	for(int i=0;i<K;i++){
		ShiftRight(A, N);	
	}
}

template <class T>
void ShiftLeft(T *A, int N, int K){
	for(int i=0;i<K;i++){
		ShiftLeft(A,  N);	
	}
}

template <class T>
void ShiftRightCircle(T *A, int N){
	T x = A[N-1];
	ShiftRight(A, N);
	A[0]= x;
}

template <class T>
void ShiftLeftCircle(T *A, int N){
	T x = A[0];
	ShiftLeft(A, N);	
	A[N-1]= x;
}

template <class T>
void ShiftRightCircle(T *A, int N, int K){
	for(int i = 0;i<K;i++){
		ShiftRightCircle(A, N);
	}
}

template <class T>
void ShiftLeftCircle(T *A, int N, int K){
	for(int i = 0;i<K;i++){
		ShiftLeftCircle(A, N);
	}
}

template <class T>
void RemoveByPosition(T*& A, int& N, int pos){
	T* B = new T[N-1];
	int j = 0;
	for (int i=0; i<N; i++){
		if (i != pos){
			B[j++] = A[i];
		}
	}
	delete[] A;
	A = B;
	N--;
}

template <class T>
void InsertByPosition(T*& A, int& N, int pos, T intru){
	T* B = new T[N+1];
	for (int i=0; i<N; i++){
		if (i < pos){
			B[i] = A[i];
		}
		else{
			B[i+1]=A[i];
		}
	}
	delete[] A;
	A = B;
	N++;
	A[pos]= intru;
}

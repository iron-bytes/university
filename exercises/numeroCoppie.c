/*
** Creare un algoritmo che ricevuto in input un numero naturale 'n'
** restituisca il numero di coppie (i,j) tali che 1 <= i <= j <= n 
*/

#include <stdio.h>

#define N 10

int algoritmo1(int n){
	int sum = 0;	//	1				
	int i,j;		//	1
	
	for(i=1 ; i<=n ; ++i){	// n+1
		for(j=1 ; j<=n ; ++j){	//	n(n+1)
			if(i <= j){ // n*n
				++sum; // <= n*n
			}
		}
	}
	return sum; // 1
}

int algoritmo2(int n){
	int sum = 0;
	int i,j;
	for(i = 1 ; i<=n ; ++i){
		for(j = i ; j<=n ; ++j){
			++sum;
		}
	}
	return sum;
}

int algoritmo3(int n){
	int sum = 0;
	int i;
	for(i=1 ; i<=n ; ++i){
		sum += n-i+1;
	}
	return sum;
}

int algoritmo4(int n){
	return (n*(n+1))/2;
}

int main(void){
	int result1, result2, result3, result4;
	result1 = algoritmo1(N);
	result2 = algoritmo2(N);
	result3 = algoritmo3(N);
	result4 = algoritmo4(N);
		
	printf("%d\n%d\n%d\n%d\n", result1, result2, result3, result4);
	
	return 0;
}

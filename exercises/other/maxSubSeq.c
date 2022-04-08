/*
	Data una sequenza di numeri, trovare il valore massimo di SUM(sottosequenza)
	tra tutte le sottosequenze.
	SUM(sottosequenza) = { for(i=0 ; i<sottosequenza.length ; i++){ sum += sottosequenza[i]; } return sum; } 
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 10

int algo1(int* v);
int algo2(int* v);
int algo3(int* v);
void stampa(int* v);
void load(int* v);

int main(void){
	int v[MAX];
	srand(time(NULL));
	load(v);
	stampa(v);
	printf("\n\n%d\n%d\n%d\n",algo1(v),algo2(v),algo3(v));
	system("pause");
	return 0;
}

void load(int* v){
		int i;
		for(i=0;i<MAX;i++){
			v[i] = rand()%10;
	}
}

void stampa(int* v){
	int i;
	for(i=0;i<MAX;i++){
		printf("%d|",v[i]);
	}
}

int algo1(int* v){
	int n = MAX;
	int maxsum = 0, sum=0;
	int i,j,z;
	for(i=0;i<MAX;i++){
		for(j=i;j<n;j++){
			sum=0;
			for(z=i;z<=j;z++){
				sum+=v[z];
			}
			if(sum>maxsum){
				maxsum = sum;
			}
		}
	}
	return maxsum;
}

int algo2(int* v){
	int n = MAX;
	int maxsum = 0, sum = 0;
	int i,j;
	for(i=0;i<n;i++){
		sum=0;
		for(j=0;j<n;j++){
			sum=sum+v[j];
			if(sum>maxsum){
				maxsum = sum;
			}
		}
	}
	return maxsum;
}

int algo3(int* v){ // Complessità: Theta(n)
	int n = MAX;
	int maxsum = 0, sum=0;
	int j;
	for(j=0;j<n;j++){
		sum=sum+v[j];
		if(sum<0){
			sum=0;
		}
		else if(sum>maxsum){
			maxsum = sum;
		}
	}
	return maxsum;
}



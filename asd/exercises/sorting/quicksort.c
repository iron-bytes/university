#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

void print(int*);
void load(int*);
void quicksort(int*, int , int);
int partition(int*, int, int);

int main(){
  int v[MAX];
  load(v);
  printf("\nArray given in input:\n");
  print(v);
  quicksort( v , 0 , MAX );
  printf("Result:\n");
  print(v);
}

void quicksort(int* v, int p , int r){
    int q;
    if(p < r){
        q = partition(v, p , r);
        quicksort(v , p , q);
        quicksort(v , q+1 , r);
    }
}

int partition(int* v, int p, int r){
    int x = v[p];
    int i = p-1;
    int j = r+1;
    int temp;
    do{

        do{
            j--;
        }while(v[j] > x);

        do{
            i++;
        }while(v[i] < x);

        if(i<j){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        
    }while(i<j);
    return j;
}


void print(int* v){
  int i;
  for(i=0;i<MAX;i++){
    printf("%d|",v[i]);
  }
  printf("\n\n");
}

void load(int* v){
  int i;
  srand(time(NULL));
  for(i=0;i<MAX;i++){
    v[i] = rand()%10;
  }
}

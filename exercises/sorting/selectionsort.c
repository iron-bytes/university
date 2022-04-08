#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

void load(int* v){
  int i;
  srand(time(NULL));
  for(i=0;i<MAX;i++){
    v[i] = rand()%10;
  }
}

void selectionSort(int* v){
  int i,j,position,tmp;
  for(i = 0; i < MAX-1; i++){
    position=i;
    for(j = i + 1; j < MAX; j++){
      if(v[j] < v[position]) position=j;
    }
    if(position != i){
      tmp=v[i];
      v[i]=v[position];
      v[position]=tmp;
    }
  }
}

void print(int* v){
  int i;
  for(i=0;i<MAX;i++){
    printf("%d|",v[i]);
  }
  printf("\n\n");
}

int main(){
  int v[MAX];
  load(v);
  print(v);
  selectionSort(v);
  print(v);
}
